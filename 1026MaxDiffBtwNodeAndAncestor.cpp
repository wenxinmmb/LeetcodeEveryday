/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/
//TODO: improve memory usage
class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        if(!root)
            return 0;
        
        int small;
        int large;
        return getLongest(root,large,small);
        
    }
    
    int getLongest(TreeNode* node, int& large, int& small){
        if(!node){
            large = INT_MIN;
            small = INT_MAX;
            return 0;
        }
        int l1,l2;
        int r1,r2;
        
        int ldis = getLongest(node->left,l1,l2);
        int rdis = getLongest(node->right,r1,r2);
        int dis = max(ldis,rdis);
        large = max(l1,r1);
        small = min(l2,r2);
        
        int cur = node->val;
        
        int diff1 = 0, diff2 = 0;
        if(large != INT_MIN)
            diff1 = abs(cur-large);
        if(small != INT_MAX)
            diff2 = abs(cur-small);
        
        int diff = max(diff1, diff2);
        
        dis = max(dis,diff);
        large = max(large,cur);
        small = min(small,cur);
        return dis;
    }
};