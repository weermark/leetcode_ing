# 0242. Valid Anagram

[leetcode題目連結](https://leetcode.com/problems/valid-anagram/)

題目給定兩個 string *s* 與 *t* ，要求這兩組 string 是否是字謎(字母出現頻率相同但位置不同的單字)。

## 解題

### 想法一: 

做法: 用 map，存 alphabet 與 frequency。

程式:
```
```

問題: 字母數量固定(26個)，且 alphabet 的 asci 也固定，不須浪費空間存 alphabet。

<br/>

### 想法二:

做法: 用 array，初始化 26 個，用 c-'a' 所得的整數作為索引讀取值。

程式: c++
```c++
// success
// time:  O(n)
// space: O(1)

class Solution {
public:
    bool isAnagram(string s, string t) {
        int record[26] = {0};
        int index;
        for(int i = 0; i < s.size(); i++){
            index = s[i] - 'a';
            record[index]++;
        }
        for(int i = 0; i < t.size(); i++){
            index = t[i] - 'a';
            record[index]--;
        }
        for(int i = 0; i < 26; i++){
            if(record[i] != 0)
                return false;
        }
        return true;
    }
};
```
省思: 變數 index 可加可不加。

<br/>

<!--
### 網路解一:

```c++
```
-->
