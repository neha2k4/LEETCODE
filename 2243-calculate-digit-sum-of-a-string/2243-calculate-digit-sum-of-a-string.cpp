class Solution {
public:
    string digitSum(string s, int k)
    {
        //brute force approach
        //time complexity: O(n.logn)
        //space complexity: O(n)

        int i;
        string ans="";

        while(1)
        {
            //if string length is less than(or equal to) 'k', returning 's'
            if(s.size()<=k)
                return s;

            //setting 'sum=0' in each iteration to get the current sum
            int sum=0;
            //loop to iterate through the current string
            for(i=0;i<s.size();i++)
            {
                if((i!=0) && (i%k==0))
                {
                    //after every 'k' characters, inserting the 'sum' to 'ans'
                    ans=ans + to_string(sum);
                    //resetting the 'sunm=0'
                    sum=0;
                }
                //adding 'current digit' to sum
                sum=sum+(s[i]-'0');
            }
            //adding last group's sum
            ans=ans + to_string(sum);
            //updating string 's' for next iteration
            s=ans;
            //updating 'ans' to empty string
            ans="";
        }    
    }
};