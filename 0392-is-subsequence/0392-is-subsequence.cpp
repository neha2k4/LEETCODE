class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int m=s.size();
        int n=t.size();
        int i=0,j=0;
        while(j!=n)
        {
            if(s[i]==t[j])
            {
                i++;
                j++;
                
            }
            else{
                j++;
            }
        }
        if(i==m)
        {
            return true;
        }
        else{
            return false;
        }

    }
};