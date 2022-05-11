70. Climbing Stairs

[leetcode題目連結](https://leetcode.com/problems/climbing-stairs/)

解釋: 每次可以爬一階或兩階階梯，求爬到第 n 階階梯有幾種方法。

## 解題

### 想法一:

做法: 用遞迴，遞迴公式如下。

遞迴公式:

```
climbStairs(1) = 1          // 爬到第一階只有一種方法
climbStairs(2) = 2          // 爬道第二階有兩種方法 (1+1 or 2)
climbStairs(n) = climbStairs(n - 1) + climbStairs(n - 2)        // 第 n 階一定是從第 n-1 階或 n-2 階爬上來
```

程式:

```c++
// fail: Time Limit Exceeded
// reason: when n = 44, exceed time limit

class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2)  return n;
        return (climbStairs(n - 1) + climbStairs(n - 2));
    }
};
```

問題: 用遞迴重複太多次計算

<br/>

### 想法二:

做法: 用 dp，dp[i] 代表爬到第 i 階的爬法數，狀態轉移方程如下。

初始化:

```
dp[1] = 1
dp[2] = 2
```

狀態轉移方程:

```
dp[i] = d[i - 1] + dp[i - 2]
```

程式:

```c++
// success
// time:  O(n)
// space: O(n)

class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2)  return n;
        int dp[n + 1];
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <= n; i++){
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
```

省思: 

<br/>

### 想法三:

做法: 優化想法二。

程式:

```c++
// success
// time:  O(n)
// space: O(1)

class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2)  return n;
        int dp[3];
        dp[1] = 1;
        dp[2] = 2;
        int tmp;
        for(int i = 3; i <= n; i++){
            tmp = dp[2];
            dp[2] = dp[1] + dp[2];
            dp[1] = tmp;
        }
        return dp[2];
    }
};
```

省思: 

<!--
### 網路解一:

```c++

```
-->
