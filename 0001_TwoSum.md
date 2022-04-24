# 1. Two Sum

[leetcode題目連結](https://leetcode.com/problems/two-sum/)

解釋: 回傳nums[]內兩個相加等於target的數的index。

## 解題

### 想法一:

做法: 創立map。迭代nums，如果nums[i]不存在map，則把target-nums[i]與i存入map。下次只要只要出現一數已存在於m，代表 target - nums[i] 等於此數。透過m[nums[i]]即可取得nums[i]的index。(設map中有一pair{5, 2}，代表nums[i]的index為2，target - nums[i]為5)

程式:

```c++
// success
// time:  O(n)
// space: O(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); i++){
            if(!m.count(nums[i]))
                m.insert({target - nums[i], i});
            else
                return {m[nums[i]], i};
        }
        return {};
    }
};
```

省思: 在決定存入與存取nums[i]還是target-nums[i]要多留心。

<br/>

<!--
### 網路解一:

```c++

```
-->