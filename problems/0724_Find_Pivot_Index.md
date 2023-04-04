# 724. Find Pivot Index

[leetcode題目連結](https://leetcode.com/problems/find-pivot-index/)

定義: 給一整數陣列，找出一索引，使得該索引左方元素與右方元素的總和相等 (皆不包刮該數)，回傳該索引，若此索引不存在，則回傳 `-1`。

## 解題

### 想法一:

做法: 前綴和。

程式:
```java
// success
// time:  O(n)
// space: O(n)

class Solution {
    public int pivotIndex(int[] nums) {
        // create preSum, remain index 0 for zero
        int[] preSum = new int[nums.length + 1];
        preSum[0] = 0;
        for (int i = 1; i <= nums.length; ++i) {
            preSum[i] = nums[i - 1] + preSum[i - 1];
        }

        int sum = preSum[nums.length];
        for (int i = 0; i < nums.length; ++i) {
            if (sum - preSum[i + 1] == preSum[i]){
                return i;
            }
        }
        return -1;
    }
}
```

<br/>

### 想法二:

做法: 優化想法一，會用到的前綴和可以邊迭代邊計算，而不需用陣列存。

程式:
```java
// success
// time:  O(n)
// space: O(1)

class Solution {
    public int pivotIndex(int[] nums) {
        int sum = 0;
        for (int i : nums) {
            sum += i;
        }

        int currentSum = 0;
        for (int i = 0; i < nums.length; ++i) {
            currentSum += nums[i];
            if (sum - currentSum == currentSum - nums[i]) {
                return i;
            }
        }
        return -1;
    }
}
```