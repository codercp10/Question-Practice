// Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

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
    void solve(TreeNode* root, int level, vector<int>& res){
        if(root == NULL) return;
        if(level == res.size()) res.push_back(root->val);
        solve(root->right,level+1,res);
        solve(root->left,level+1,res);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        solve(root,0,ans);
        return ans;
    }
};

// In the brute force approach, the level order traversal can be used and the right most element of each level can be pushed in the solution.