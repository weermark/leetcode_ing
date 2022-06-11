# 704. Binary Search

[leetcode題目連結](https://leetcode.com/problems/binary-search/)

解釋:

## 解題

### 想法一:

做法:

程式:

```c++
// success
// time:  O()
// space: O()


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right){
            int mid = (left + right) / 2;
            if(nums[mid] > target)
                right = mid - 1;
            else if(nums[mid] < target)
                left = mid + 1;
            else if(nums[mid] == target)
                return mid;
        }
        return -1;
     }
 };
```

問題:

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


### 網路解一:

```c++

```
-->
