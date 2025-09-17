//
// Created by Eltaj Gafarli on 9/17/2025.
//

#include <bitset>
#include<string>
using namespace std;

class Solution {
public:
    string convertDateToBinary(string date) {
        string yearStr = date.substr(0, 4);
        string monthStr = date.substr(5, 2);
        string dayStr = date.substr(8, 2);

        string split = date.substr(4, 1);

        int year = stoi(yearStr);
        int month = stoi(monthStr);
        int day = stoi(dayStr);

        string yearBit = toBinary(year);

        string monthBit = toBinary(month);

        string dayBit = toBinary(day);

        return yearBit + split + monthBit + split + dayBit;
    }

    string toBinary(int n) {
        if (n == 0) return "0";
        string result;
        while (n > 0) {
            result = char('0' + (n % 2)) + result;
            n /= 2;
        }
        return result;
    }
};