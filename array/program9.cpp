#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

struct Edge {
    int to;
    int reverseIndex;
    int capacity;
    int cost;
};

class MinCostMaxFlow {
private:
    int vertices;
    vector<vector<Edge>> graph;

public:
    MinCostMaxFlow(int n) {
        vertices = n;
        graph.resize(n);
    }

    void addEdge(int from, int to, int capacity, int cost) {
        Edge forwardEdge;
        forwardEdge.to = to;
        forwardEdge.reverseIndex = graph[to].size();
        forwardEdge.capacity = capacity;
        forwardEdge.cost = cost;

        Edge reverseEdge;
        reverseEdge.to = from;
        reverseEdge.reverseIndex = graph[from].size();
        reverseEdge.capacity = 0;
        reverseEdge.cost = -cost;

        graph[from].push_back(forwardEdge);
        graph[to].push_back(reverseEdge);
    }

    pair<int, int> findMinCostFlow(int source, int sink, int requiredFlow) {
        int totalFlow = 0;
        int totalCost = 0;

        while (totalFlow < requiredFlow) {
            vector<int> distance(vertices, INT_MAX);
            vector<int> parentVertex(vertices, -1);
            vector<int> parentEdge(vertices, -1);
            vector<bool> inQueue(vertices, false);

            queue<int> q;

            distance[source] = 0;
            q.push(source);
            inQueue[source] = true;

            
            while (!q.empty()) {
                int current = q.front();
                q.pop();
                inQueue[current] = false;

                for (int i = 0; i < graph[current].size(); i++) {
                    Edge &edge = graph[current][i];

                    if (edge.capacity > 0 &&
                        distance[current] != INT_MAX &&
                        distance[current] + edge.cost < distance[edge.to]) {

                        distance[edge.to] =
                            distance[current] + edge.cost;

                        parentVertex[edge.to] = current;
                        parentEdge[edge.to] = i;

                        if (!inQueue[edge.to]) {
                            q.push(edge.to);
                            inQueue[edge.to] = true;
                        }
                    }
                }
            }

         
            if (parentVertex[sink] == -1) {
                break;
            }

            int pathFlow = requiredFlow - totalFlow;

            int current = sink;

            while (current != source) {
                int previous = parentVertex[current];
                int edgeIndex = parentEdge[current];

                pathFlow = min(
                    pathFlow,
                    graph[previous][edgeIndex].capacity
                );

                current = previous;
            }

            current = sink;

            while (current != source) {
                int previous = parentVertex[current];
                int edgeIndex = parentEdge[current];

                Edge &edge = graph[previous][edgeIndex];

                edge.capacity -= pathFlow;

                graph[current][edge.reverseIndex].capacity += pathFlow;

                current = previous;
            }

            totalFlow += pathFlow;
            totalCost += pathFlow * distance[sink];
        }

        return {totalFlow, totalCost};
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> roads(m);

    int maximumTown = n;

    for (int i = 0; i < m; i++) {
        cin >> roads[i].first >> roads[i].second;

        maximumTown = max(maximumTown, roads[i].first);
        maximumTown = max(maximumTown, roads[i].second);
    }

    int firstScout, secondScout;
    cin >> firstScout >> secondScout;

    int outpost;
    cin >> outpost;

    maximumTown = max(maximumTown, firstScout);
    maximumTown = max(maximumTown, secondScout);
    maximumTown = max(maximumTown, outpost);

    

    int superSource = 2 * maximumTown;
    int superSink = superSource + 1;
    int totalVertices = superSink + 1;

    MinCostMaxFlow network(totalVertices);


    for (int town = 1; town <= maximumTown; town++) {
        int inNode = 2 * (town - 1);
        int outNode = inNode + 1;

        if (town == outpost) {
            
            network.addEdge(inNode, outNode, 2, 0);
        } else {
            network.addEdge(inNode, outNode, 1, 1);
        }
    }


    for (int i = 0; i < m; i++) {
        int firstTown = roads[i].first;
        int secondTown = roads[i].second;

        int firstIn = 2 * (firstTown - 1);
        int firstOut = firstIn + 1;

        int secondIn = 2 * (secondTown - 1);
        int secondOut = secondIn + 1;

       
        if (firstTown != outpost) {
            network.addEdge(firstOut, secondIn, 1, 0);
        }

        if (secondTown != outpost) {
            network.addEdge(secondOut, firstIn, 1, 0);
        }
    }

    int firstScoutIn = 2 * (firstScout - 1);
    int secondScoutIn = 2 * (secondScout - 1);

    int outpostOut = 2 * (outpost - 1) + 1;

    network.addEdge(superSource, firstScoutIn, 1, 0);
    network.addEdge(superSource, secondScoutIn, 1, 0);


    network.addEdge(outpostOut, superSink, 2, 0);

    pair<int, int> answer =
        network.findMinCostFlow(superSource, superSink, 2);

    if (answer.first < 2) {
        cout << "Impossible";
    } else {
        cout << answer.second;
    }

    return 0;
}