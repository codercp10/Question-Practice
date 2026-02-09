// A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

// The path sum of a path is the sum of the node's values in the path.

// Given the root of a binary tree, return the maximum path sum of any non-empty path.

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
    int solve(TreeNode* root, int& ans) {
        if (!root) return 0;
        int left = max(solve(root->left, ans), 0);
        int right = max(solve(root->right, ans), 0);
        ans = max(ans, left + right + root->val);
        return max(left, right) + root->val;
    }
    
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;  
        solve(root, ans);
        return ans;
    }
};