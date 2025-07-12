class Solution {
public:
    string longestPrefix(string s) {
        int n=s.length();
        long long p=31,pre=0,suf=0,mod=1e9+7,pro=31;
        int ans=0;
        for(int i=0;i<n-1;i++)
        {
            pre=(pre+pro*(s[i]-'a'+1)+mod)%mod;
            suf=(suf*p+p*(s[n-i-1]-'a'+1)+mod)%mod;
            pro=(pro*p)%mod;
            if(pre==suf) ans=i+1;
        }
        return s.substr(0,ans);
    }
};