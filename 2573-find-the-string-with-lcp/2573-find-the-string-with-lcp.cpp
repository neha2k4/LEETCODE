class Solution {
public:
    // First of all check lcp matrix is valid or not? If not return empty string
    bool isLcpValid(vector<vector<int>>&lcp)
    {
        /*
            observation-1: lcp[0][0]=dimesnion of matrix;
            observation-2: lcp[i][j]=lcp[j][i] as in both case two strings [i to n-1] and [j to n-1] are same.
            observation-3: lcp[i+1][j+1]=lcp[i][j]-1 if lcp[i][j]>0
            observation-4: lcp[i][j]<=n- max(i,j)
        */
        int n=lcp.size();
        if(lcp[0][0]!=n) return false;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
               if(lcp[i][j]!=lcp[j][i]) return false;
               if(lcp[i][j]>n-max(i,j)) return false;
               if(i+1<n && j+1<n && lcp[i][j]>0 &&  lcp[i+1][j+1]!=lcp[i][j]-1) return false;
            }
        }
        return true;
    }
    string findTheString(vector<vector<int>>& lcp) 
    {
        if(isLcpValid(lcp)==false)
        {
          // invalid LCP
            return "";
        } 
        int n=lcp.size();
        char currChar='a';
        vector<char>v(n,'#');
        for(int i=0;i<n;i++)
        {
            if(v[i]!='#')continue;
            if(currChar>'z') 
            {
               // Characters exceeded
                return "";
            }
            for(int j=0;j<n;j++)
            {
                if(lcp[i][j]>0) v[j]=currChar; // if two substrings have lcp>0, means have some common prefix, so s[j]=s[i]
            }
             currChar++;
        }
        string ans="";
        for(auto it:v)ans+=it;
        //check if my builded string is satisfying the given lcp or not.
        for (int i = 0; i < n; ++i) 
        {
            for (int j = 0; j < n; ++j) 
            {
                int v = i + 1 < n && j + 1 < n ? lcp[i + 1][j + 1] : 0;
                v = ans[i] == ans[j] ? v + 1 : 0;
                if (lcp[i][j] != v) return "";
            }
        }

        return ans;
    }
};