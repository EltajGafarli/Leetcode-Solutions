//
// Created by Eltaj Gafarli on 9/15/2025.
//

#include<iostream>
#include<map>
using namespace std;

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        map<char, bool> brokenMap;

        for (int i = 0; i < brokenLetters.length(); i++) {
            brokenMap[brokenLetters[i]] = true;
        }

        int result = 0;
        int counter = 0;

        for (int i = 0; i < text.length(); i++) {
            if (text[i] == ' ') {
                if (counter == 0) {
                    result ++;
                }
                counter = 0;
            } else {
                if (brokenMap[text[i]]) {
                    counter ++;
                }
            }
        }

        result += counter != 0 ? 0 : 1;

        return result;
    }
};