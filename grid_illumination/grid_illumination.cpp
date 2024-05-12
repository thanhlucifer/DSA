#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> grid_illumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
    vector<vector<int>> grid(n, vector<int>(n, 0));
    vector<int> ans;

    // Bật đèn và chiếu sáng các ô lân cận
    for (auto lamp : lamps) {
        int row = lamp[0], col = lamp[1];
        grid[row][col] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (row == i || col == j || abs(row - i) == abs(col - j)) {
                    grid[i][j] = 1;
                }
            }
        }
    }

    // Xử lý các truy vấn và tắt đèn
    for (auto query : queries) {
        int query_row = query[0], query_col = query[1];
        if (grid[query_row][query_col] == 1) {
            ans.push_back(1);
        } else {
            ans.push_back(0);
        }
        // Tắt đèn và đèn lân cận
        for (int i = query_row - 1; i <= query_row + 1; ++i) {
            for (int j = query_col - 1; j <= query_col + 1; ++j) {
                if (i >= 0 && i < n && j >= 0 && j < n && grid[i][j] == 1) {
                    grid[i][j] = 0;
                }
            }
        }
    }

    return ans;
}

int main() {
    int n = 5;
    vector<vector<int>> lamps = {{0,0},{4,4}};
    vector<vector<int>> queries = {{1,1},{1,0}};

    vector<int> result = grid_illumination(n, lamps, queries);
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
