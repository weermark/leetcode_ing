# 116. Populating Next Right Pointers in Each Node

[leetcode題目連結](https://leetcode.com/problems/populating-next-right-pointers-in-each-node/submissions/)

定義: 輸入滿枝二元樹根節點，回傳同高度節點層層相連後的根節點。

解釋: 把同高度的節點用 next 連接起來。

```java
/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}
    
    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
```

## 解題

### 想法一:

做法: bfs，每次取一層出來連接。

程式:

```java
// success
// time:  O(v)
// space: O(2 ^ h) = O(2 ^ log(V+1))
// 最底下那一層的節點數 2 ^ (h-1) = 2 ^ (log(V+1)-1) = 2 ^ log(V+1) - 2 = O(2 ^ log(V+1))

// java
class Solution {
    private Queue<Node> q;
    public void bfs(){
        while(!q.isEmpty() && q.peek() != null){
            int sz = q.size();
            Node preNode = q.poll();
            for(int i = 1; i < sz; ++i){
                // 當 preNode 為不為一層中的最後一個 null
                if(preNode != null){
                    q.offer(preNode.left);
                    q.offer(preNode.right);
                }
                Node curNode = q.poll();
                preNode.next = curNode;
                preNode = curNode;
            }
            q.offer(null);
        }
    }
    public Node connect(Node root) {
        q = new LinkedList<>();
        q.offer(root);
        q.offer(null);
        bfs();
        return root;
    }
}
```

省思: 每一層的開頭要另外處理。

<br/>

### 想法二:

做法: bfs 加上虛擬頭。

程式:

```java
// success
// time:  O(v)
// space: O(2 ^ h)

// java
class Solution {
    private Queue<Node> q;
    public void bfs(){
        while(!q.isEmpty()){
            // 取出虛擬頭
            Node guard = q.poll();
            // 當層的首個節點為 null，結束程式
            if(q.peek() == null)    return;
            // 計算當層節點數
            int sz = q.size();
            // 把虛擬頭放入下一層的頭
            q.offer(guard);
            Node preNode = guard;
            // 把當層節點用 next 相連
            for(int i = 0; i < sz; ++i){
                Node curNode = q.poll();
                preNode.next = curNode;
                preNode = curNode;
                
                q.offer(preNode.left);
                q.offer(preNode.right);
            }
        }
    }
    public Node connect(Node root) {
        q = new LinkedList<>();
        // 虛擬頭會不斷地被放到 queue 的層與層之間，方便操作。
        Node guard = new Node(-1);
        q.offer(guard);
        q.offer(root);
        bfs();
        return root;
    }
}
```

省思: 利用虛擬頭簡化每層首個節點的處理。