# 62. Unique Paths

[leetcode題目連結](https://leetcode.com/problems/unique-paths/submissions/)

解釋: 求在m*n的網格中，從起點(左上角[0, 0])走到終點(右下角[m-1, n-1])的最短步數有幾種?

## 解題

### 想法一:

做法: 用數學的方式。最上面一排與最左邊一列的方法數皆為1，而其餘格子的方法數計算則是上面一格與左邊一格的方法數加總，舉例如下。 

當m=3, n=7，表中每個位置的值為起點到該點的方法數。

```
起點
1 | 1 | 1 | 1 | 1 | 1 | 1  
--|---|---|---|---|---|---
1 | 2 | 3 | 4 | 5 | 6 | 7  
--|---|---|---|---|---|---
1 | 3 | 6 | 10| 15| 21| 28
                        終點
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
        // 從[1,1]的位置開始，計算到每個網格的方法數，一直到[m-1,m-1]
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                path[i][j] = path[i-1][j] + path[i][j-1];
            }
        }
        return path[m - 1][n - 1];
    }
};
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


```

省思: 

<br/>

<!--
### 網路解一:

```c++

```
-->
