//
// Created by Eltaj Gafarli on 9/17/2025.
//

#include<string>
#include <vector>
using namespace std;

class Solution {
public:

    void build_matrix(vector<vector<int>>& matrix, int n) {
        int i = 0;
        int j = 0;

        while (i < n) {
            int cnt = 0;
            vector<int> row;

            while (cnt < n) {
                row.push_back(j ++);
                cnt ++;
            }

            matrix.push_back(row);
            i ++;
        }
    }
    int finalPositionOfSnake(int n, vector<string>& commands) {
        const string UP = "UP";
        const string DOWN = "DOWN";
        const string LEFT = "LEFT";
        const string RIGHT = "RIGHT";

        vector<vector<int>> matrix;

        build_matrix(matrix, n);

        int x = 0;
        int y = 0;

        for (int i = 0; i < commands.size(); i ++) {
            if (commands[i] == UP && x > 0) {
                x --;
            } else if (commands[i] == DOWN && x < n - 1) {
                x ++;
            } else if (commands[i] == LEFT && y > 0) {
                y --;
            } else if (commands[i] == RIGHT && y < n - 1) {
                y ++;
            }
        }


        return matrix[x][y];
    }
};