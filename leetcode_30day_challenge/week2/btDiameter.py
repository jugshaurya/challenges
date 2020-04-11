# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def height(self, root):
        if(root is None):
            return 0;
        lheight = self.height(root.left)
        rheight = self.height(root.right)
        return max(lheight, rheight) + 1
    
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        if(root is None):
            return 0;
        
        lh = self.height(root.left)
        rh = self.height(root.right)
        lans = self.diameterOfBinaryTree(root.left)
        rans = self.diameterOfBinaryTree(root.right)
        return max(lh+rh, lans, rans);



# optimised

class Solution:
    def helper(self, root):
        if(root is None):
            return (0, 0); # diameter, height
        
        ld, lh = self.helper(root.left)
        rd, rh = self.helper(root.right)
        return (max(ld, rd, lh+rh) , max(lh, rh) + 1)
    
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        return self.helper(root)[0]