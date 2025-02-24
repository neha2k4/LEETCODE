class Solution {
public:
    bool dfs(int node,unordered_map<int,list<int>>&adj,unordered_map<int,bool>&vis,vector<int>&time, int timer){
        vis[node]=true;
        time[node]=timer;
        if(node==0) return true;
        
        for(auto i:adj[node]){
            if(!vis[i]){
                if(dfs(i,adj,vis,time,timer+1)){return true;}
            }
        }
        time[node]=-1;
        return false;
    }
    long long adfs(int node , int time,unordered_map<int,bool>&v,unordered_map<int,list<int>>&adj,vector<int>&timeBob,vector<int>&amount){
        if(adj[node].size() == 1 && node != 0) {  
   if(timeBob[node]==time) return amount[node]/2;
   else if(timeBob[node]<time && timeBob[node]!=-1) return 0;
   else return amount[node];
}

        long long ans=INT_MIN;
        v[node]=true;
        //long long 
        for(auto i:adj[node]){
            if(!v[i]){
                if(timeBob[node]==time){ans=max(ans,(amount[node]/2)+adfs(i,time+1,v,adj,timeBob,amount));}
                else if(timeBob[node]<time && timeBob[node]!=-1){ans=max(ans,0+adfs(i,time+1,v,adj,timeBob,amount));}
                else{ans=max(ans,(amount[node])+adfs(i,time+1,v,adj,timeBob,amount));}
            }
        }
        return ans;

    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n=edges.size()+1;
        unordered_map<int,list<int>>adj;
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int>time(n+1,-1);
        int timer=0;
        time[bob]=timer;
        unordered_map<int,bool>vis;
        vis[bob]=true;
        for(auto i:adj[bob]){
            if(dfs(i,adj,vis,time,timer+1)){break;}
        }
        for(auto i:time) cout<<i<<" ";
        unordered_map<int,bool>v;
        int t=0;
        long long ans=INT_MIN;
        cout<<ans<<" "<<endl;
        ans=max(ans,adfs(0,t,v,adj,time,amount));
        

        return ans;

    }
};