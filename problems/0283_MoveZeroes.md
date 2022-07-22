# 283. Move Zeroes

[leetcode題目連結](https://leetcode.com/problems/move-zeroes/)

解釋:

## 解題

### 想法一:

做法:

程式:

```java
// error: 
// fail:
// reason: 

class Solution {
    public void moveZeroes(int[] nums) {
        int fast = 0, slow = 0;
        for(; fast < nums.length; ++slow, ++fast){
            if(nums[fast] == 0){
                ++fast;
            }
            if(fast < nums.length)
                nums[slow] = nums[fast];
        }
        for(; slow < nums.length; ++slow){
            nums[slow] = 0;
        }
    }
}
```

問題:

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
