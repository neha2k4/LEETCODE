const int mod = 1000000007;
class Solution {
    vector<int> subtreeCount; // Stores number of elements in subtree rooted at any node
    vector<int> dp; // Stores answer for subtree rooted at any node
    
    struct BinomialCoefficients{
        vector<int> fact, inverse;

        BinomialCoefficients(int n){
            fact = vector<int>(n+1, 1);
            inverse = vector<int>(n+1, 1);
            for(int i = 2 ; i <= n ; i++){
                fact[i] = 1LL * fact[i-1] * i % mod;
                inverse[i] = getPower(fact[i], mod-2);
            }
        }

        int getPower(int x, int y){
            int res = 1;
            while(y){
                if(y & 1) res = 1LL * res * x % mod;
                y >>= 1;
                x = 1LL * x * x % mod;
            }
            return res;
        }
        
        inline int getNcr(int n, int r){
            return (n >= r ? 1LL * fact[n] * inverse[r] % mod * inverse[n-r] % mod : 0); 
        }
    };
    
    BinomialCoefficients *binomial = NULL;
public:
    int waysToBuildRooms(vector<int>& prevRoom) {
        int n = prevRoom.size();
        subtreeCount = vector<int>(n, 0);
        dp = vector<int>(n, 1);
        binomial = new BinomialCoefficients(n);
        
        // Create and build tree
        vector<int> g[n];
        for(int i = 1 ; i < n ; i++) g[prevRoom[i]].emplace_back(i);
        
        dfs(g, 0);
        return dp[0];
    }
    
    void dfs(vector<int> g[], int node){
        for(int i : g[node]){
            dfs(g, i);
            dp[node] = 1LL * dp[node] * dp[i] % mod;
            subtreeCount[node] += subtreeCount[i];
        }
        
        // Combinatorics part
        int remainingNodes = subtreeCount[node];
        for(int i : g[node]){
            dp[node] = 1LL * dp[node] * binomial->getNcr(remainingNodes, subtreeCount[i]) % mod;
            remainingNodes -= subtreeCount[i];
        }
        
        subtreeCount[node]++; // Including current node in this subtree
    }
};