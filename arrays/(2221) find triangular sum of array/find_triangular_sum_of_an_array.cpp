//
// Created by Eltaj Gafarli on 9/11/2025.
//

#include <stdexcept>
#include <vector>
using namespace std;

class Solution {
public:

    long long int findFactorial(int n) {
        if (n < 0) {
            throw range_error("Negative number cannot be found");
        }
        if (n == 0 || n == 1) {
            return 1;
        }

        return n * (findFactorial(n - 1) % 10);
    }

    int calculateCombinations(int n, int k) {
        if (n < 0 || k < 0) {
            throw range_error("Negative number cannot be found");
        }
        long long int n_factorial = findFactorial(n) % 10;
        long long int k_factorial = findFactorial(k) % 10;
        int diff = n - k;
        long long int diff_factorial = findFactorial(diff) % 10;
        return static_cast<int> (n_factorial / (k_factorial * diff_factorial));
    }

    int find_number_of_zeros(long long int n) {
        int result = 0;

        n = n / 5;

        while (n > 0) {
            result += n % 5;
            n = n / 5;
        }

        return result;
    }

    int triangularSum(vector<int>& nums) {
        int size = static_cast<int>(nums.size());

        int sum = 0;

        for (int i = 0; i < size; i++) {
            int nZeros = find_number_of_zeros(size - 1);
            int kZeros = find_number_of_zeros(i);
            int diffZeros = find_number_of_zeros(size - i - 1);

            int finalZeros = 0;

            if (kZeros > 0 && diffZeros > 0) {
                finalZeros = nZeros / (kZeros * diffZeros);
            }
            if (finalZeros > 0) {
                continue;
            }
            int base = calculateCombinations(size - 1, i) % 10;
            sum += (base * nums[i]) % 10;
        }

        return sum % 10;
    }
};

// mathematical solution
// it cannot work for the number of elements 200 and more
