//
// Created by Eltaj Gafarli on 9/22/2025.
//

#include<string>
using namespace std;

class Solution {
public:
    bool checkOnesSegment(string s) {
        int left = 0, right = s.size() - 1;

        while (s[right] == '0') {
            right--;
        }

        const string sub = s.substr(left, right - left + 1);

        return sub.find('0') == string::npos;
    }
};