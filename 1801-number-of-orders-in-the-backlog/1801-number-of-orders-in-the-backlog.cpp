class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, BuyComp> buy;
        priority_queue<pair<int,int>, vector<pair<int,int>>, SellComp> sell;
        long res = 0;
        
        for (vector<int>& order : orders) {
            int sum = order[1];
            // buy order
            if (order.back() == 0) {
                while (!sell.empty() && sell.top().first <= order[0] && order[1]) {
                    int amount = min(order[1], sell.top().second);
                    if (sell.top().second == amount) {
                        sell.pop();
                    } else {
                        pair<int,int> cur = sell.top();
                        sell.pop();
                        cur.second -= amount;
                        sell.push(cur);
                    }
                    order[1] -= amount;
                }
                if (order[1] > 0) {
                    buy.push(make_pair(order[0], order[1]));
                }
			// sell order
            } else {
                while (!buy.empty() && buy.top().first >= order[0] && order[1]) {
                    int amount = min(order[1], buy.top().second);
                    if (buy.top().second == amount) {
                        buy.pop();
                    } else {
                        pair<int,int> cur = buy.top();
                        buy.pop();
                        cur.second -= amount;
                        buy.push(cur);
                    }
                    order[1] -= amount;
                }
                if (order[1] > 0) {
                    sell.push(make_pair(order[0], order[1]));
                }
            }
            res += order[1]*2 - sum;
        }
        return res%mod;
    }
private:
    const int mod = 1e9+7;
    
    // price, amount
    struct BuyComp {
        bool operator() (pair<int,int>& a, pair<int,int>& b) {
            return a.first < b.first;
        }
    };
    
    struct SellComp {
        bool operator() (pair<int,int>& a, pair<int,int>& b) {
            return a.first > b.first;
        }
    };
};