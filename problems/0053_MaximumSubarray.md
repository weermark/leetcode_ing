# 53. Maximum Subarray

[leetcode題目連結](https://leetcode.com/problems/maximum-subarray/)

解釋: 回傳參數陣列 nums 中子陣列的最大加總值。

## 解題

### 想法一:

做法: 只要 sum 為正，總和皆有可能為最大值。一旦 sum 小於 0，就應捨棄前面的負總和，從 0 開始繼續計算。

程式:

```c++
// success
// time:  O(n)
// space: O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = -INT_MAX;
        int sum = 0;
        for(int i = 0; i < nums.size(); ++i){
            sum += nums[i];
            if(sum < 0){
                // note: ele in nums may be all nagetive
                res = (res < sum) ? sum : res;
                sum = 0;
                continue;
            }
            if(res < sum){
                res = sum;
            }
        }
        return res;
    }
};
```

省思: 要注意 nums 可能全為負數。

<br/>

### 想法二:

做法: 優化想法一，調換兩個 if 的位置，可減少程式。

程式:

```c++
// success
// time:  O(n)
// space: O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        int sum = 0;
        for(int i = 0; i < nums.size(); ++i){
            sum += nums[i];
            if(res < sum){
                res = sum;
            }
            if(sum < 0){
                sum = 0;
            }
        }
        return res;
    }
};
```

省思: 把握總和為負即捨棄的概念就可以完成了。

<br/>

### 網路解一:

dp

```c++
int maxSubArray(vector<int>& nums) {
    int sum = nums[0], max_sum = nums[0];
    for(int i = 1; i < nums.size(); i++){
        sum = max(nums[i], sum + nums[i]);
        if(sum > max_sum){
            max_sum = sum;
        }
    }
    return max_sum;
}
```
