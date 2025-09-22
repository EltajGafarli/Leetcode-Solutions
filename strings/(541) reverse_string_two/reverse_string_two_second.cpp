//
// Created by Eltaj Gafarli on 9/22/2025.
//

#include <algorithm>
#include <ranges>
#include <string>
using namespace std;

class Solution {

public:
    string reverseStr(string s, int k) {

        int size = s.length();
        for (int i = 0; i < size;) {
            int end = min(i + k, size);

            reverse(s.begin() + i, s.begin() + end);

            i += 2 * k;
        }
    }
};