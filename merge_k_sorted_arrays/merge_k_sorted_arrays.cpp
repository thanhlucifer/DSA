#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Define a tuple to store value, row, and column
typedef tuple<int, int, int> Tuple;

// Define comparison for priority queue
struct Compare {
    bool operator()(Tuple const &a, Tuple const &b) {
        return get<0>(a) > get<0>(b);
    }
};

vector<int> merge_k_sorted_arrays(vector<vector<int>> &matrix) {
    vector<int> merged;
    priority_queue<Tuple, vector<Tuple>, Compare> pq;
    
    // Push the first element from each array into the priority queue
    for (int i = 0; i < matrix.size(); ++i) {
        pq.push({matrix[i][0], i, 0});
    }
    
    while (!pq.empty()) {
        auto [val, row, col] = pq.top();
        pq.pop();
        merged.push_back(val);
        
        // Push the next element from the same row into the priority queue
        if (col + 1 < matrix[row].size()) {
            pq.push({matrix[row][col + 1], row, col + 1});
        }
    }
    
    return merged;
}

int main() {
    vector<vector<int>> matrix = {{1, 3, 5}, {2, 4, 6}, {7, 8, 9}};
    vector<int> result = merge_k_sorted_arrays(matrix);
    
    cout << "Merged array: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
