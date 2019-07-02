// https://leetcode.com/problems/flip-binary-tree-to-match-preorder-traversal
class Solution {
public:
    int i = 0;
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int> res;
        if(dfs(root,voyage,res)){
            return res;
        }
        return vector<int>{-1};
    }
    
    bool dfs(TreeNode* root, vector<int>&voyage , vector<int>& res){
        if(!root)
            return true;
        if(root -> val != voyage[i]){
            return false;
        }
        i++;
        if(root->left && root->left->val != voyage[i]){
            res.push_back(root->val);
            TreeNode *temp = root->left;
            root->left = root->right;
            root->right = temp;
        }
        return dfs(root->left,voyage,res) && dfs(root->right,voyage,res);
    }
};