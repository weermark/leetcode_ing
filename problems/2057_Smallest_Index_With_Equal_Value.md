# 2057. Smallest Index With Equal Value 

[leetcode題目連結](https://leetcode.com/problems/smallest-index-with-equal-value/description/)

定義: 給一整數陣列，回傳該陣列中索引最小且該索引 `mod 10` 的值與元素值相等。

## 解題

### 想法一:

做法: 要求最小的索引，那只要從索引 0 開始迭代，第一個符合 mod 條件的索引即為答案。

程式:
```java
// success
// time:  O(n)
// space: O(1)

class Solution {
    public int smallestEqual(int[] nums) {
        for (int i = 0; i < nums.length; ++i) {
            if (i % 10 == nums[i])  return i;
        }
        return -1;
    }
}
```