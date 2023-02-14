
# 455. Assign Cookies

[leetcode題目連結](https://leetcode.com/problems/assign-cookies/)

解釋: 給兩陣列 g, s。g[i] 代表小孩 i 對餅乾大小的需求，s[j] 代表餅乾 j 的大小。只有餅乾大小大於等於小孩需求，該小孩才能被滿足。回傳被滿足小孩的數量。

## 解題

### 想法一:

做法: 從最大需求的小孩與最大塊的餅乾開始判斷，能給則給，不能則換下一個小孩判斷。

程式:

```c++
// error: Wrong Answer
// input: [10,9,8,7][5,6,7,8]

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int i = g.size()- 1;
        int j = s.size() - 1;
        int res = 0;
        while(i >= 0 && j>=0){
            // 小孩 i 需求小於等於餅乾 j，則餅乾給該小孩，並換下一個小孩
            if(g[i] <= s[j]){
                ++res;
                --i;
                --j;
            }
            // 小孩 i 需求大於餅乾 j，則直接換下一個小孩
            else if(g[i] > s[j]){
                --i;
            }
        }
        return res;
    }
};
```

問題: 陣列 g 並沒有排序。

<br/>

### 想法二:

做法: 修正想法二，先把 g, s 排序

程式:

```c++
// success
// time:  O(nlogn)
// space: O(1)

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // g, s 並沒有排序，因此先排序，才好取出最大需求小孩和最大塊餅乾
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int j = s.size() - 1;
        int res = 0;
        for(int i = g.size() - 1; i >=0 && j >= 0; --i){
            // 小孩 i 需求小於等於餅乾 j，則餅乾給該小孩，並換下一個小孩
            if(g[i] <= s[j]){
                ++res;
                --j;
            }
            /* 小孩 i 需求大於餅乾 j，則直接換下一個小孩 (j 在當次循環為最大塊餅乾，因此不存在比 j 大的餅乾，也代表該小孩不可能被滿足)
            */
            // else if(g[i] > s[j]){}
        }
        return res;
    }
};
```

省思: 拿最大比最大的。

<br/>

<!--
### 網路解一:

```c++

```
-->
