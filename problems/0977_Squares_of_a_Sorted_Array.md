# 977. Squares of a Sorted Array

[leetcode題目連結](https://leetcode.com/problems/squares-of-a-sorted-array/)

解釋: 回傳參數陣列 nums 的元素取平方後的新有序陣列。

## 解題

### 想法一:

做法: 雙指針，一個指 nums 的頭，一個指 nums 的尾。當頭元素絕對值大於尾元素絕對值，把頭元素的平方放入新陣列，並把頭指針往後移一個位置。當尾元素絕對值大於頭元素絕對值，把尾元素的平方放入新陣列，並把尾指針往前移一個位置。重複此操作，直到兩個指針指到同一個位置，再把該位置的元素平方放入新陣列。

程式:

```c++
// success
// time:  O(n)
// space: O(n)

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        // push new ele from right of res
        auto iter = res.end() - 1;
        // point to first ele of nums
        auto left = nums.begin();
        // point to last ele of nums
        auto right = nums.end() - 1;
        while(left != right){
            if(abs(*left) >= abs(*right)){
                *iter-- = (*left) * (*left++);
            }
            else if(abs(*left) < abs(*right)){
                *iter-- = (*right) * (*right--);
            }
        }
        // important
        *iter = (*left) * (*left);
        return res;
    }
};
```

省思: 要注意當兩個指針指向同一位置時，while 會結束，所以還要再把同位置的元素取平方後放入新陣列。

<br/>

<!--

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
