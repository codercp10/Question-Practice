// Given a binary tree, determine if it is height-balanced.

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
    int height(TreeNode* root,int h){
        int ans=0;
        if(!root) return h;
        ans = max(height(root->left,h+1),ans);
        ans = max(height(root->right,h+1),ans);
        return ans;
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        if(!root->right && !root->left) return true;
        cout<<height(root->left,0);
        int lh = height(root->left,0);
        int rh = height(root->right,0);
        if(abs(lh-rh) <=1 && isBalanced(root->left) && isBalanced(root->right)) return true;
        return false;
    }
};