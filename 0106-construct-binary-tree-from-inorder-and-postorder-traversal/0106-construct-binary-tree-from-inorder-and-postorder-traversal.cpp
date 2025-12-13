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
    int find(vector<int>& inorder, int target, int start, int end) {
        for(int i = start; i <= end; i++) {
            if(inorder[i] == target)
                return i;
        }
        return -1;
    }

    TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int& postIndex) {
        if(inStart > inEnd)
            return NULL;

        TreeNode* root = new TreeNode(postorder[postIndex]);
        int pos = find(inorder, postorder[postIndex], inStart, inEnd);
        postIndex--;
  
        root->right = buildTreeHelper(inorder, postorder, pos + 1, inEnd, postIndex);
        root->left = buildTreeHelper(inorder, postorder, inStart, pos - 1, postIndex);
        
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        int postIndex = n - 1;  
        return buildTreeHelper(inorder, postorder, 0, n - 1, postIndex);
    }
};