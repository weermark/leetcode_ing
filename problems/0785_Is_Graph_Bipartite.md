# 785. Is Graph Bipartite?

[leetcode題目連結](https://leetcode.com/problems/is-graph-bipartite/description/)

定義: 給一無向相鄰矩陣，回傳該圖是否可以被分為兩個集合，使得圖上所有邊各自所連接的兩個節點一定分別在兩個集合內。

## 解題

### 想法一:

做法: 著色配上深度遍歷。

程式:
```java
// success
// time:  O(e + v)
// space: O(e)

class Solution {
    public boolean isBipartite(int[][] graph) {
        // there are three color, which is 0 (no color), 1 (red), -1 (blue)
        int[] colors = new int[graph.length];
        Arrays.fill(colors, 0);

        // graph may not be connected, 
        // so need a for loop to iterate all edge
        for (int i = 0; i < graph.length; ++i) {
            if (colors[i] == 0 && dfs(i, 1, graph, colors)) {
                // if dfs() is true, means graph is bipartite, return false
                return false;
            }
        }
        return true;
    }
    
    private boolean dfs(int u, int adjColor, int[][] graph, int[] colors) {
        // visited
        if (colors[u] != 0)
            return colors[u] == adjColor;
        colors[u] = -adjColor;

        for (int i : graph[u]) {
            if (dfs(i, colors[u], graph, colors))
                return true;
        }
        return false;
    }
}
```