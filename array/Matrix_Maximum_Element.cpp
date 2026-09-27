// 4.) Matrix Maximum Element – Position and Minimum Swaps
// Problem Statement:
// You are given a matrix along with its number of rows and columns. Your task is to determine:
// The position (row, column) of the maximum element in the matrix.
// The minimum number of swaps required to move this maximum element to the center of the matrix, assuming each swap moves the element exactly one step in any direction (up, down, left, or right).
// The center of the matrix is defined as:
// (center_row = rows // 2,  center_col = cols // 2)
// Each move that shifts the element by one position counts as one swap.
// Output Format
// minimum_swaps  (<row>,<col>)
// Where <row>,<col> is the original position of the maximum element.
// Example
// Input:
// Rows = 3, Cols = 3Matrix:
// 10 5 7
// 11 6 1
// 4  3 2
// Explanation:
// Maximum element = 11
// Position = (1,0)
// Center position = (1,1)
// Minimum swaps required = 1
// Output:
// 1 (1,0)

#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main()
{
    int row,col;
    cin>>row;
    cin>>col;

    vector<vector<int>>arr(row,vector<int>(col));

    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cin>>arr[i][j];
        }
    }

    int maximum=INT_MIN;
    int ansrow=-1;
    int anscol=-1;

    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(maximum<arr[i][j])
            {
                maximum = arr[i][j]; 
                ansrow=i;
                anscol=j;
            }
            
        }
    }

    int midrow=row/2;
    int midcol=col/2;

    int swaps=abs(ansrow-midrow)+abs(anscol-midcol);

    cout<<swaps<<"("<<ansrow<<","<<anscol<<")";

    return 0;

   
}
