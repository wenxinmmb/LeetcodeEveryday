// https://leetcode.com/problems/maximum-average-subtree/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    double largest;
public:
    double maximumAverageSubtree(TreeNode* root) {
        largest = 0;
        int c;
        double n;
        AvgTree(root, c, n);
        return largest;
    }
    
    void AvgTree(TreeNode* root, int& num_child, double& sum){
        num_child = 0;
        sum = 0;
        if(!root){
            return;
        }
        
        int num;
        double summ;
        if(root->left){
            AvgTree(root->left, num, summ);
            num_child += num;
            sum += summ;
        }
        if(root->right){
            AvgTree(root->right, num, summ);
            num_child += num;
            sum +=summ;
        }
        num_child += 1;
        sum += root->val;
        largest = max(largest,sum/num_child);
        return;
    }
    
};