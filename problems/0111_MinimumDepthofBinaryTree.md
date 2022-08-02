# 題目: 

[leetcode題目連結]()

解釋:

## 解題

### 想法一:

做法:

程式:

```c++
// success
// time:  O(lgn)
// 滿枝二元樹，底層最多同時會有 2 ^ lgn-1，也就是 (n/2) - 1 個 TreeNode 儲存在 queue 裡
// space: O(n)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        // init
        if(root == nullptr) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int step = 1;
        // start BFS
        while(!q.empty()){
            int curSize = q.size();
            for(int i = 0; i < curSize; ++i){
                TreeNode* cur = q.front();
                q.pop();
                // the node is leaf, return
                if(cur->left == nullptr && cur->right == nullptr){
                    return step;
                }
                // left node is not null, add it to queue
                if(cur->left != nullptr){
                    q.push(cur->left);
                }
                // right node is not null, add it to queue
                if(cur->right != nullptr){
                    q.push(cur->right);
                }
            }
            // next round will traverse next level, so step counter plus one
            ++step;
        }
        return step;
    }
};
```

省思: BFS 有層級遍歷的特性。

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

<br/>

-->

### 網路解一:

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

 // java
class Solution {
    public int minDepth(TreeNode root) {
        // 當 root 為 leaf，回傳 0
        if (root == null) return 0;
        int l = minDepth(root.left);
        int r = minDepth(root.right);
        if (l == 0 || r == 0) {
            return l + r + 1;
        } else {
            return Math.min(l, r) + 1;
        }
    }
}
```

利用遞迴遍歷樹，短小乾淨。

