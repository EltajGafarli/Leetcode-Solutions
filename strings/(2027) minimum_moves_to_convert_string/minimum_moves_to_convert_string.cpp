//
// Created by Eltaj Gafarli on 9/18/2025.
//

#include<string>
using namespace std;

class Solution {
public:
    int minimumMoves(string s) {

        int i = 0;

        int step = 0;

        while(i < s.length()) {
            if (s[i] == 'X') {
                i += 3;
                step ++;
            } else {
                i ++;
            }
        }

        return step;

    }
};