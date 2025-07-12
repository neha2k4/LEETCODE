class Solution {
public:
    // time/space: O(n)/O(n)
    int minimumTimeToInitialState(string word, int k) {
        int n = word.size();
        // build the rolling hash table
        vector<int> hash(n + 1, 0);
        vector<int> power(n + 1, 1);
        for (int i = 0; i < n; i++) {
            power[i + 1] = ((1LL * power[i] * POWER) % MOD);
            hash[i + 1] = ((hash[i] + 1LL * (word[i] - 'a') * power[i]) % MOD);
        }

        // try to match `s[i..]` with `s[0..]`
        for (int i = k; i < n; i += k) {
            int hash_a = (1LL * hash[n - i] * power[i]) % MOD;
            int hash_b = (hash[n] + MOD - hash[i]) % MOD;
            if (hash_a == hash_b) return (i / k);
        }
        return ((n + k - 1) / k);
    }
private:
    const int POWER = 26;
    const int MOD = 1e9 + 7;
};