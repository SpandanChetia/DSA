#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> rotateMatrix(vector<vector<int>>&matrix){
    int rows = matrix.size();
    int cols = matrix[0].size();

    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            matrix[j][i] = matrix[i][j];
        }
    }
    for(int i=0; i<rows; i++){
        reverse(matrix[i].begin(), matrix[i].end());
    }
    return matrix;
}
vector<vector<int>> rotateRectangularMatrix(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<vector<int>> rotated(cols, vector<int>(rows));

    for (int i=0; i<rows; i++){
        for (int j=0; j<cols; j++){
            rotated[j][rows-1-i] = matrix[i][j];
        }
    }

    return rotated;
}

int main(){
    vector<vector<int>> matrix = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9},
    {10, 11, 12}
    };

    vector<vector<int>>ans = rotateRectangularMatrix(matrix);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[0].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}
