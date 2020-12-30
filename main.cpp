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
    void GetNextLevelKids(vector<TreeNode *>& kids, vector<vector<int>> &result) {
        vector<int> newKidsData;
        vector<TreeNode *> newKids;
        vector<TreeNode *>::iterator iter = kids.begin();
        vector<TreeNode *>::iterator endIter = kids.end();
        
        for (; iter != endIter; ++iter) {
            TreeNode *node = *iter;
            
            if (node != nullptr) {
                if (node->left != nullptr) {
                    newKidsData.push_back(node->left->val);
                    newKids.push_back(node->left);
                }
                if (node->right != nullptr) {
                    newKidsData.push_back(node->right->val);
                    newKids.push_back(node->right);
                }                
            }
        }
        
        if (newKidsData.size() > 0) {
            GetNextLevelKids(newKids, result);
            result.push_back(newKidsData);
        }
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        
        if (root != nullptr) {
            vector<int> newKidsData;
            vector<TreeNode *> newKids;
            
            newKidsData.push_back(root->val);
            newKids.push_back(root);
            GetNextLevelKids(newKids, result);
            result.push_back(newKidsData);
        }
        
        return result;
    }
};
