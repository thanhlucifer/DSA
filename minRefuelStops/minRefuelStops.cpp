#include <iostream>
#include <vector>
using namespace std;

int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    int n = stations.size();
    vector<long long> dp(n + 1, 0);
    dp[0] = startFuel;

    for (int i = 0; i < n; ++i) {
        for (int j = i; j >= 0; --j) {
            if (dp[j] >= stations[i][0]) {
                dp[j + 1] = max(dp[j + 1], dp[j] + stations[i][1]);
            }
        }
    }

    for (int i = 0; i <= n; ++i) {
        if (dp[i] >= target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int target = 100;
    int startFuel = 10;
    vector<vector<int>> stations = {{10, 60}, {20, 30}, {30, 30}, {60, 40}};
    cout << "Minimum refueling stops: " << minRefuelStops(target, startFuel, stations) << endl;
    return 0;
}
