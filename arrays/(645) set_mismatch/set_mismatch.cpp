//
// Created by Eltaj Gafarli on 9/10/2025.
//

#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int size = nums.size();
        long long int sumOfN = (size + 1) * size / 2;
        long long int sum = 0;
        int twice = 0;
        map<int, bool> nums_count_map;

        for (auto num: nums) {
            sum += num;

            if (nums_count_map[num]) {
                twice = num;
            }
            nums_count_map[num] = true;
        }

        sum -= twice;

        int missing = static_cast<int>(sumOfN - sum);

        return {twice, missing};
    }
};