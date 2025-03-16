class Solution {
private:
    long long check(vector<int>& piles, int h, int val, int n){
        long long total=0;
        for(int i=0;i<n;i++){
            total+=ceil((double)piles[i]/(double)val);
        }
        return total;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1, right=*max_element(piles.begin(), piles.end()), n=piles.size();
        while(left<=right){
            int mid=(left+right)/2;
            long long val=check(piles, h, mid, n);
            if(val<=h){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return left;
    }
};