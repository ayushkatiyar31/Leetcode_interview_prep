class Solution {
public:
    unordered_map<string, int> memo;

    int solve(int i, int sum, vector<int>& nums, int target) {
        if (i == nums.size()) {
            return sum == target;
        }

        string key = to_string(i) + "," + to_string(sum);
        if (memo.count(key)) return memo[key];

        int add = solve(i + 1, sum + nums[i], nums, target);
        int subtract = solve(i + 1, sum - nums[i], nums, target);

        return memo[key] = add + subtract;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(0, 0, nums, target);
    }
};
