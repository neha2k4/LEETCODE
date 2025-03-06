class Solution {
public:
    bool digitCount(string num) {
        int n = num.size();
        vector<int> count(10, 0);
        for(int i = 0; i < n; i++)
        {
            count[num[i] - '0']++;
        }
        for(int i = 0; i < n; i++)
        {
            if(count[i] == (num[i] - '0')) continue;
            else return false;
        }
        return true;
    }
};