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

    void traverseSubtree(TreeNode* root, int& count, int& sum){
        if(!root)
            return ;
        
        count += 1;
        sum += root->val;

        traverseSubtree(root->left, count, sum);
        traverseSubtree(root->right, count, sum);
    }

    int averageOfSubtree(TreeNode* root) {
        
        queue<TreeNode*> q;
        q.push(root);

        int valid = 0;
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            cout << node->val << endl;

            int sum = 0, count = 0;
            traverseSubtree(node, count, sum);

            if(sum / count == node->val) valid += 1;
        
            if(node->left)  q.push(node->left);
            if(node->right) q.push(node->right);
        }


        return valid;
    }
};

/*

brute-force: for every node, traverse it's subtree counting nodes and adding vals -> compute average
time:        O(n^2), traversing every node's subtree, which can get large
space:       O(1), only need to store how many nodes in that subtree and the sum of it's nodes

Input: root = [4,8,5,0,1,null,6]
Output: 5
Explanation: 
For the node with value 4: The average of its subtree is (4 + 8 + 5 + 0 + 1 + 6) / 6 = 24 / 6 = 4.
For the node with value 5: The average of its subtree is (5 + 6) / 2 = 11 / 2 = 5.
For the node with value 0: The average of its subtree is 0 / 1 = 0.
For the node with value 1: The average of its subtree is 1 / 1 = 1.
For the node with value 6: The average of its subtree is 6 / 1 = 6.

* return the number of nodes where the value of the node is equal 
to the average of the values in its subtree

*/