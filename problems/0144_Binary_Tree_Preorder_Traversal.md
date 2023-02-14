# 144. Binary Tree Preorder Traversal

[leetcode題目連結]()

定義: 輸入一二元樹根節點，回傳前序遍歷。

解釋: 前序遍歷的時間點是在剛進入節點時。

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

### 想法二:

做法: 在前序位置把該點的值加入容器。

程式:

```c++
// success
// time:  O(v)
// space: O(h)

// java
class Solution {
    List<Integer> list;
    public void traverse(TreeNode root){
        if(root == null){
            return;
        }
        list.add(root.val);
        traverse(root.left);
        traverse(root.right);
        return;
    }
    public List<Integer> preorderTraversal(TreeNode root) {
        list = new LinkedList<>();
        traverse(root);
        return list;
    }
}
```

省思: 掌握前中後序的三個時間點即可快速完成。