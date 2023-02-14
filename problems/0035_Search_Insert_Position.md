# 35. Search Insert Position

[leetcode題目連結](https://leetcode.com/problems/search-insert-position/)

定義: 輸入整數陣列及目標值，回傳目標值所在之索引值。若索引值不存在，回傳目標值應在之索引值。 

## 解題

### 想法一:

做法: 二分搜索。

程式:
```java
// success
// time:  O(lgn)
// space: O(1)

class Solution {
    public int searchInsert(int[] nums, int target) {
        int left = 0;
        int right = nums.length - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] > target) 
                right--;
            else if (nums[mid] < target)
                left++;
            else if (nums[mid] == target) 
                return mid;
        }
        return left;
    }
}
```