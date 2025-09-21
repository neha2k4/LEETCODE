class Solution {
public:
    bool check(vector<int>&v,map<char, int> &m){
        for(int i =0;i<26;i++){
            if(m[char('A'+i)]<v[i]){return false;}
        }
        return true;
    }
    int balancedString(string s) {
        vector<int> v(26, 0);
        map<char, int> m,m1;
        int n = s.length();
        for (auto i : s) {
            m1[i]++;
            if (m1[i] > (n / 4)) {
                v[i - 'A'] += 1;
            }
        }
        int p = -1,l=0,ans=0;
        while(p<n && check(v,m)==false){p++;m[s[p]]++;}
        ans = p + 1;
        for(int i=p+1;i<n;i++){
            m[s[i]]++;
            while(l<i && check(v,m)==true){m[s[l]]--;l++;}
            ans=min(ans,i-l+2);
        }
        return ans;
    }
};