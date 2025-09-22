//
// Created by Eltaj Gafarli on 9/22/2025.
//

#include <stack>
#include<string>
using namespace std;

class Solution {
public:
    int calculate(string s) {

        stack<int> st;
        int curr = 0;
        char operation = '+';

        for (int i = 0; i < s.length(); i++) {
            char currChar = s[i];
            if (isdigit(currChar)) {
                curr = curr * 10 + (currChar - '0');
            }

            if (!isdigit(currChar) && currChar != ' ' || i == s.length() - 1) {
                if (operation == '+') {
                    st.push(curr);
                } else if (operation == '-') {
                    st.push(-curr);
                } else if (operation == '*') {
                    int top = st.top();
                    st.pop();
                    st.push(top * curr);
                } else if (operation == '/') {
                    int top = st.top();
                    st.pop();
                    st.push(top / curr);
                }

                operation = currChar;
                curr = 0;
            }
        }

        int result = 0;

        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        return result;
    }
};