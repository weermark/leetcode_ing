# 283. Move Zeroes

[leetcode題目連結](https://leetcode.com/problems/move-zeroes/)

解釋: 給參數陣列 nums，把 0 移動到陣列末端。

## 解題

### 想法一:

做法: 雙指針。兩指針 slow 與 fast，fast 在每次 while 循環前會往前，而 slow 遇到 0 則不往前。在每次 while 循環前把 nums[fast] 賦予 nums[slow]，使得元素為 0 的位置 (也就是 slow 停下的位置)，會被後方非 0 的元素覆蓋 (fast 所在位置) 。第一個 while 結束後，slow 所停留的位置後方的元素應全被覆寫為 0，因此再用一個 while 執行覆蓋。

程式:

```c++
// success
// time:  O(n)
// space: O(1) 

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // 指針初始為 nums 第一個元素的索引
        int slow = 0;
        int fast = 0;
        while(fast < nums.size()){
            nums[slow] = nums[fast];
            // nums[slow] 為 0，則讓 slow 停下，在下一次循環會把此 0 覆蓋
            if(nums[slow] != 0){
                ++slow;
            }
            // fast 不斷往前
            ++fast;
        }
        // 覆寫應為 0 而非 0 的位置
        while(slow < nums.size()){
            nums[slow] = 0;
            ++slow;
        }
        return;
    }
};
```

省思: 類似移除元素。

<!--

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
