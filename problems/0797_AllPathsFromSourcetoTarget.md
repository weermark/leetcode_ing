# 797. All Paths From Source to Target

[leetcode題目連結](https://leetcode.com/problems/all-paths-from-source-to-target/)

解釋: 給一有向無環圖 (相鄰矩陣實現)，回傳 0 到 n-1 的所有路徑。

輸入範例: 
graph = [[1,2],[3],[3],[]]

index   node
0       -> 1 ->2
1       -> 3
2       -> 3
3

## 解題

### 想法一 (參考網路解):

做法:

程式: 無環，用 DFS 遍歷即可。

```java
// success
// 還沒學
// time:  O()
// space: O()

// java
class Solution {
    List<List<Integer>> res = new LinkedList<>();
    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        LinkedList<Integer> path = new LinkedList<>();
        DFSTraverse(graph, 0, path);
        return res;
    }
    
    public void DFSTraverse(int[][] graph, int node, LinkedList<Integer> path){
        path.add(node);
        if(node == graph.length - 1){
            // 注意回傳新複製的 path，不然存在 res 的都會是同一個實體。
            res.add(new LinkedList<>(path));
        }
        for(int i: graph[node]){
            DFSTraverse(graph, i, path);
        }
        path.removeLast();
    }
}
```

省思: 可用 foreach 實現 DFS 中 stack 概念。

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

<!--
### 網路解一:

```c++

```
-->
