# 746. Min Cost Climbing Stairs

[leetcode題目連結](https://leetcode.com/problems/min-cost-climbing-stairs/)

解釋: 第i個階梯有相對應的花費cost[i]。可以從第0階或第1階開始爬，每次可爬一階或兩階，每經過第i階就必須花費cost[i]，求到第cost.size()階的最小花費。

## 解題

### 想法一:

做法: 用dp，dp[i]為第i階所需花費。

初始化:

```
dp[0] = cost[0]
dp[1] = cost[1]
```

狀態轉移方程:

```
dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i]
```

程式:

```c++
// success
// time:  O(n)
// space: O(n)

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int len = cost.size();
        vector<int> dp(len, 0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i = 2; i < len; i++){
            // 第i階花費
            dp[i] += cost[i];
            // 到第i階的最小花費
            dp[i] += dp[i - 1] < dp[i - 2] ? dp[i - 1] : dp[i - 2];
        }
        // 第len階才是要求的梯數，而當階無花費，可選從前一階或前兩階中，選比較小花費的梯數爬上來
        return dp[len - 1] < dp[len - 2] ? dp[len - 1] : dp[len - 2];
    }
};
```

問題: 第i-3階的值在計算第i階時不會再用到。換句話說，for每次迭代時只會用到兩個陣列的值，計算完當階最小花費後，也只需要兩個空間存i和i-1階的最小花費，因此實際只需要兩個空間則可。

<br/>

### 想法二:

做法: 優化想法一。

程式:

```c++
// success
// time:  O(n)
// space: O(1)

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int dp[2];
        dp[0] = cost[0];
        dp[1] = cost[1];
        int tmp;
        for(int i = 2; i < cost.size(); i++){
            // 保存dp[1] (第i-1階的最小花費)
            tmp = dp[1];
            // dp[1]的值改為第i階的最小花費
            dp[1] = (dp[0] < dp[1]) ? dp[0] : dp[1];
            dp[1] += cost[i];
            // dp[0]的值改為第i-1階的最小花費
            dp[0] = tmp;
        }
        return (dp[0] < dp[1]) ? dp[0] : dp[1];
    }
};
```

省思: 

<br/>

<!--
### 網路解一:

```c++

```
-->
