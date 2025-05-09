class Solution 
{
public:
    int countBalancedPermutations(string num) 
    {
        // Step 1: Count digit frequencies
        vector<int> f(10, 0); 
        int s = 0;

        for (char c : num) 
        {
            f[c - '0']++;
            s += c - '0';
        }

        // Step 2: If sum is odd, can't divide evenly
        if (s % 2 != 0) return 0;

        const int mod = 1e9 + 7;
        // Step 3: Target sum for each half
        s /= 2; 
        
        int n = num.size();

        // Step 4: Precompute factorials and inverse factorials
        auto fif = enumFIF(1000, mod);

        // Step 5: Initialize DP with base case (ways to split into two halves)
        vector<vector<long long>> dp(n / 2 + 1, vector<long long>(s + 1));
        dp[0][0] = 1LL * fif[0][n / 2] * fif[0][n - n / 2] % mod;

        // Step 6: For each digit
        for (int i = 0; i <= 9; ++i) 
        {
            vector<vector<long long>> ndp(n / 2 + 1, vector<long long>(s + 1));

            // Step 7: Try all valid distributions of current digit
            for (int j = 0; j <= n / 2; ++j) 
            {
                for (int k = 0; k <= s; ++k) 
                {
                    if (dp[j][k] == 0)
                    {
                        continue;
                    } 

                    // Step 8: Try putting t copies of digit i into one half
                    for (int t = 0; t <= f[i] && k + i * t <= s && j + t <= n / 2; ++t) 
                    {
                        long long ways = dp[j][k] * 1LL * fif[1][t] % mod * fif[1][f[i] - t] % mod;
                        ndp[j + t][k + i * t] = (ndp[j + t][k + i * t] + ways) % mod;
                    }
                }
            }

            // Step 9: Move to the new dp state
            dp = ndp;
        }

        // Step 10: Final answer is how many ways to split into equal sum/length
        return dp[n / 2][s];
    }

    // Precompute factorials and inverse factorials modulo mod
    vector<vector<int>> enumFIF(int n, int mod) 
    {
        vector<int> f(n + 1), invf(n + 1);
        f[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            f[i] = 1LL * f[i - 1] * i % mod;
        } 

        long long a = f[n], b = mod, p = 1, q = 0;
        while (b > 0) 
        {
            long long c = a / b, d;
            d = a; a = b; b = d % b;
            d = p; p = q; q = d - c * q;
        }

        invf[n] = (p < 0) ? p + mod : p;
        for (int i = n - 1; i >= 0; i--) 
        {
            invf[i] = 1LL * invf[i + 1] * (i + 1) % mod;
        }

        return {f, invf};
    }
};