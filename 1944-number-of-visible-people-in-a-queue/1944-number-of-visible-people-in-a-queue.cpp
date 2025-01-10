class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n=heights.size(),size=0,flag=0,people;
         stack<int>s;
          vector<int>visiblePeople(n,1);
        for(int i=n-1;i>=0;i--)
        {   flag=0;
            people=0;
            while(!s.empty()&&heights[i]>heights[s.top()])
            {
                s.pop();
                flag=1;
                people++;
                size--;
            }
            if(size) people++;
            if(flag) visiblePeople[i]=people;
            s.push(i);
            size++;
        }
       visiblePeople[n-1]=0;
    return visiblePeople;
    }
};