# 27. Remove Element

[leetcode題目連結](https://leetcode.com/problems/remove-element/)

解釋: 回傳參數陣列 nums 移除元素值等於 val 的元素後的長度，並且更改後的 nums[0..新長度 - 1] 為原 nums 中值不為 val 的元素。

## 解題

### 想法一:

做法: 雙指針 slow 與 fast，兩指針皆指向頭元素。當 nums[fast] 不等於 val 時，兩指針皆往後一步，當 nums[fast] == val，fast 往後移而 slow 停下。無論如何，下一次迴圈開始時皆令 nums[slow] = nums[flow]，使得原本位置值為 val 的元素在迴圈中逐漸被後面值不等於 val 的元素覆蓋。

程式:

```c++
// success
// time:  O(n)
// space: O(1)

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0;
        int fast = 0;
        while(fast < nums.size()){
            nums[slow] = nums[fast];
            if(nums[fast] != val){
                // slow and fast both step back
                slow++;
                fast++;
            }
            else if(nums[fast] == val){
                // just fast step back, and slow stop one time
                fast++;
            }
        }
        // now, fast == nums.size()
        // fast - slow equal the number of val
        return nums.size() - (fast - slow);
        // or return slow
    }
};
```

省思: 要注意 fast 在陣列末端時的處理，要避免 fast 超出陣列範圍時，還令 nums[left] = nums[right]，使得 nums[left] 為殘值，在 leetcode 會被視為 Runtime Error。

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
