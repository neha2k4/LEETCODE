class Solution {
public:
    
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        vector<int>ans(queries.size());
        unordered_map<int,int>mp;
        vector<pair<int,int>>vk;
        for(int i=0;i<queries.size();i++) vk.push_back({queries[i],i});
        for(auto &it:logs) swap(it[0],it[1]);

        sort(logs.begin(),logs.end());
        sort(vk.begin(),vk.end());

        int l=0,r=0;
        int cnt=0;
        for(auto q:vk){
            int qr=q.first;
            int idx=q.second;

            while(r<logs.size() && logs[r][0]<=qr){
                mp[logs[r][1]]++;
                if(mp[logs[r][1]]==1) cnt++;
                r++;
            }

            while(l<logs.size() && logs[l][0]<(qr-x)){
                mp[logs[l][1]]--;
                if(mp[logs[l][1]]==0) cnt--;
                l++;
            }
            ans[idx]=n-cnt;
        }
        return ans;
    }
};