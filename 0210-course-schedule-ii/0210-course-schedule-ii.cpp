class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> in(numCourses, 0);
        vector<int> topo;
        int n = 0;
        vector<vector<int>> adj(numCourses);
        for(auto it : prerequisites) {
            in[it[0]]++;
            adj[it[1]].push_back(it[0]);
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(in[i] == 0) q.push(i);
        }
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            n++;
            for(auto it : adj[node]) {
                in[it]--;
                if(in[it] == 0) {
                    q.push(it);
                }
            }
        }
        if(n != numCourses) return {};
        return topo;
    }
};