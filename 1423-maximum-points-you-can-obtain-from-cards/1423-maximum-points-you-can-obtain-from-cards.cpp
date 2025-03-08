class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int s = n - k, e = n - k;
        int maxi = 0, sum = 0;
        while(e < n){
            sum += cardPoints[e];
            e++;
        }
        maxi = sum;
        while(e < (n  + k)){
            sum += (cardPoints[e % n] - cardPoints[s % n]);
            e++;
            s++;
            maxi = max(maxi, sum); 
        }
        return maxi;
    }
};