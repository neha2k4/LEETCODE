class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> count(24,0);
        for(int i: candidates)
        {
            int bit=0;
            while(i>0)
            {
                count[bit]+=(i&1);
                i=i>>1;
                bit++;
            }
        }
        return *max_element(count.begin(),count.end());
        
    }
};