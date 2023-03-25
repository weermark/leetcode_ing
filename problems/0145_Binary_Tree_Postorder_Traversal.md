# 145. Binary Tree Postorder Traversal 

[leetcode題目連結](https://leetcode.com/problems/binary-tree-postorder-traversal/description/)

定義: 給一二元樹根結點，回傳後序遍歷結果。

解釋: 後序遍歷的時間點是在要離開節點時。

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
```

## 解題

### 想法一:

做法:

程式:
```java
// success
// time:  O(v)
// space: O(h)

class Solution {
    private void postorder(TreeNode node, List<Integer> res) {
        if (node == null) return;
        postorder(node.left, res);
        postorder(node.right, res);
        res.add(node.val);
    }

    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> res = new LinkedList<Integer>();
        postorder(root, res);
        return res;
    }
}
```