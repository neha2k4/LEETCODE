class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int>prefixcommonarray(n);
        unordered_set<int>hash1,hash2;
        for(int i=0;i<n;i++)
        {
            hash1.insert(A[i]);
            hash2.insert(B[i]);
            int cnt=0;
            for(auto j:hash1)
            {
                if(hash2.count(j))
                {
                    cnt++;
                }
            }
            prefixcommonarray[i]=cnt;
        }
        return prefixcommonarray;
    }
};