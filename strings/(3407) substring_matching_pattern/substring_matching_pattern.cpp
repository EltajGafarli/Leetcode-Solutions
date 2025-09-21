//
// Created by Eltaj Gafarli on 9/21/2025.
//

#include <string>
using namespace std;

class Solution {
public:
    bool hasMatch(string s, string p) {
        int starIndex = p.find("*");

        int size = p.size();

        string left = p.substr(0, starIndex);
        string right = p.substr(starIndex + 1, size - starIndex + 1);


        if (left.empty() && right.empty()) {
            return true;
        }


        if (s.find(left) == string::npos || s.find(right) == string::npos) {
            return false;
        }

        int ind1 = s.find(left);

        int ind2 = s.rfind(right);

        if (left.empty()) {
            if (ind2 != string::npos) {
                return true;
            }

            return false;
        }

        if (right.empty()) {
            if (ind1 != string::npos) {
                return true;
            }

            return false;
        }

        if (ind2 - ind1 > 0) {
            if (ind1 + left.length() > ind2) return false;
            return true;
        }
        return false;
    }
};