//
// Created by Eltaj Gafarli on 9/22/2025.
//
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    bool buddyStrings(string s, string goal) {

        if (s == goal) {
            int arr[26] = {};

            for (int i = 0; i < s.length(); i++) {
                arr[s[i] - 'a']++;
                if (arr[s[i] - 'a'] > 1) {
                    return true;
                }
            }

            return false;
        }

        if (s.length() != goal.length()) {
            return false;
        }

        vector<int> inds;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] != goal[i]) {
                inds.push_back(i);
            }
        }


        if (inds.size() > 2) {
            return false;
        }
        if (inds.size() < 2) {
            return false;
        }

        int left = inds[0], right = inds[1];

        return (s[left] == goal[right] && s[right] == goal[left]);

    }
};