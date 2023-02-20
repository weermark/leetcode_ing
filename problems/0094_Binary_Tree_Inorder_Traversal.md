# 94. Binary Tree Inorder Traversal

[leetcode題目連結](https://leetcode.com/problems/binary-tree-inorder-traversal/)

定義: 給一二元樹跟節點，回傳中序遍歷結果。

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
```

## 解題

### 想法一:

做法: 中序遍歷

程式:
```python
// success
// time:  O(v)
// space: O(h)

class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        res = []
        self.inorderUtil(root, res)
        return res

    def inorderUtil(self, node: Optional[TreeNode], res: List[int]) -> None:
        if node != None:
            self.inorderUtil(node.left, res)
            res.append(node.val)
            self.inorderUtil(node.right, res)

```