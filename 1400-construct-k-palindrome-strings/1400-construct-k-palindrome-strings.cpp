class Solution {
public:
    bool canConstruct(string s, int k) {
        unordered_map<int,int>mpp;
        if(s.size()<k)
        {
            return false;
        }
        int cnt=0;
        for(int i=0;i<s.size();i++)
        {
            mpp[s[i]]++;
        }
        for(auto i=mpp.begin();i!=mpp.end();i++)
        {
            if(i->second%2==1)
            {
                cnt++;
            }
        }
        if(cnt<=k)
        {
            return true;
        }
        else{
            return false;
        }

    }
};