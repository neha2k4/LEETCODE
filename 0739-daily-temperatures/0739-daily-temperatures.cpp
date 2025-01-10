
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n, 0);
        stack<int> s; // Stack to store the indices
        for(int i = 0; i < n;i++){
            while(!s.empty() && temperatures[i] > temperatures[s.top()]){
                int idx = s.top();
                s.pop();
                answer[idx] = i - idx; 
            }
            s.push(i); 
        }

        return answer;
    }
};