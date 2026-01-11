class Solution {
public:
    int dp[305][5005];

    int solve(int i, int amount, vector<int>& coins) {
        if (amount == 0) return 1;
        if (i < 0 || amount < 0) return 0;

        if (dp[i][amount] != -1)
            return dp[i][amount];

      
        return dp[i][amount] =
            solve(i, amount - coins[i], coins) +
            solve(i - 1, amount, coins);
    }

    int change(int amount, vector<int>& coins) {
        memset(dp, -1, sizeof(dp));
        return solve(coins.size() - 1, amount, coins);
    }
};
