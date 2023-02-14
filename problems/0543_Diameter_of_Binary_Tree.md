# 543. Diameter of Binary Tree 

[leetcode題目連結](https://leetcode.com/problems/diameter-of-binary-tree/)

定義: 輸入一二元數根節點，回傳該樹最長直徑。

解釋: 最長直徑是樹中任兩點的最長距離，可不經過根節點。

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

做法: 左右子樹深度相加最大即是最長直徑，而該節點即是最長直徑的根節點。每一節點都可能是根節點，因此每個節點都要判斷到。

程式:

```c++
// success
// time:  O(v)
// space: O(h)

class Solution {
    private int res = 0;
    public int maxSubTreeDiameter(TreeNode root){
        if(root == null){
            return 0;
        }
        int leftDiameter = maxSubTreeDiameter(root.left);
        int rightDiameter = maxSubTreeDiameter(root.right);
        res = Math.max(res, (leftDiameter + rightDiameter));
        return (leftDiameter > rightDiameter ? leftDiameter : rightDiameter) + 1;
        
    }
    public int diameterOfBinaryTree(TreeNode root) {
        maxSubTreeDiameter(root);
        return res;
    }
}
```

省思: 這題要從底下為 0 向上加。
<!--
<br/>

### 想法二:

做法:

程式:

```c++
// success
// time:  O()
// space: O()


```

省思: 
-->