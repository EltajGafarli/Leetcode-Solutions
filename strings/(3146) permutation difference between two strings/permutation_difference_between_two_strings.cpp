//
// Created by Eltaj Gafarli on 9/17/2025.
//

#include <map>
#include<string>
#include<cmath>
using namespace std;

class Solution {
public:
    int findPermutationDifference(string s, string t) {
        map<char, int> tIndex;
        int res = 0;

        for(int i = 0; i < t.length(); i++) {
            tIndex[t[i]] = i;
        }

        for(int i = 0; i < s.length(); i++) {
            res += abs(tIndex[s[i]] - i);
        }

        return res;
    }
};