#include <iostream>
#include <vector>
using namespace std;

void dfs(int idx, const vector<int>& nums, vector<int>& curr, vector<vector<int>>& res) {
    if (idx == nums.size()) {
        res.push_back(curr);
        return;
    }
    // Include nums[idx]
    curr.push_back(nums[idx]);
    dfs(idx + 1, nums, curr, res);
    curr.pop_back();
    // Exclude nums[idx]
    dfs(idx + 1, nums, curr, res);
}

vector<vector<int>> subsets(const vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> curr;
    dfs(0, nums, curr, res);
    return res;
}

int main() {
    vector<int> nums = {1, 2, 3};
    auto all = subsets(nums);
    for (auto& s : all) {
        cout << "[ ";
        for (int x : s) cout << x << " ";
        cout << "]\n";
    }
    return 0;
}
