//
// Created by Eltaj Gafarli on 9/17/2025.
//

#include<iostream>
#include<map>
using namespace std;

class Solution {
public:
    int maxFreqSum(string s) {
        map<char, bool> vowels = {
            {'a', true},
            {'e', true},
            {'i', true},
            {'o', true},
            {'u', true}
        };

        int maxVowel = 0;
        int maxConsonant = 0;

        map<char, int> vowelCounter;
        map<char, int> consonantCounter;

        for (int i = 0; i < s.length(); i++) {
            if (vowels[s[i]]) {
                vowelCounter[s[i]]++;
                maxVowel = max(maxVowel, vowelCounter[s[i]]);
            } else {
                consonantCounter[s[i]] ++;
                maxConsonant = max(maxConsonant, consonantCounter[s[i]]);
            }
        }

        return maxVowel + maxConsonant;
    }
};