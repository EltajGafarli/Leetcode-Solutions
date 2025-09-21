//
// Created by Eltaj Gafarli on 9/21/2025.
//

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include<string>
#include <vector>
#include <bits/ostream.tcc>
using namespace std;

class Solution {
public:
    bool equalFrequency(string word) {
        map<char, int> letter_map;

        for(int i = 0; i < word.size(); i++) {
            letter_map[word[i]] ++;;
        }

        vector<int> freq;

        for (auto it: letter_map) {
            freq.push_back(it.second);
        }

        sort(freq.begin(), freq.end());
        // 2 2

        int first = freq[0]; // 2
        int last = freq[freq.size() - 1]; // 2

        cout << first << ' ' << last << endl;

        if ((first == 1 && last == 1) || freq.size() == 1) {
            return true;
        }

        if (first + 1 == last) {
            if (freq.size() == 2) {
                return true;
            } else {
                if (freq[1] == last) {
                    if (first > 1) return false;
                    return true;
                }
                if (freq[freq.size() - 2] == last) {
                    return false;
                }

                return true;
            }
        } else {
            set<int> nums;
            map<int, int> freq_map;

            for (auto it: freq) {
                nums.insert(it);
                freq_map[it] ++;
            }

            if (nums.size() == 2 and (min(last, first) == 1)) {

                int mini = min(last, first);

                if (freq_map[mini] > 1) {
                    return false;
                }
                return true;
            }

            return false;
        }
    }
};