//
// Created by Eltaj Gafarli on 9/11/2025.
//

#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    string sortVowels(string s) {

        vector<char> strVowels;

        map<char, bool> vowels{
            {'a', true},
            {'e', true},
            {'i', true},
            {'o', true},
            {'u', true}
        };

        for (int i = 0; i < s.length(); i++) {
            if (vowels.contains(static_cast<char>(tolower(s[i])))) {
                strVowels.push_back(s[i]);
            }
        }

        ranges::sort(strVowels);

        int index = 0;

        for (int i = 0; i < s.length(); i++) {
            if (vowels.contains(static_cast<char>(tolower(s[i])))) {
                s[i] = strVowels[index ++];
            }
        }

        return s;
    }
};