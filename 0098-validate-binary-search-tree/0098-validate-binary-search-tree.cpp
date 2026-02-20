/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* v) {  
        stack<TreeNode*> s;
        vector <int> ans;

        while (!s.empty() || v != nullptr) {
            while (v != nullptr) {
                s.push(v);
                v = v->left;
            }

            if (ans.size() > 0 && ans[ans.size() - 1] >= s.top()->val) 
                return false;

            ans.push_back(s.top()->val);

            v = s.top()->right;
            s.pop();
        }

        return true;
    }
};