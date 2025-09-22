//
// Created by Eltaj Gafarli on 9/21/2025.
//

#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        int size = s.length();

        if (size < k) {
            reverse(s.begin(), s.end());
            return s;
        }

        int i = 0;

        while (i < size) {
            int end = i + k;

            if (end >= size) {
                end = s.end() - s.begin();
            }
            reverse(s.begin() + i, s.begin() + end);
            i += 2 * k;
        }

        reverse(s.begin() + i, s.end());

        return s;

    }
};