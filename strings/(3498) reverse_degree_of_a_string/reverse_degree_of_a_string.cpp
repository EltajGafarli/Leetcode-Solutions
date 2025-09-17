//
// Created by Eltaj Gafarli on 9/17/2025.
//

#include<string>
using namespace std;

class Solution {
public:
    int reverseDegree(string s) {
        char last = 'z';

        int res = 0;

        for (int i = 0; i < s.length(); i++) {
            int diff = last - s[i] + 1;
            res += diff * (i + 1);
        }

        return res;
    }
};