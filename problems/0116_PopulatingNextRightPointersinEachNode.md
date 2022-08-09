# 題目: 

[leetcode題目連結]()

定義:

解釋: 

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

做法:

程式:

```c++
// error: 
// fail:
// reason: 


```

問題:

<br/>

### 想法二:

做法:

程式:

```c++
// success
// time:  O()
// space: O()

// java
class Solution {
    private Queue<Node> q;
    public void bfs(){
        while(!q.isEmpty() && q.peek() != null){
            int sz = q.size();
            Node preNode = q.poll();
            for(int i = 1; i < sz; ++i){
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

省思: 