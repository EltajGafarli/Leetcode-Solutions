//
// Created by Eltaj Gafarli on 9/22/2025.
//

#include<string>
using namespace std;

class Solution {
public:
    bool checkOnesSegment(string s) {
        return s.find("01") == string::npos;
    }
};