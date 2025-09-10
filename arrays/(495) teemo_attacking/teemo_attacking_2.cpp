//
// Created by Eltaj Gafarli on 9/10/2025.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int size = timeSeries.size();
        int result = 0;

        for (int i = 0; i < size - 1; i++) {
            result += min(timeSeries[i + 1] - timeSeries[i], duration);
        }

        return result + duration;
    }
};

vector<int> get_time_series(int size) {
    vector<int> time_series;

    for (int i = 0; i < size; i++) {
        cin >> time_series[i];
    }

    return time_series;
}

int main() {
    int size, duration;

    cin >> size;

    vector<int> time_series = get_time_series(size);

    cin >> duration;


    Solution solution;

    const int result = solution.findPoisonedDuration(time_series, duration);

    cout << "Result: " << result << endl;
}