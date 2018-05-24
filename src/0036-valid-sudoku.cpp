/*
Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

Example 1:
Input:
[
['5','3','.','.','7','.','.','.','.'],
['6','.','.','1','9','5','.','.','.'],
['.','9','8','.','.','.','.','6','.'],
['8','.','.','.','6','.','.','.','3'],
['4','.','.','8','.','3','.','.','1'],
['7','.','.','.','2','.','.','.','6'],
['.','6','.','.','.','.','2','8','.'],
['.','.','.','4','1','9','.','.','5'],
['.','.','.','.','8','.','.','7','9']
]
Output: true
*/
#include <utils.h>

// 分别通过三个二维数组来保存三个规则的状态,然后再挨个检查是否在三个规则中有重复
class Solution {
public:
    bool isValidSudoku(vector<vector<char>> &board) {
        int rows[9][9] = {0}, columns[9][9] = {0}, boxes[9][9] = {0}; // 可以考虑用位运算来节约空间或者通过复用的方式

        if (board.size() != 9 || board[0].size() != 9) return false;

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == '.') continue;

                int idx = board[i][j] - '1';
                int row_idx = i, column_idx = j, box_idx = i / 3 * 3 + j / 3;
                if (rows[row_idx][idx] != 0 || columns[column_idx][idx] != 0 || boxes[box_idx][idx] != 0) {
                  return false;
                }
                rows[row_idx][idx] = columns[column_idx][idx] = boxes[box_idx][idx] = 1;
            }
        }

        return true;
    }
};

TEST(_0036, IsValidSudoku) {
    Solution s;

    vector<vector<char>> case0 = {
            {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    ASSERT_TRUE(s.isValidSudoku(case0));
}