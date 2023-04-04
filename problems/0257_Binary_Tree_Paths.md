# 257. Binary Tree Paths

[leetcode題目連結](https://leetcode.com/problems/binary-tree-paths/description/)

定義: 給二元樹根節點，回傳該樹從根到葉節點的全部路徑。

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

做法: 前序遍歷。

程式:
```java
// success
// time:  O(v)
// space: O(h)


class Solution {
    private List<String> paths;
    private void traverse(TreeNode root, String path) {
        if (root == null)   return;
        // leaf
        if (root.left == null && root.right == null) {
            path += Integer.toString(root.val);
            paths.add(new String(path));
            return;
        }
        path += Integer.toString(root.val) + "->";
        traverse(root.left, path);
        traverse(root.right, path);
    }
    public List<String> binaryTreePaths(TreeNode root) {
        paths = new LinkedList<>();
        String path = "";
        traverse(root, path);
        return paths;
    }
}
```