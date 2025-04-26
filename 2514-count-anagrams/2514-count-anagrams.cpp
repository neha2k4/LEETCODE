#pragma GCC optimize("O3", "unroll-loops")
static int mod=1e9+7;
class Solution {
public:
    vector<long long> fact;
    void factorialMod(int n){
        fact.assign(n+1, 1);
        for(int i=2; i<=n; i++){
            fact[i]=fact[i-1]*i%mod;
        }
    }
    // Find x, y, d such that ax + by = d where d = gcd(a, b)
    int modInverse(int a, int b=mod) {//mod is prime d=1
        int x0 = 1, x1 = 0;
        int r0 = a, r1 = b;
        while (r1 != 0) {
            int q = r0/r1, rr = r1, xx = x1;
            r1 = r0-q * r1;
            x1 = x0-q * x1;
            r0 = rr;
            x0 = xx;
        }
        if (x0 < 0) x0+= b;
        return x0;
    }
    long long computePerm(array<int, 26>& freq, int wlen){
        long long ans=fact[wlen];
        for(int f: freq){
            if (f!=0){
                ans=(ans*modInverse(fact[f]))%mod;
            }
        }
        return ans%mod;
    }
    int countAnagrams(string& s) {
        int n=s.size();
        factorialMod(n);
        long long ans=1;
        array<int, 26> freq={0};
        int wlen=0;
        for (int i=0; i<n; i++){
            while(i<n && s[i]!=' '){
                freq[s[i]-'a']++;
                wlen++;
                i++;
            }
            ans=(ans*computePerm(freq, wlen))%mod;
            if (i<n){
                freq.fill(0);
                wlen=0;
            }
        }
        return ans%mod;
    }
};

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();