//
// Created by Eltaj Gafarli on 9/22/2025.
//
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        vector<int> nums;
        vector<char> ops;

        map<char, bool> opMap = {
            {'+', true},
            {'-', true},
            {'*', true},
            {'/', true}
        };

        for (int i = 0; i < s.length(); i++) {
            if (opMap[s[i]]) {
                ops.push_back(s[i]);
            } else if (s[i] != ' ') {
                if (i > 0 && !opMap[s[i - 1]] && s[i - 1] != ' ') {
                    int top = 10 * nums.back() + (s[i] - '0');
                    nums[nums.size() - 1] = top;
                } else {
                    nums.push_back(s[i] - '0');
                }
            }
        }

        stack<int> st;


        for (int i = 0; i < ops.size(); i++) {
            if (ops[i] == '+') {
                if (i == 0) {
                    st.push(nums[i]);
                }

                st.push(nums[i + 1]);


            } else if (ops[i] == '-') {
                if (i == 0) {
                    st.push(nums[i]);

                }
                st.push(-1 * nums[i + 1]);
            } else {
                if (st.empty()) {
                    st.push(nums[i]);
                }
                int top = st.top();
                st.pop();

                if (ops[i] == '*')
                    st.push(top * nums[i + 1]);

                else st.push(top / nums[i + 1]);
            }
        }

        int result = 0;

        if (st.empty()) {
            return nums[0];
        }

        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        return result;
    }
};