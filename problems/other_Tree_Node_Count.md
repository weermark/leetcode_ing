# Tree Node Count

定義: 輸入二元樹根節點，回傳二元樹的節點數量。

做法: 分治法。

程式:

```java
// time:  O(v)
// space: O(h)

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

// java
int treeNodeCount(TreeNode root){
	if(root == null)    return 0;
	return treeNodeCount(root.left) + treeNodeCount(root.right) + 1;
}
```