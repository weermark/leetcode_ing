# 547. Number of Provinces

[leetcode題目連結](https://leetcode.com/problems/number-of-provinces/description/)

定義: 給一相鄰矩陣，元素 0 沒相連，1 為有相連。回傳連通分量數。

## 解題

### 想法一:

做法: 深度遍歷。

程式:
```java
// success
// time:  O(n ^ 2)
// space: O(n)
// 其中 n 為節點數

class Solution {
    private boolean[] visited;

    public int findCircleNum(int[][] isConnected) {
        int len = isConnected.length;
        visited = new boolean[len];
        int count = 0;

        for (int i = 0; i < len; ++i) {
            if (!visited[i]) {
                dfs(i, isConnected);
                ++count;
            }
        }

        return count;
    }

    private void dfs(int node, int[][] isConnected) {
        visited[node] = true;

        for (int i = 0; i < isConnected[node].length; ++i) {
            if (!visited[i] && isConnected[node][i] == 1) {
                dfs(i, isConnected);
            }
        }
    }
}
```