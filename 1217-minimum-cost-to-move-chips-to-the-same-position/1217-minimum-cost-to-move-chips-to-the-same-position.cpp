class Solution {
public:
    int minCostToMoveChips(vector<int>& pos) {
        int odd = 0;
        int even = 0;
        for(int i = 0;i<pos.size();i++){
            if(pos[i] %2 == 1)odd++;
            else even++;
        
        }
        return min(even,odd);
        
    }
};