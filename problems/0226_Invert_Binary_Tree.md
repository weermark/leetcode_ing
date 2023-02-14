# 226. Invert Binary Tree

[leetcode題目連結](https://leetcode.com/problems/invert-binary-tree/)

定義: 輸入一二元樹，鏡像翻轉二元樹，回傳翻轉後的根節點。

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

做法: 在後序位置交換左節點和右節點，這樣會在遍歷到樹底後從下往上逐步交換。用前序也可以。

程式:

```c++
// success
// time:  O(v)
// space: O(h)

// java
class Solution {
    public void exchangeSubNode(TreeNode root){
        TreeNode tmp = root.left;
        root.left = root.right;
        root.right = tmp;
    }
    public void invert(TreeNode root){
        if(root == null)    return;
        invert(root.left);
        invert(root.right);
        exchangeSubNode(root);
        return;
    }
    public TreeNode invertTree(TreeNode root) {
        invert(root);
        return root;
    }
}
```

省思: 後序位置可以做到自底向上。