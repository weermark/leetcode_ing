# 654. Maximum Binary Tree

[leetcode題目連結](https://leetcode.com/problems/maximum-binary-tree/)

定義: 給一整數陣列，回傳最大二元樹的根節點。

解釋: 最大二元樹的父節點為陣列中的最大值，左子節點為父節點值索引左邊的子陣列的最大值，右子節點為父節點值索引右邊的子陣列的最大值。

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

做法: 用遞迴逐步找出子陣列的最大值，並建立節點。遞迴程式可以分兩部分。一，如何得到 root? 二，得到 root 後要做甚麼?

程式:

```java
// success
// time:  O(nlgn)
// space: O(n)

// java
class Solution {
    public TreeNode traverse(int left, int right, int[] nums){
        // 超出邊界
        if(left > right)   return null;
        // 找出 root
        int maxPos = left;
        for(int i = left + 1; i <= right; ++i){
            if(nums[i] > nums[maxPos]){
                maxPos = i;
            }
        }
        // 找 root 的左右子節點
        TreeNode root = new TreeNode(nums[maxPos]);
        root.left = traverse(left, maxPos - 1, nums);
        root.right = traverse(maxPos + 1, right, nums);
        return root;
    }
    
    public TreeNode constructMaximumBinaryTree(int[] nums) {
        return traverse(0, nums.length - 1, nums);
    }
}
```

省思: 

<!--

<br/>

### 想法二:

做法:

程式:

```
// success
// time:  O()
// space: O()


```

省思: 

-->