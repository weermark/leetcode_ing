# 509. Fibonacci Number

[leetcode題目連結](https://leetcode.com/problems/fibonacci-number/)

解釋: 回傳費氏數列的第n個數。

## 解題

### 想法一:

做法: 用遞迴，依照題目說明給予的遞迴公式寫出遞迴函數。

遞迴公式: 

```
fib(0) = 0
fib(1) = 1
fib(n) = fib(n - 1) + fib(n - 2)
```

程式:

```c++
// success
// time:  O(2^n)
// space: O(n)

class Solution {
public:
    int fib(int n) {
        if(n <= 1)  return n;       // Note: 當n=0時，要回傳0
        return (fib(n - 1) + fib(n - 2));
    }
};
```

問題: 太花時間

<br/>

### 想法二:

做法: 用dp，dp[i]代表第i個費氏數列，狀態轉移方程如下。

初始化:

```
dp[0] = 0
dp[1] = 1
```

狀態轉移方程: 

```
dp[i] = dp[i - 1] + dp[i - 2]
```

程式:

```c++
// success
// time:  O(n)
// space: O(n)

class Solution {
public:
    int fib(int n) {
        if(n <= 1)  return n;
        int dp[n + 1];
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i <= n; i++){
            dp[i] = dp[i - 1] + dp[i - 2];
            // cout << "dp[" << i << "]=" <<  dp[i] << endl;
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
    int fib(int n) {
        if(n <= 1)  return n;
        int dp[2];
        dp[0] = 0;
        dp[1] = 1;
        int tmp;
        for(int i = 2; i <= n; i++){
            tmp = dp[1];
            dp[1] = dp[1] + dp[0];
            dp[0] = tmp;
        }
        return dp[1];
    }
};
```

省思: 

<!--
### 網路解一:

```c++

```
-->
