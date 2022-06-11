# 416. Partition Equal Subset Sum

[leetcode題目連結](https://leetcode.com/problems/partition-equal-subset-sum/)

解釋: 回傳參數陣列是否可以拆成兩個子集，使得兩個子集的元素值加總相等。

## 解題

### 想法一:

做法: 判斷是否存在兩個加總相等的子集，換個說法，也就是判斷陣列中是否存在一集合，使得此集合值加總等於陣列元素值加總的一半。題目只要求布林值，因此不需求出實際集合內的值。遇到找陣列子集組合問題，通常可用動態規劃。網路上說此題可用 01 背包問題的概念。
背包載重為陣列元素值加總的一半，而元素值為重量與價值。
令 i 為陣列元素個數 (陣列長度)，j 為 0 到背包載重，dp[i][j] 為在重量為 j 的情況下，陣列 0 到 i 的元素值的最大加總。

初始化:
```
dp[i][0] = 0
dp[0][j] = 0, if j < nums[0]
dp[0][j] = i, if j >= nums[0]
```

狀態轉移方程:
```
dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - nums[i]] + nums[i]);
```

程式:

```c++
// error: Runtime Error
// reason: heap-buffer-overflow, Last executed input [100]

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i : nums)
            sum += i;
        // 陣列元素值加總為奇數，無法拆解成兩個相等加總值的子集
        if(sum % 2 == 1)    return false;
        int target = sum / 2;
        
        vector<vector<int>> dp(nums.size(), vector<int>(target + 1, 0));
        // init
        for(int i = 0; i < nums.size(); i++)
            dp[i][0] = 0;
        for(int j = 0; j < nums[0]; j++)
            dp[0][j] = 0;
        for(int j = nums[0]; j <= target; j++)
            dp[0][j] = nums[0];
        
        // transfer
        for(int i = 1; i < nums.size(); i++){
            for(int j = 1; j <= target; j++){
                if(j < nums[i])
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - nums[i]] + nums[i]);
            }
        }
        /*for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j <= target; j++){
                cout << dp[i][j] << ' ';
            }
            cout << endl;
        }*/
        // 剛好裝滿，代表存在子集，其加總為陣列元素值加總的一半
        return (dp[nums.size() - 1][target] == target);
    }
};
```

問題: 初步認定為花費空間太大，但機率低。也有可能是索引取錯。

<br/>

### 想法二:

做法: 把做法一用滾動陣列實作。

程式:

```c++
// error: Runtime Error
// reason: heap-buffer-overflow, Last executed input [100]

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i : nums)
            sum += i;
        // 陣列元素值加總為基數，無法拆解成兩個相等加總值的子集
        if(sum % 2 == 1)    return false;
        int target = sum / 2;
        
        vector<int> dp(target + 1, 0);
        // init
        for(int j = 0; j < nums[0]; j++)
            dp[j] = 0;
        for(int j = nums[0]; j <= target; j++)
            dp[j] = nums[0];
        
        // transfer
        for(int i = 1; i < nums.size(); i++){
            for(int j = target; j >= nums[i]; j--){
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        /*for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j <= target; j++){
                cout << dp[i][j] << ' ';
            }
            cout << endl;
        }*/
        return (dp[target] == target);
    }
};
```

問題: 應當是迭代時，索引取錯。

<br/>

### 想法三:

做法: 更正想法二。

程式:

```c++
// success
// time:  O(n^2)
// space: O(n)

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i : nums)
            sum += i;
        // 陣列元素值加總為基數，無法拆解成兩個相等加總值的子集
        if(sum % 2 == 1)    return false;
        int target = sum / 2;
        
        vector<int> dp(target + 1, 0);
        // init
        
        // transfer
        for(int i = 0; i < nums.size(); i++){
            for(int j = target; j >= nums[i]; j--){
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        /*for(int i : dp){
            cout << i << ' ';
        }*/
        return (dp[target] == target);
    }
};
```

省思: 對於背包問題的不熟導致索引取值多次更改。這題基本上與 01 背包問題一致，只是要想到背包載重為 sum/2。

<br>

<!--
### 網路解一:

```c++

```
-->
