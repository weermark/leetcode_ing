# 104. Maximum Depth of Binary Tree

[leetcode題目連結](https://leetcode.com/problems/maximum-depth-of-binary-tree/)

解釋: 回傳參數二元數的最大深度。

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

做法: 遍歷二元數，在進入新節點時深度增加，離開時減少。如有更大的深度，就更新 res。

程式:

```java
// error: Runtime Error
// input: []

// java
class Solution {
    private int res = 0;
    public void traverse(TreeNode node, int depth){
        if(node == null)    return;
        // 進入新節點，深度加一
        ++depth;
        // 比較 res 與更新後的深度何者較大
        res = Math.max(res, depth);
        traverse(node.left, depth);
        traverse(node.right, depth);
        // 退出節點，深度減一
        --depth;
        return;
    }
    
    public int maxDepth(TreeNode root) {
        // 遍歷 root 左子樹
        traverse(root.left, 1);
        // 遍歷 root 右子樹
        traverse(root.right, 1);
        return res;
    }
}
```

問題: root 為 null 時沒有例外處理。

<br/>

### 想法二 (更正想法一):

做法: 加上例外處理

程式:

```java
// error: Wrong Answer
// Input: [0]

// java
class Solution {
    private int res = 0;
    public void traverse(TreeNode node, int depth){
        if(node == null)    return;
        // 進入新節點，深度加一
        ++depth;
        // 比較 res 與更新後的深度何者較大
        res = Math.max(res, depth);
        traverse(node.left, depth);
        traverse(node.right, depth);
        // 退出節點，深度減一
        --depth;
        return;
    }
    
    public int maxDepth(TreeNode root) {
        if(root == null)    return 0;
        // 遍歷 root 左子樹
        traverse(root.left, 1);
        // 遍歷 root 右子樹
        traverse(root.right, 1);
        return res;
    }
}
```

問題: res 初始值設定有誤。

<br/>

### 想法三 (更正想法二):

做法: res 初始值設為 1。

程式:

```java
// success
// time:  O(v)
// space: O(h)

// java
class Solution {
    private int res = 1;
    public void traverse(TreeNode node, int depth){
        if(node == null)    return;
        // 進入新節點，深度加一
        ++depth;
        // 如深度大於 res，更新 res
        res = Math.max(res, depth);
        traverse(node.left, depth);
        traverse(node.right, depth);
        // 退出節點，深度減一
        --depth;
        return;
    }
    
    public int maxDepth(TreeNode root) {
        if(root == null)    return 0;
        // 遍歷 root 左子樹
        traverse(root.left, 1);
        // 遍歷 root 右子樹
        traverse(root.right, 1);
        return res;
    }
}
```

省思: 測資範圍外沒做好例外處理。

### 想法四 (優化想法三):

程式:

```java
// success
// time:  O(v)
// space: O(h)

// java
class Solution {
    private int res = 0;
    private int depth = 0;

    public void traverse(TreeNode node){
        if(node == null){
            // 觸底，如深度大於 res，更新 res
            res = Math.max(res, depth);
            return;
        }
        // 進入新節點，深度加一
        ++depth;
        // 遍歷 root 左子樹
        traverse(node.left);
        // 遍歷 root 右子樹
        traverse(node.right);
        // 退出節點，深度減一
        --depth;
        return;
    }
    
    public int maxDepth(TreeNode root) {
        traverse(root);
        return res;
    }
}
```

### 想法五:

做法: 用分治法，樹的高度是子樹的高度加一。