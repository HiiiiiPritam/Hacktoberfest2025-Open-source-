class Solution {
public:
    int M = 1e9 + 7;
    
    int fun(int i, int n, int minProfit, vector<int>& group, vector<int>& profit,
            vector<vector<vector<int>>>& dp) {
        
        if (i == group.size()) return minProfit <= 0;
        if (dp[i][n][minProfit] != -1) return dp[i][n][minProfit];
        
        long long res = fun(i + 1, n, minProfit, group, profit, dp); // not take
        
        if (n >= group[i]) {
            int newProfit = max(0, minProfit - profit[i]);
            res += fun(i + 1, n - group[i], newProfit, group, profit, dp);
        }
        
        return dp[i][n][minProfit] = res % M;
    }

    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int m = group.size();
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(minProfit + 1, -1)));
        return fun(0, n, minProfit, group, profit, dp);
    }
};
