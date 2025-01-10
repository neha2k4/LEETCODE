class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> ind;
        for (int i = 0; i < nums1.size(); i++) {
            ind[nums1[i]] = i;
        }
        stack<int> remains;
        for (int i : nums2) {
            while (!remains.empty() and i > remains.top()) {
                nums1[ind[remains.top()]] = i;
                remains.pop();
            }
            if (ind.find(i) != ind.end()) {
                remains.push(i);
            }
        }
        while (!remains.empty()) {
            nums1[ind[remains.top()]] = -1;
            remains.pop();
        }
        return nums1;
    }
};