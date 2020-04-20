
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def getPreIndex(self): 
        return self.constructTreeUtil.preIndex 
    def incrementPreIndex(self): 
        self.constructTreeUtil.preIndex += 1

    def constructTreeUtil(self,pre, low, high, size): 
        if( getPreIndex() >= size or low > high): 
            return None
        root = Node(pre[getPreIndex()]) 
        self.incrementPreIndex() 
        if low == high : 
            return root 
        for i in range(low, high+1): 
            if (pre[i] > root.val): 
                break
        root.left = self.constructTreeUtil(pre, getPreIndex(), i-1 , size) 
        root.right = self.constructTreeUtil(pre, i, high, size) 
        return root 

    def constructTree(self, pre): 
        size = len(pre) 
        constructTreeUtil.preIndex = 0
        return self.constructTreeUtil(pre, 0, size-1, size) 


    def bstFromPreorder(self, preorder: List[int]) -> TreeNode:
        return self.constructTree(preorder)
