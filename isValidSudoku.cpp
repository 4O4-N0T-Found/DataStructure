// 判断一个 9x9 的数独是否有效。
#include <iostream>
#include <vector>
using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    int row[9][10] = {0};
    int col[9][10] = {0};
    int box[9][10] = {0};
    int i, j, curr;
    for(i = 0; i < 9; i++) {
        for(j = 0; j < 9; j++) {
            if(board[i][j] == '.')     continue;
            curr = (int)board[i][j] - '0';
            if(row[i][curr] == 1)   return false;
            if(col[j][curr] == 1)   return false;
            if(box[j/3 + (i/3)*3][curr] == 1)   return false;
            row[i][curr] = 1;
            col[j][curr] = 1;
            box[j/3 + (i/3)*3][curr] = 1;
        }
    }
    return true;
}

int main() {
    vector<vector<char>> board = {
            {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    cout << isValidSudoku(board);
}
