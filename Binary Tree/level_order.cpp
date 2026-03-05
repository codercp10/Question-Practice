// Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

// For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

// The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

// Return the vertical order traversal of the binary tree.


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
    void solve(TreeNode* root, int x,int y,map<int,vector<pair<int,int>>>& m){
        if(!root) return ;
        m[x].push_back(make_pair(y,root->val));
        solve(root->left,x-1,y+1,m);
        solve(root->right,x+1,y+1,m);
        
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int,vector<pair<int,int>>> m;
        solve(root,0,0,m);
        for(auto& [x,vec]: m){
            sort(vec.begin(),vec.end());
            vector<int> temp;
            for(int i = 0;i<vec.size();i++){
                temp.push_back(vec[i].second);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};