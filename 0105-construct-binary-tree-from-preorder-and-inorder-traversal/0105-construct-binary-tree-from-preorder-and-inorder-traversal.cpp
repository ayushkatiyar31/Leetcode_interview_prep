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
 
    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, 
                             int inStart, int inEnd, int& preIndex) {
     
        if(inStart > inEnd) {
            return NULL;
        }
        
        TreeNode* root = new TreeNode(preorder[preIndex]);
        int pos = find(inorder, preorder[preIndex], inStart, inEnd);
        preIndex++;
         
        root->left = buildTreeHelper(preorder, inorder, inStart, pos - 1, preIndex);
        root->right = buildTreeHelper(preorder, inorder, pos + 1, inEnd, preIndex);
        
        return root;
    }
 
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int preIndex = 0; 
        return buildTreeHelper(preorder, inorder, 0, n - 1, preIndex);
    }
};