# 1049. Last Stone Weight II

[leetcode題目連結](https://leetcode.com/problems/last-stone-weight-ii/)

解釋: 回傳參數陣列 stones 分兩組後的最小加總值差距。

## 解題

### 想法一:

做法: 使用 01 背包問題的解法。把 stones 分成兩組，加總較小的組別其加總值最大為 sum / 2，因此在 sum / 2 的重量下使用動態規劃求加總值較小的組別的最大加總值，再把加總值較大的組別的加總值減去加總值較小的組別的加總值，即可得到兩組差距，此差距極微答案。

程式:

```c++
// success
// m = sum / 2, n = stones.size()
// time:  O(m * n)
// space: O(m)

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for(int i : stones){
           sum += i; 
        } 
        // 如果 sum 為奇數，target 為整數且向下取整，因此 target 的值必小於 sum / 2 
        // 也就是說，dp[target] 的值是兩組石頭中重量加總較小的那一組
        int target = sum / 2;
        
        vector<int> dp(target + 1, 0);
        for(int i = 0; i < stones.size(); i++){
            for(int j = target; j >= stones[i]; j--){
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }
        return (sum - dp[target]) - dp[target];
    }
};
```

省思: 設定 target 的值要三思。

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
