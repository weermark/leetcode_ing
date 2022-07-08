# 53. Maximum Subarray

[leetcode題目連結](https://leetcode.com/problems/maximum-subarray/)

解釋: 回傳參數陣列 nums 中子陣列的最大加總值。

## 解題

### 想法一:

做法:

程式:

```c++
// error: 
// fail:
// reason: 

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = 0;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(sum < 0){
                sum = 0;
            }
            if(sum > res){
                res = sum;
            }
        }
        return res;
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
