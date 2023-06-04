# 112. Path Sum

[leetcode題目連結](https://leetcode.com/problems/path-sum/description/)

定義: 給一二元樹的根節點及目標值，回傳該二元樹是否有一從根到葉的路徑，使得該路徑節點的值總和等於目標值。 

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

做法: 遍歷二元樹，到葉節點時判斷是否相等即可。須注意葉節點必須 `沒有左右子節點`。

程式:
```java
// success
// time:  O(n)
// space: O(h)


class Solution {
    public boolean hasPathSum(TreeNode root, int targetSum) {
        if (root == null)   return false;
        return traverse(root, targetSum);
    }

    private boolean traverse(TreeNode root, int sum) {
        // 空節點
        if (root == null)   return false;
        // 葉節點
        if (root.left == null && root.right == null) {
            return root.val == sum;
        }
        sum -= root.val;
        return (traverse(root.left, sum) || 
                traverse(root.right, sum));
    }
}
```