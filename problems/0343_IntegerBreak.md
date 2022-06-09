343. Integer Break

[leetcode題目連結](https://leetcode.com/problems/integer-break/)

解釋: 回傳整數 n 拆開後的最大乘積。

## 解題

### 想法一 (參考網路): 

做法: 從 3 開始往上加到 n，並同時 dp[i] 紀錄整數 i 拆開後的最大乘積。用迴圈取數字小於 i 的所有最大拆解乘積 dp[i - j]  * j (dp[2] 到 dp[i - 1])*j)或 (i - j) * j 的最大值，則此最大值即為數字 i 的拆解最大乘積 dp[i]。

初始化:

```
dp[2] = 1
```

狀態轉移方程: 

```
dp[i] = max(j * (i - j), j * dp[i - j])
```

程式:

```c++
// success
// time:  O(n^2)
// space: O(n)

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 0);
        dp[2] = 1;
        for(int i = 3; i <= n; i++){
            for(int j = 1; j < i - 1; j++){
                dp[i] = max(dp[i], max(dp[i - j] * j, (i - j) * j));
            }
        }
        return dp[n];
    }
};
```

省思: 注意 dp[1] 沒意義，所以在迴圈時要注意不要取到。另外，在想如何把所有可能為最大值的乘積方式列出要費點時間。

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


### 網路解一:

```c++

```
-->
