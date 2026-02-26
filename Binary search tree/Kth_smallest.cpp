// Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

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
    void preorder(TreeNode* root,vector<int>& t,int k){
        if(!root) return;
        preorder(root->left,t,k);
        t.push_back(root->val);
        if(t.size() == k) return;
        preorder(root->right,t,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
        preorder(root,ans,k);
        cout<<ans[k-1];
        if(ans.size()>=k) return ans[k-1];
        return -1;
    }
};