#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

struct Sticker {
    int x, y, z;
    int nx, ny, nz;
};

Sticker stickers[24];


int permutation[6][24];

void setSticker(
    int index,
    int x, int y, int z,
    int nx, int ny, int nz
) {
    stickers[index] = {x, y, z, nx, ny, nz};
}

void rotatePoint(
    int &x, int &y, int &z,
    int axis
) {
    int oldX = x;
    int oldY = y;
    int oldZ = z;

    if (axis == 0) {
       
        x = oldX;
        y = -oldZ;
        z = oldY;
    }
    else if (axis == 1) {
       
        x = oldZ;
        y = oldY;
        z = -oldX;
    }
    else {
    
        x = -oldY;
        y = oldX;
        z = oldZ;
    }
}

bool sameSticker(const Sticker &a, const Sticker &b) {
    return a.x == b.x &&
           a.y == b.y &&
           a.z == b.z &&
           a.nx == b.nx &&
           a.ny == b.ny &&
           a.nz == b.nz;
}

void initializeStickers() {
  
    setSticker(0, -1, 1, -1, 0, 1, 0);
    setSticker(1,  1, 1, -1, 0, 1, 0);
    setSticker(2, -1, 1,  1, 0, 1, 0);
    setSticker(3,  1, 1,  1, 0, 1, 0);

    setSticker(4, -1,  1, 1, 0, 0, 1);
    setSticker(5,  1,  1, 1, 0, 0, 1);
    setSticker(6, -1, -1, 1, 0, 0, 1);
    setSticker(7,  1, -1, 1, 0, 0, 1);

   
    setSticker(8,  -1, -1,  1, 0, -1, 0);
    setSticker(9,   1, -1,  1, 0, -1, 0);
    setSticker(10, -1, -1, -1, 0, -1, 0);
    setSticker(11,  1, -1, -1, 0, -1, 0);


    setSticker(12, -1, -1, -1, 0, 0, -1);
    setSticker(13,  1, -1, -1, 0, 0, -1);
    setSticker(14, -1,  1, -1, 0, 0, -1);
    setSticker(15,  1,  1, -1, 0, 0, -1);

    setSticker(16, -1,  1, -1, -1, 0, 0);
    setSticker(17, -1,  1,  1, -1, 0, 0);
    setSticker(18, -1, -1, -1, -1, 0, 0);
    setSticker(19, -1, -1,  1, -1, 0, 0);

    setSticker(20, 1,  1,  1, 1, 0, 0);
    setSticker(21, 1,  1, -1, 1, 0, 0);
    setSticker(22, 1, -1,  1, 1, 0, 0);
    setSticker(23, 1, -1, -1, 1, 0, 0);
}

void createMovePermutations() {
   

    int faceAxis[6] = {
        0, 0, 1, 1, 2, 2
    };

    int faceLayer[6] = {
        -1, 1, -1, 1, -1, 1
    };

    for (int face = 0; face < 6; face++) {
        int axis = faceAxis[face];
        int layer = faceLayer[face];

        for (int i = 0; i < 24; i++) {
            Sticker changed = stickers[i];

            int coordinate;

            if (axis == 0) {
                coordinate = changed.x;
            }
            else if (axis == 1) {
                coordinate = changed.y;
            }
            else {
                coordinate = changed.z;
            }

            if (coordinate == layer) {
                rotatePoint(
                    changed.x,
                    changed.y,
                    changed.z,
                    axis
                );

                rotatePoint(
                    changed.nx,
                    changed.ny,
                    changed.nz,
                    axis
                );
            }

            for (int j = 0; j < 24; j++) {
                if (sameSticker(changed, stickers[j])) {
                    permutation[face][i] = j;
                    break;
                }
            }
        }
    }
}

array<char, 24> applyQuarterTurn(
    const array<char, 24> &cube,
    int face
) {
    array<char, 24> result;

    for (int i = 0; i < 24; i++) {
        int newPosition = permutation[face][i];
        result[newPosition] = cube[i];
    }

    return result;
}

array<char, 24> applyMove(
    array<char, 24> cube,
    int face,
    int numberOfTurns
) {
    for (int turn = 0; turn < numberOfTurns; turn++) {
        cube = applyQuarterTurn(cube, face);
    }

    return cube;
}

bool isSolved(const array<char, 24> &cube) {
    for (int face = 0; face < 6; face++) {
        int start = face * 4;

        for (int i = start + 1; i < start + 4; i++) {
            if (cube[i] != cube[start]) {
                return false;
            }
        }
    }

    return true;
}

bool canSolve(
    const array<char, 24> &cube,
    int currentDepth,
    int maximumDepth,
    int previousFace
) {
    if (isSolved(cube)) {
        return true;
    }

    if (currentDepth == maximumDepth) {
        return false;
    }

    for (int face = 0; face < 6; face++) {
        
        if (face == previousFace) {
            continue;
        }

       
        for (int turns = 1; turns <= 3; turns++) {
            array<char, 24> nextCube =
                applyMove(cube, face, turns);

            if (canSolve(
                    nextCube,
                    currentDepth + 1,
                    maximumDepth,
                    face
                )) {
                return true;
            }
        }
    }

    return false;
}

bool solvableWithinFourMoves(
    const array<char, 24> &cube
) {
    for (int depth = 0; depth <= 4; depth++) {
        if (canSolve(cube, 0, depth, -1)) {
            return true;
        }
    }

    return false;
}

int main() {
    array<char, 24> cube;

    for (int i = 0; i < 24; i++) {
        cin >> cube[i];
    }

    initializeStickers();
    createMovePermutations();

   
    int corners[8][3] = {
        {0, 14, 16},   // 1, 15, 17
        {1, 15, 21},   // 2, 16, 22
        {2, 4, 17},    // 3, 5, 18
        {3, 5, 20},    // 4, 6, 21
        {8, 6, 19},    // 9, 7, 20
        {9, 7, 22},    // 10, 8, 23
        {10, 12, 18},  // 11, 13, 19
        {11, 13, 23}   // 12, 14, 24
    };

    for (int corner = 0; corner < 8; corner++) {
        int first = corners[corner][0];
        int second = corners[corner][1];
        int third = corners[corner][2];

        char firstColour = cube[first];
        char secondColour = cube[second];
        char thirdColour = cube[third];

        
        array<char, 24> firstRotation = cube;

        firstRotation[first] = secondColour;
        firstRotation[second] = thirdColour;
        firstRotation[third] = firstColour;

        if (solvableWithinFourMoves(firstRotation)) {
            char colours[3] = {
                firstColour,
                secondColour,
                thirdColour
            };

            sort(colours, colours + 3);

            cout << colours[0]
                 << colours[1]
                 << colours[2];

            return 0;
        }

        
        array<char, 24> secondRotation = cube;

        secondRotation[first] = thirdColour;
        secondRotation[second] = firstColour;
        secondRotation[third] = secondColour;

        if (solvableWithinFourMoves(secondRotation)) {
            char colours[3] = {
                firstColour,
                secondColour,
                thirdColour
            };

            sort(colours, colours + 3);

            cout << colours[0]
                 << colours[1]
                 << colours[2];

            return 0;
        }
    }

    return 0;
}