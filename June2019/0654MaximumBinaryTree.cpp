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
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return makeTree(nums, 0, nums.size()-1);
    }
    
    TreeNode* makeTree(vector<int>& nums, int start, int end){
        int maxm = nums[start];
        int ind = start;
        for(int i = start + 1; i<= end; i++){
            if(nums[i] > maxm){
                maxm = nums[i];
                ind = i;
            }
        }
        TreeNode* curNode = new TreeNode(maxm);
        if(ind != start){
            curNode -> left = makeTree(nums, start, ind - 1);
        }
        if(ind != end){
            curNode -> right = makeTree(nums, ind + 1, end);
        }
        return curNode;
    }
};