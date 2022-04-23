# 344. Reverse String

[leetcode題目連結](https://leetcode.com/problems/reverse-string/)

解釋: 反轉array內的元素。ex. index 0 與 index n-1 換，index 1 與 index n - 2 換...

## 解題

### 想法一:

做法: 用雙指針，一個從頭，一個從尾，兩個指針不相等時交換內容，並移動位置。

程式:

```c++
// success
// time:  O(n)
// space: O(1)

class Solution {
public:
    void swap(char& c1, char& c2){
        char tmp = c1;
        c1 = c2;
        c2 = tmp;
    }
    void reverseString(vector<char>& s) {
        for(int i = 0, j = s.size() - 1; i < s.size()/2; i++, j--){
            swap(s[i], s[j]);
        }
    }
};
```

省思: 很常見的題型，只要掌握雙指針的概念就可以快速完成。

<br/>

### 想法二:

做法:

同想法一，改用iterator。

程式:

```c++
// success
// time:  O(n)
// space: O(1)

class Solution {
public:
    void reverseString(vector<char>& s) {
        auto left = s.begin();
        auto right = s.end();
        while(left != right && left != --right){
            char tmp = *left;
            *left = *right;
            *right = tmp;
            left++;
        }
    }
};
```

省思: 要注意左指針與右指針不能同時改變位置，或者要另設判斷，不然兩指針可能會交錯(s有偶數個字元的時候)。另外，比起使用vector，善用與操作C-style的array更能精進程式能力。

<br/>

<!--
### 網路解一:

```c++

```
-->
