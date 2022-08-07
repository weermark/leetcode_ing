# 題目: 

[leetcode題目連結]()

定義:

解釋: 

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
        while(!q.isEmpty){
            int sz = q.size();
            Node preNode = q.offer();
            for(int i = 1; i < sz - 1; ++i){
                // TODO:add node to queue
                
                //
                Node curNode = q.offer();
                preNode.next = curNode;
                preNode = curNode;
            }
            Node lastNode = q.offer();
            lastNode.next = null;
        }
        
        
        
    }
    public Node connect(Node root) {
        q = new LinkedList<>();
        q.poll(root);
        bfs();
        return root;
    }
}
```

省思: 