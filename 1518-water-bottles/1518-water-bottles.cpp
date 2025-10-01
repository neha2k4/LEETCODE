class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        // Drink all full bottles
        int cnt=numBottles;

        while(numBottles>=numExchange){
            // get exchange the numExchange empty bottles with one full bottle
            cnt+=(numBottles/numExchange);
            numBottles=(numBottles/numExchange)+(numBottles%numExchange);
        }

        // Total number of drinked bottles
        return cnt;
    }
};