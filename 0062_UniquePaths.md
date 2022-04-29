# 62. Unique Paths

[leetcode題目連結](https://leetcode.com/problems/unique-paths/submissions/)

解釋: 求在m*n的網格中，從起點(左上角[0, 0])走到終點(右下角[m - 1, n - 1])的最短步數有幾種?

## 解題

### 想法一:

做法: 用數學的方式。最上面一排與最左邊一列的方法數皆為1(因為到這些格子只有一種方法)，而其餘格子的方法數計算則是上面一格與左邊一格的方法數加總，舉例如下。 

設m = 3, n = 7，下表中每個格子的值為起點到該點的方法數。

```
起點
1 | 1 | 1 | 1 | 1 | 1 | 1  
--|---|---|---|---|---|---
1 | 2 | 3 | 4 | 5 | 6 | 7  
--|---|---|---|---|---|---
1 | 3 | 6 | 10| 15| 21| 28
                        終點
```

如果用dp的觀點，dp[i][j]為從起點到第[i,j]格的方法數，據此，可以列出如下式子。

初始化
```
dp[0][0..n-1] = 1
dp[0..m-1][0] = 1
```

狀態轉移方程
```
dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
```

程式:

```c++
// success
// time:  O(m*n)
// space: O(m*n)

class Solution {
public:
    int uniquePaths(int m, int n) {
        // array的值皆初始化為1
        vector<vector<int>> path(m, vector<int>(n, 1));
        // 從[1,1]的位置開始，計算到達每個網格的方法數，一直到[m-1,n-1]
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                path[i][j] = path[i-1][j] + path[i][j-1];
            }
        }
        return path[m - 1][n - 1];
    }
};
```

省思: 只要能做到搜尋與遍歷的方法應該都可以用。

<br/>

### 網路解一:

做法: 滾動陣列。每次只記錄一列的值，而利用這列的值推出下一列的值。

```c++
// time:  O(m*n)
// space: O(n)

class Solution {
public:
    int uniquePaths(int m, int n) {
        // 第0列，值皆為1
        vector<int> dp(n, 1);
        /*從第1列開始，dp[i]的值皆可透過dp[i](上面一格) + dp[i - 1](左邊一格)得到*/
        /*dp[0]的值固定為1*/
        for (int j = 1; j < m; j++) {
            for (int i = 1; i < n; i++) {
                dp[i] += dp[i - 1];
            }
        }
        return dp[n - 1];
    }
};
```

<br/>

### 網路解二:

做法: 使用組合數公式。在這m + n - 2個格子的移動中，一定會有m - 1步是往下走，而我們只需求向下走的方法有幾種即可。公式如下。

![](https://latex.codecogs.com/svg.image?C_{n-1}^{m+n-2})

<!--<img src="https://latex.codecogs.com/svg.image?\binom{n}{m}" title="https://latex.codecogs.com/svg.image?\binom{n}{m}" />-->
