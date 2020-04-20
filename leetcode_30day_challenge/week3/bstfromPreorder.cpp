/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    TreeNode* newTreeNode(int key){
        TreeNode* node = new TreeNode;
        node->val = key;
        node->left = node->right = nullptr;
        return node;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
         int pIndex = 0;
        return buildTree(preorder, pIndex, INT_MIN, INT_MAX);   
    }

    TreeNode* buildTree(vector<int> &preorder, int& pIndex, int min, int max){
        if (pIndex == preorder.size())
            return nullptr;
        int val = preorder[pIndex];
        if (val < min || val > max)
            return nullptr;
        TreeNode* root = newTreeNode(val);
        pIndex++;
        root->left = buildTree(preorder, pIndex, min, val-1);
        root->right = buildTree(preorder, pIndex, val+1, max);
        return root;
    }

};