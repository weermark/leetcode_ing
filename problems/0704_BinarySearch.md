# 704. Binary Search

[leetcode題目連結](https://leetcode.com/problems/binary-search/)

定義: 給定參數陣列 nums 與目標值 target，回傳 target 在 nums 中的索引。

解釋: 用二元搜尋。

## 解題

### 想法一:

做法: 二元搜尋，左閉右閉。

程式:

```c#
// success
// time:  O(lgn)
// space: O(1)

public class Solution {
    public int Search(int[] nums, int target) {
        // 左閉右閉
        int left = 0;
        int right = nums.Length - 1;
        // left 與 right 相等有意義
        while(left <= right){
            int middle = (left + right) / 2;
            if(nums[middle] > target){
                right = middle - 1;
            }
            else if(nums[middle] < target){
                left = middle + 1;
            }
            else if(nums[middle] == target){
                return middle;
            }
        }
        // target 不存在
        return -1;
    }
}
```

省思: 要多次確認是否符合左閉右閉的要求，比如:
* right 初始賦值為 len-1
* while 判斷， left 可以等於 right
* target 較小時，right 覆寫為 middle-1