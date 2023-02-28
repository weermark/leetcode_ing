# 303. Range Sum Query - Immutable

[leetcode題目連結](https://leetcode.com/problems/range-sum-query-immutable/)

定義: 建立一類別 `NumArray`，在初始化時給定一參數陣列 `nums`。呼叫函式 `sumRange` 輸入兩整數參數 `left`、`right`，回傳 `nums` 在兩參數區間內的總和。

## 解題

### 想法一:

做法: 初始化時建立前綴和陣列，呼叫 `sumRange` 時只需要取前綴和陣列的值即可。

程式:
```java
// success
// time:  O(1)
// space: O(n)

// java
class NumArray {

    private int[] preSum;

    public NumArray(int[] nums) {
        preSum = new int[nums.length];
        preSum[0] = nums[0];
        for (int i = 1; i < nums.length; ++i) {
            // preSum[i] 的值是 nums[0 ~ i-1] + nums[i] 的值
            // preSum[i - 1] 的值是 nums[0 ~ i-1]
            preSum[i] = preSum[i - 1] + nums[i];
        }
    }
    
    public int sumRange(int left, int right) {
        if (left == 0)
            return preSum[right];
        else
            // 閉區間 [left, right]，因此總和包含 nums[left] 的值
            return preSum[right] - preSum[left - 1];
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(left,right);
 */
```