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

    pair<int, int> dfs(TreeNode* root, int& valid){
        if(!root)
            return {0, 0};

        pair<int, int> leftSubtree = dfs(root->left, valid);
        pair<int, int> rightSubtree = dfs(root->right, valid);

        int sum = root->val + leftSubtree.first + rightSubtree.first;
        int count = 1 + leftSubtree.second + rightSubtree.second;

        if(sum / count == root->val)
            valid++;

        return {sum, count};
    }

    int averageOfSubtree(TreeNode* root) {
        int valid = 0;
        dfs(root, valid);
        return valid;
    }

};