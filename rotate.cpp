// 给定一个n阶二维矩阵表示一个图像。将图像顺时针旋转90度。leetcode 48题。
#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size() - 1, temp, pre_i, pre_j;
    for(int i = 0; i <= (n-1) / 2; i++) {
        for(int j = 0; j <= n / 2; j++) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[n - j][i];
            matrix[n - j][i] = matrix[n - i][n - j];
            matrix[n - i][n - j] = matrix[j][n - i];
            matrix[j][n - i] = temp;
        }
    }
    return;
}

void print(vector<vector<int>>& matrix) {
    for(auto i:matrix) {
        for(auto j:i) {
            cout << j << ' ';
        }
        cout << '\n';
    }
}

int main() {
    vector<vector<int>> matrix = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };
    print(matrix);
    rotate(matrix);
    cout << "rotate:\n";
    print(matrix);
}