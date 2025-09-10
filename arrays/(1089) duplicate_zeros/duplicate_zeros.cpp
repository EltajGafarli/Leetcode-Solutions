//
// Created by Eltaj Gafarli on 9/10/2025.
//

#include<vector>
using namespace std;

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int> result;

        for (int i : arr) {
            if (i == 0) {
                result.push_back(i);
                result.push_back(i);
            } else {
                result.push_back(i);
            }
        }

        for (int i = 0; i < result.size(); i++) {
            arr[i] = result[i];
        }
    }
};