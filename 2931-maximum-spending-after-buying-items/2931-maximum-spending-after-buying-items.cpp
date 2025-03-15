class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        
        long long ans=0;
        vector<long long> price;
        for(auto it:values){
            for(auto i:it) price.push_back(i);
        }
        sort(price.begin(), price.end());
        for(int i=0; i<price.size(); i++){
            ans+=price[i]*(i+1);
        }
        return ans; 
        
    }
};