# 349. Intersection of Two Arrays

[leetcode題目連結](https://leetcode.com/problems/intersection-of-two-arrays/submissions/)

解釋: 回傳nums1與nums2中都出現過的元素。

## 解題

### 想法一:

做法: 把nums1放入set，set在與nums2比較某元素是否出現過，有則放入set1，最後回傳set1。

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

做法: 把nums1放入set s，遍歷nums2的元素，在s有找到則放入res並從s中移除。

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
