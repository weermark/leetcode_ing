# Tree Node Level

定義: 輸入二元樹根節點，輸出每個節點所在層數。

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

做法: 往下 (子節點) 傳遞非累增變數，每往下傳一個節點就加一。

程式:

```java
// time:  O(v)
// space: O(h)

// call
void treeNodeLevel(TreeNode root){
    if(root == null){
        return;
    }

    treeNodeLevelUtil(root, 1);
}

void treeNodeLevelUtil(TreeNode root, int level){
    if(root == null){
        return;
    }
    
    System.out.println("節點 " + root.val + " 的所在層數為 " + level);

    treeNodeLevelUtil(root.left, level + 1);
    treeNodeLevelUtil(root.right, level + 1);
    return;
}
```