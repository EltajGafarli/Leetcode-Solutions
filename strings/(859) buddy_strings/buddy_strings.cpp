//
// Created by Eltaj Gafarli on 9/22/2025.
//
#include <map>
#include<string>
using namespace std;

class Solution {
public:
    bool buddyStrings(string s, string goal) {

        if (s.length() != goal.length() || s.length() < 2 || goal.length() < 2) {
            return false;
        }

        map<char, int> sMap;
        map<char, int> gMap;

        for (int i = 0; i < s.length(); i++) {
            sMap[s[i]]++;
            gMap[goal[i]]++;
        }


        int diffCount = 0;
        int left = 0, right = 0;
        bool leftExists = false;
        int size = s.length();

        for (int i = 0; i < size; i ++) {
            if (s[i] != goal[i]) {
                if (leftExists) {
                    right = i;
                } else {
                    leftExists = true;
                    left = i;
                }

                diffCount ++;

                if (diffCount > 2) {
                    return false;
                }
            }
        }

        if (diffCount == 1) {
            return false;
        }

        if (diffCount == 0) {
            if (s.length() > 2) {
                if (sMap.size() == s.size()) {
                    return false;
                }

                return true;
            }
            swap(s[0], s[size - 1]);
            return s == goal;
        }

        swap(s[left], s[right]);

        return s == goal;
    }
};