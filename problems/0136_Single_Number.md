# 136. Single Number

[leetcode題目連結](https://leetcode.com/problems/single-number/description/)

定義: 給一整數陣列，其中數字皆成對出現，只有一數字只出現一次，回傳只出現過一次的數字。

## 解題

### 想法一:

做法: 異或運算。兩相等數異或運算為 0，最後只會留下只出現一次的數字。

程式:
```java
// success
// time:  O(n)
// space: O(1)

class Solution {
    public int singleNumber(int[] nums) {
        int res = 0;
        for (int i : nums) {
            res ^= i;
        }
        return res;
    }
}
```