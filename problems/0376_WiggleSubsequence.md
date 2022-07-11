# 376. Wiggle Subsequence

[leetcode題目連結](https://leetcode.com/problems/wiggle-subsequence/)

解釋: 回傳陣列參數 nums 中，連續元素差在正數和負數中交替的最長子序列。其中，允許刪除陣列中的元素。

## 解題

### 想法一:

做法: 連續兩個或多個遞增或遞減，則不計入。

程式:

```c++
// error: Wrong Answer
/*
input
[0, 0]
*/

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() <= 1)
            return 1;
        
        int res = 2;
        // increase : 1
        // decrease : 0
        bool isWiggle = (nums[1] > nums[0]) ? 1 : 0;
        
        for(int i = 2; i < nums.size(); i++){
            // down and up
            if(nums[i] > nums[i - 1] && isWiggle == 0){
                ++res;
                isWiggle = 1;
            }
            // up and down
            else if(nums[i] < nums[i - 1] && isWiggle == 1){
                ++res;
                isWiggle = 0;
            }
        }
        return res;
    }
};
```

問題: 忽略了連續元素值相等的判斷。

<br/>

### 想法二:

做法: 更正想法一，去除用 bool 判斷遞增遞減，因為除了兩數相等的可能外，還有在賦值時條件較為複雜。更改後，直接用當前兩數相減結果與前兩數相減結果做比較。

程式:

```c++
// success
// time:  O(n)
// space: O(1)

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() <= 1)
            return 1;
        // we will start from index 1, so res set value 1 because of index 0
        int res = 1;
        
        int preDiff = 0;
        int curDiff = 0;
        for(int i = 1; i < nums.size(); i++){
            curDiff = nums[i] - nums[i - 1];
            if((curDiff > 0 && preDiff <= 0) || (curDiff < 0 && preDiff >= 0)){
                // 如果這句寫在 if 外，將導致兩相等數被記入 res (preDiff==0 符合計入條件)
                preDiff = curDiff;
                ++res;
            }
        }
        return res;
    }
};
```

省思: 這題很直觀，但要考慮的額外條件有點多，判斷句要小心寫。

<br/>

<!--
### 網路解一:

```c++

```
-->
