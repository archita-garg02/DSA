#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;

    int grid[25][25];
    char brickType[630];

    int brickCount = 0;
    int source = -1;
    int destination = -1;

    for (int row = 0; row < n; row++) {
        string input;
        cin >> input;

        int column = 0;
        int index = 0;

        while (index < input.length()) {
            int length = 0;

        
            while (index < input.length() &&
                   input[index] >= '0' &&
                   input[index] <= '9') {

                length = length * 10 + (input[index] - '0');
                index++;
            }

            char type = input[index];
            index++;

            int currentBrick = brickCount;
            brickType[currentBrick] = type;
            brickCount++;

            if (type == 'S') {
                source = currentBrick;
            }

            if (type == 'D') {
                destination = currentBrick;
            }

          
            for (int j = 0; j < length; j++) {
                grid[row][column] = currentBrick;
                column++;
            }
        }
    }

    
    vector<int> graph[630];

    int directionRow[] = {-1, 1, 0, 0};
    int directionColumn[] = {0, 0, -1, 1};

    for (int row = 0; row < n; row++) {
        for (int column = 0; column < n; column++) {

            int currentBrick = grid[row][column];

            for (int direction = 0; direction < 4; direction++) {
                int newRow = row + directionRow[direction];
                int newColumn = column + directionColumn[direction];

                if (newRow >= 0 && newRow < n &&
                    newColumn >= 0 && newColumn < n) {

                    int adjacentBrick = grid[newRow][newColumn];

                    if (currentBrick != adjacentBrick) {
                        graph[currentBrick].push_back(adjacentBrick);
                    }
                }
            }
        }
    }

   
    vector<int> distance(brickCount, INT_MAX);
    deque<int> dq;

    distance[source] = 0;
    dq.push_front(source);

    while (!dq.empty()) {
        int current = dq.front();
        dq.pop_front();

        for (int next : graph[current]) {
           
            if (brickType[next] == 'R') {
                continue;
            }

            int cost;

            if (brickType[next] == 'G') {
                cost = 1;
            } else {
           
                cost = 0;
            }

            if (distance[current] + cost < distance[next]) {
                distance[next] = distance[current] + cost;

                if (cost == 0) {
                    dq.push_front(next);
                } else {
                    dq.push_back(next);
                }
            }
        }
    }

    cout << distance[destination];

    return 0;
}