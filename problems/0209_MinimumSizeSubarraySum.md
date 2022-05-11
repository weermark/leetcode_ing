# 209. Minimum Size Subarray Sum

[leetcode題目連結](https://leetcode.com/problems/minimum-size-subarray-sum/)

解釋: 回傳最小長度子陣列長度，其總和大於或等於 target。

## 解題

### 想法一(參考網路):

做法: 滑動窗口。nums[right..left] 為子陣列，當此子陣列總和大於 target 時，紀錄子陣列長度並 left-1 直到總和小於 target，如此循環直到結束，最後回傳最小子陣列長度。

程式:

```c++
// success
// time:  O(n)
// space: O(1)

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = INT_MAX;
        int sum = 0;
        int count = 0;
        for(int left = 0, right = 0; right < nums.size(); right++){
            sum += nums[right];
            while(sum >= target){
                count = right - left + 1;
                res = min(count, res);
                sum -= nums[left];
                ++left;
            }
        }
        return (res == INT_MAX) ? 0 : res;
    }
};
```

省思: 概念易懂，但轉換程式仍需經驗。此處用 while 用得著實漂亮，如改用 if 會很麻煩。

<br/>

<!--
### 網路解一:

```c++

```
-->
