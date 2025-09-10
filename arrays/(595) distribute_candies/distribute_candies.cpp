//
// Created by Eltaj Gafarli on 9/10/2025.
//


#include <map>
#include<vector>

using namespace std;

class Solution {
public:

    static int distributeCandies(vector<int>& candyType) {

        map<int, int> candies;

        for (auto type : candyType) {
            candies[type] += 1;
        }

        int canEatCount = static_cast<int>(candyType.size()) / 2;
        int candies_size = static_cast<int>(candies.size());

        return min(canEatCount, candies_size);
    }
};