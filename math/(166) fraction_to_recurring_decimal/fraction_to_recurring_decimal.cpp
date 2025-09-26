//
// Created by Eltaj Gafarli on 9/26/2025.
//
#include <string>
#include <map>
using namespace std;
class Solution {
public:
    string fractionToDecimal(int num, int den) {

        long long int numerator = num;
        long long int denominator = den;

        if (numerator % denominator == 0 || numerator == 0) {
            return to_string(numerator / denominator);
        }


        bool minus = false;

        if (numerator < 0 && denominator < 0) {
            numerator = abs(numerator);
            denominator = abs(denominator);
            minus = false;
        } else if (numerator > 0 && denominator < 0) {
            numerator = abs(numerator);
            denominator = abs(denominator);
            minus = true;
        } else if (numerator < 0 && denominator > 0) {
            numerator = abs(numerator);
            denominator = abs(denominator);
            minus = true;
        }

        long long int full = numerator / denominator;
        long long int rem = numerator % denominator;

        string rem_result = ".";
        long long int x = rem;

        map<string, int> mp;

        int index = -1;
        int i = 0;

        while (x % denominator != 0) {
            x = (x % denominator) * 10;
            long long int x_full = x / denominator;

            string m = to_string(x) + "." + to_string(denominator);
            if (mp.find(m) != mp.end()) {
                index = mp.at(m);
                break;
            }
            mp[m] = i;
            i++;
            rem_result = rem_result + to_string(x_full);
        }

        string sign = minus ? "-" : "";

        if (index == -1) {
            return sign +  to_string(full) + (rem_result == "." ? "" : rem_result);
        }

        string p = "";

        for(i = 0; i < rem_result.length(); i ++) {
            p += rem_result[i];
            if (i == index) {
                p += "(";
            }
        }

        return sign + to_string(full) + p + ")";

    }
};