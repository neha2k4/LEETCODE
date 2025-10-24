class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        vector<int>ans(nums1.size());
        unordered_map<int,int>mpp;
        stack<int>s;
        for(int i=n-1;i>=0;i--)
        {
            while(s.size()>0 && s.top()<=nums2[i])
            {
                s.pop();
            }
            if(s.empty())
            {
                mpp[nums2[i]]=-1;
            }
            else{
                mpp[nums2[i]]=s.top();
            }
            s.push(nums2[i]);
        }
        for(int i=0;i<nums1.size();i++)
        {
            ans[i]=mpp[nums1[i]];
        }

        
        return ans;
    }
};