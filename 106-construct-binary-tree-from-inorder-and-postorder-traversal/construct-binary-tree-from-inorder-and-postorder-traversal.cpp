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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        if (inorder.empty() || postorder.empty())
            return NULL;

        TreeNode* root = new TreeNode(postorder.back());

        int i = 0;
        while (inorder[i] != postorder.back())
            i++;

        vector<int> leftInorder(inorder.begin(), inorder.begin() + i);
        vector<int> rightInorder(inorder.begin() + i + 1, inorder.end());

        vector<int> leftPostorder(postorder.begin(),
                                  postorder.begin() + i);

        vector<int> rightPostorder(postorder.begin() + i,
                                   postorder.end() - 1);

        root->left = buildTree(leftInorder, leftPostorder);
        root->right = buildTree(rightInorder, rightPostorder);

        return root;
    }
};