#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct Query {
    int firstStation;
    string operation;
    int secondStation;
};

unordered_map<string, int> stationId;
vector<unordered_set<int>> graph;
vector<unordered_set<int>> restrictions;

int getStationId(const string& station) {
    if (stationId.find(station) != stationId.end()) {
        return stationId[station];
    }

    int newId = stationId.size();
    stationId[station] = newId;

    graph.push_back(unordered_set<int>());
    restrictions.push_back(unordered_set<int>());

    return newId;
}

bool pathExists(int source, int destination) {
  
    if (restrictions[source].count(destination)) {
        return false;
    }

    vector<bool> visited(graph.size(), false);
    queue<int> q;

    visited[source] = true;
    q.push(source);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        if (current == destination) {
            return true;
        }

        for (int neighbour : graph[current]) {
            
            if (restrictions[source].count(neighbour)) {
                continue;
            }

            if (!visited[neighbour]) {
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }

    return false;
}

int main() {
    int n;
    cin >> n;
    cin.ignore();

 
    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);

        stringstream ss(line);
        string sourceName;
        ss >> sourceName;

        int source = getStationId(sourceName);

        string connectedStationName;

        while (ss >> connectedStationName) {
            int connectedStation =
                getStationId(connectedStationName);

       
            graph[source].insert(connectedStation);
            graph[connectedStation].insert(source);
        }
    }

    int q;
    cin >> q;

    vector<Query> queries;

    for (int i = 0; i < q; i++) {
        string firstName;
        string operation;
        string secondName;

        cin >> firstName >> operation >> secondName;

        int firstStation = getStationId(firstName);
        int secondStation = getStationId(secondName);

        Query currentQuery;
        currentQuery.firstStation = firstStation;
        currentQuery.operation = operation;
        currentQuery.secondStation = secondStation;

        queries.push_back(currentQuery);
    }

    int r;
    cin >> r;
    cin.ignore();


    for (int i = 0; i < r; i++) {
        string line;
        getline(cin, line);

        stringstream ss(line);

        string sourceName;
        ss >> sourceName;

        int source = getStationId(sourceName);

        string restrictedName;

        while (ss >> restrictedName) {
            int restrictedStation =
                getStationId(restrictedName);

            restrictions[source].insert(restrictedStation);
        }
    }

    for (const Query& query : queries) {
        int first = query.firstStation;
        int second = query.secondStation;

        if (query.operation == "connects") {
            graph[first].insert(second);
            graph[second].insert(first);
        }
        else if (query.operation == "disconnects") {
            graph[first].erase(second);
            graph[second].erase(first);
        }
        else if (query.operation == "to") {
            if (pathExists(first, second)) {
                cout << "yes\n";
            } else {
                cout << "no\n";
            }
        }
    }

    return 0;
}