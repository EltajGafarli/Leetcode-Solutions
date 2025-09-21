//
// Created by Eltaj Gafarli on 9/21/2025.
//

#include<iostream>
#include <vector>
#include <cctype>
#include <algorithm>
using namespace std;

class Solution {
public:
    string generateTag(string caption) {
        vector<string> str;

        int i = 0;
        int last = 0;

        while (caption[last] == ' ') {
            last ++;
        }

        i = last;

        while (i < caption.size()) {
            if (caption[i] == ' ') {
                string sub = caption.substr(last, i - last);
                if (sub != " " && sub != "") {
                    str.push_back(sub);
                }
                last = i + 1;
            }
            i++;
        }

        string sub = caption.substr(last, i - last);
        if (sub != " " && sub != "") {
            str.push_back(sub);
        }



        i = 0;


        string result = "";

        while (i < str.size()) {
            transform(str[i].begin(), str[i].end(), str[i].begin(),
              [](unsigned char c){ return tolower(c); });
            if (i == 0) {
                str[i][0] = tolower(str[i][0]);
                result += str[i];
            } else {
                str[i][0] = toupper(str[i][0]);
                result += str[i];
            }

            i ++;
        }

        string ans = "";

        for (int i = 0; i < result.size(); i++) {
            if (isalpha(result[i])) {
                ans += result[i];
            }
        }

        return "#" + ans.substr(0, 99);

    }
};