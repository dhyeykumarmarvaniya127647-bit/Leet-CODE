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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        if (pre.empty()) return nullptr;
        TreeNode* root = new TreeNode(pre[0]);
        if (pre.size() == 1) return root;

        int i = find(post.begin(), post.end(), pre[1]) - post.begin();

        vector<int> lpre(pre.begin()+1, pre.begin()+i+2);
        vector<int> lpost(post.begin(), post.begin()+i+1);

        root->left = constructFromPrePost(lpre, lpost);

        vector<int> rpre(pre.begin()+i+2, pre.end());
        vector<int> rpost(post.begin()+i+1, post.end()-1);

        root->right = constructFromPrePost(rpre, rpost);
        return root;
    }
};