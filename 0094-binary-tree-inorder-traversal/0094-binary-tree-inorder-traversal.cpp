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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* node=root;
        stack<TreeNode*> st;
        while(true)
        {
            if(node==nullptr)
            {
                if(st.empty())
                {
                    break;
                }
                node=st.top();
                ans.push_back(node->val);
                st.pop();
                node=node->right;
            }
            else
            {
                st.push(node);
                node=node->left;
            }
        }
        return ans;
    }
};