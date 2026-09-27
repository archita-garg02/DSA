#include <iostream>
#include <string>
using namespace std;

const int MAX_SIZE = 25;

int n, m, keyLength;

char grid[MAX_SIZE][MAX_SIZE];

bool allowed[MAX_SIZE][MAX_SIZE][MAX_SIZE];
bool canReach[MAX_SIZE][MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];

int rowDirection[] = {-1, 1, 0, 0};
int columnDirection[] = {0, 0, -1, 1};

string currentKey;
string answer;

int validPathCount = 0;

bool isValidCell(int row, int column) {
    return row >= 0 && row < n &&
           column >= 0 && column < m;
}

void findKey(int row, int column, int time) {
   
    if (validPathCount >= 2) {
        return;
    }

    visited[row][column] = true;
    currentKey.push_back(grid[row][column]);

    if (time == keyLength - 1) {
        validPathCount++;

        if (validPathCount == 1) {
            answer = currentKey;
        }

        currentKey.pop_back();
        visited[row][column] = false;
        return;
    }

    for (int direction = 0; direction < 4; direction++) {
        int nextRow = row + rowDirection[direction];
        int nextColumn = column + columnDirection[direction];

        if (!isValidCell(nextRow, nextColumn)) {
            continue;
        }

        if (visited[nextRow][nextColumn]) {
            continue;
        }

    
        if (!allowed[time + 1][nextRow][nextColumn]) {
            continue;
        }

        if (!canReach[time + 1][nextRow][nextColumn]) {
            continue;
        }

        findKey(nextRow, nextColumn, time + 1);

        if (validPathCount >= 2) {
            break;
        }
    }

    currentKey.pop_back();
    visited[row][column] = false;
}

int main() {
    cin >> n >> m;

    for (int row = 0; row < n; row++) {
        for (int column = 0; column < m; column++) {
            cin >> grid[row][column];
        }
    }

    cin >> keyLength;


    for (int time = 0; time < keyLength; time++) {
        for (int row = 0; row < n; row++) {
            for (int column = 0; column < m; column++) {
                allowed[time][row][column] = true;
            }
        }
    }

    int clueCount;
    cin >> clueCount;

    for (int clue = 0; clue < clueCount; clue++) {
        int time;
        int x1, y1, x2, y2;

        cin >> time;
        cin >> x1 >> y1 >> x2 >> y2;

   
        time--;
        x1--;
        y1--;
        x2--;
        y2--;

  
        for (int row = x1; row <= x2; row++) {
            for (int column = y1; column <= y2; column++) {
                allowed[time][row][column] = false;
            }
        }
    }


    for (int time = 0; time < keyLength; time++) {
        bool cellAvailable = false;

        for (int row = 0; row < n; row++) {
            for (int column = 0; column < m; column++) {
                if (allowed[time][row][column]) {
                    cellAvailable = true;
                }
            }
        }

        if (!cellAvailable) {
            cout << "Not enough clues";
            return 0;
        }
    }

   

    int lastTime = keyLength - 1;

    for (int row = 0; row < n; row++) {
        for (int column = 0; column < m; column++) {
            canReach[lastTime][row][column] =
                allowed[lastTime][row][column];
        }
    }

    for (int time = keyLength - 2; time >= 0; time--) {
        for (int row = 0; row < n; row++) {
            for (int column = 0; column < m; column++) {
                canReach[time][row][column] = false;

                if (!allowed[time][row][column]) {
                    continue;
                }

                for (int direction = 0;
                     direction < 4;
                     direction++) {

                    int nextRow =
                        row + rowDirection[direction];

                    int nextColumn =
                        column + columnDirection[direction];

                    if (isValidCell(nextRow, nextColumn) &&
                        canReach[time + 1][nextRow][nextColumn]) {

                        canReach[time][row][column] = true;
                        break;
                    }
                }
            }
        }
    }

    for (int row = 0; row < n; row++) {
        for (int column = 0; column < m; column++) {
            if (allowed[0][row][column] &&
                canReach[0][row][column]) {

                findKey(row, column, 0);
            }

            if (validPathCount >= 2) {
                break;
            }
        }

        if (validPathCount >= 2) {
            break;
        }
    }

    if (validPathCount == 1) {
        cout << answer;
    } else {
        cout << "Not enough clues";
    }

    return 0;
}