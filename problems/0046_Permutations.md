# 46. Permutations

[leetcode題目連結](https://leetcode.com/problems/permutations/)

定義: 給定一陣列 nums，回傳陣列中元素的全排列。

## 解題

### 想法一:

做法: 回溯。在回溯過程中，把沒加過的元素加到 path，加過的就不加。當 path 長度等於 nums，此為一種排列可能，加到 res，並回溯到上一層，把 path 最後一個加入的元素踢出。回溯會重複這個過程，直到全部排列可能都被放入 res。

程式:

```c++
// success
// time:  O(n * n!)
// space: O(n!)

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<bool> used;

    void backtracking(vector<int>& nums){
        if(path.size() == nums.size()){
            res.push_back(path);
            return;
        }
        for(int i = 0; i < nums.size(); ++i){
            // nums[i] arready in path
            if(used[i] == true) continue;
            // add nums[i] to path
            path.push_back(nums[i]);
            used[i] = true;
            
            backtracking(nums);
            // remove nums[i] from path
            path.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        // init used
        used.resize(nums.size());
        fill(used.begin(), used.end(), false);
        
        backtracking(nums);
        return res;
    }
};
```

省思: 暴力窮舉!!