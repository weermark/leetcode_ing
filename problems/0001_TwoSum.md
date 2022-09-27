# 1. Two Sum

[leetcode題目連結](https://leetcode.com/problems/two-sum/)

解釋: 回傳參數陣列 nums 中兩個相加等於 target 的元素的索引。

## 解題

### 想法一:

做法: 創立 hashMap。迭代 nums，如果 nums[i] 不存在 map ，則把 target-nums[i] 與 i 存入 map。下次只要出現一數已存在於 m，代表 target - nums[i] 等於此數。透過 m[nums[i]] 即可取得 nums[i] 的 index。 (ex. map 中有一 pair{5, 2}，代表 nums[i] 的索引為 2，target-nums[i] 為 5)

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

省思: 在決定存入與存取 nums[i] 還是 target-nums[i] 要多留心。

<br/>

<!--
### 網路解一:

```c++

```
-->
