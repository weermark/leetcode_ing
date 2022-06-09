# 383. Ransom Note

[leetcode題目連結](https://leetcode.com/problems/ransom-note/)

解釋: 給予兩個 string，如果第二個 string 可以包含第一個 string 相對應的各個 alphabet 量，回傳 true，否則回傳 false。

## 解題

### 想法一:

做法: 創立 hashMap，迭代 magazine，map 的 key 存出現的 char，value 存出現次數(數量)。而後再迭代 ransomNote，把用到的 char 扣掉。如最後 map 中有負數，代表 magazine 中各 char 的數量無法滿足 ransomNote 所需數量，回傳 false。


程式: 
```c++
// success
// time:  O(n)
// space: O(n)

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> m;
        for(char c : magazine)
            ++m[c];
        for(char c : ransomNote)
            --m[c];
        for(auto i : m){
            if(i.second < 0)
                return false;
        }
        return true;
    }
};
```

省思: 常見的題目類型。

<br>

### 想法二:

做法: 使用 map 比較花空間，因為確定出現的 char 必為 a-z，所以可以用 array[26] 就好。

程式: 
```c++
// success
// time:  O(n)
// space: O(1)

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int record[26] = {0};
        for(char c : magazine)
            ++record[c-'a'];
        for(char c : ransomNote){
            if(--record[c-'a'] < 0)
                return false;
        }
        return true;
    }
};
```

省思: 透過固定空間降到常數空間。

<br/>

<!--
### 網路解一:

```c++

```
-->
