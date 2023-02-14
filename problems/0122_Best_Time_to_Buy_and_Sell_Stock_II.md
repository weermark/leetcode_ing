# 122. Best Time to Buy and Sell Stock II

[leetcode題目連結](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/)

解釋: 你一次只能持有一張股票。給參數陣列 prices，prices[i] 代表第 i 天的股票價格，求透過價差所能得的最大利潤。

## 解題

### 想法一:

做法: 遍歷 prices，若後一個元素大於前一個元素，則加入 res。

程式:

```c++
// success
// time:  O(n)
// space: O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for(int i = 1; i < prices.size(); ++i){
            int diff = prices[i] - prices[i - 1];
            if(diff > 0){
                res += diff;
            }
        }
        return res;
    }
};
```

省思: for 迴圈，i 要從 1 開始。

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
