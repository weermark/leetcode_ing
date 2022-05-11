# 349. Intersection of Two Arrays

[leetcode題目連結](https://leetcode.com/problems/intersection-of-two-arrays/submissions/)

解釋: 回傳 nums1 與 nums2 中都出現過的元素。

## 解題

### 想法一:

做法: 把 nums1 放入 set，set 在與 nums2 比較某元素是否出現過，有則放入 set1，最後回傳 set1。

程式:

```c++
// success
// time:  O(n)
// space: O(n*m)

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s(nums1.begin(), nums1.end());

        unordered_set<int> s1;
        for(auto i : nums2){
            if(s.count(i))
                s1.insert(i);
        }
        
        return vector<int>(s1.begin(), s1.end());
    }
};
```

問題: 空間花費較多。

<br/>

### 想法二:

做法: 把 nums1 放入 set *s*，遍歷 nums2 的元素，在 s 有找到則放入 res 並從 s 中移除。

程式:

```c++
// success
// time:  O(n)
// space: O(n)

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s(nums1.begin(), nums1.end());
        vector<int> res;
        for(auto i : nums2){
            if(s.count(i)){
                res.push_back(i);
                s.erase(i);
            }
        }
        return res;
    }
};
```

省思: 因為知道nums[i]大小，所以可以初始化時給定空間，加快速度。

<br/>

<!--
### 網路解一:

```c++

```
-->
