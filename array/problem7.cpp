#include <iostream>
#include <string>
using namespace std;

struct Command {
    int existingCube;
    int newCube;
    string direction;
};

int findCube(int x[], int y[], bool active[],
             int totalCubes, int targetX, int targetY) {
    
    for (int cube = 1; cube <= totalCubes; cube++) {
        if (active[cube] &&
            x[cube] == targetX &&
            y[cube] == targetY) {
            
            return cube;
        }
    }

    return -1;
}

int main() {
    int n;
    cin >> n;

    Command commands[55];

    for (int i = 0; i < n; i++) {
        cin >> commands[i].existingCube
            >> commands[i].newCube
            >> commands[i].direction;
    }

    int targetCube;
    cin >> targetCube;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {

            bool shouldSwap = false;

            if (commands[j].existingCube >
                commands[j + 1].existingCube) {
                
                shouldSwap = true;
            }
            else if (commands[j].existingCube ==
                     commands[j + 1].existingCube &&
                     commands[j].newCube >
                     commands[j + 1].newCube) {
                
                shouldSwap = true;
            }

            if (shouldSwap) {
                Command temp = commands[j];
                commands[j] = commands[j + 1];
                commands[j + 1] = temp;
            }
        }
    }


    int x[55] = {0};
    int y[55] = {0};
    bool active[55] = {false};

    int totalCubes = 50;


    int firstCube = commands[0].existingCube;

    x[firstCube] = 0;
    y[firstCube] = 0;
    active[firstCube] = true;


    for (int i = 0; i < n; i++) {
        int existingCube = commands[i].existingCube;
        int newCube = commands[i].newCube;

        int newX = x[existingCube];
        int newY = y[existingCube];

        if (commands[i].direction == "top") {
            newY++;
        }
        else if (commands[i].direction == "down") {
            newY--;
        }
        else if (commands[i].direction == "left") {
            newX--;
        }
        else if (commands[i].direction == "right") {
            newX++;
        }

        int oldCube = findCube(
            x, y, active, totalCubes, newX, newY
        );

        if (oldCube != -1) {
            active[oldCube] = false;
        }

        x[newCube] = newX;
        y[newCube] = newY;
        active[newCube] = true;
    }

    int targetX = x[targetCube];
    int targetY = y[targetCube];

    int topCube = findCube(
        x, y, active, totalCubes,
        targetX, targetY + 1
    );

    int downCube = findCube(
        x, y, active, totalCubes,
        targetX, targetY - 1
    );

    int leftCube = findCube(
        x, y, active, totalCubes,
        targetX - 1, targetY
    );

    int rightCube = findCube(
        x, y, active, totalCubes,
        targetX + 1, targetY
    );

    cout << topCube << " "
         << downCube << " "
         << leftCube << " "
         << rightCube;

    return 0;
}