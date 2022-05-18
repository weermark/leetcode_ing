# 383. Ransom Note

[leetcode題目連結](https://leetcode.com/problems/ransom-note/)

解釋: 給予兩個string，如果第二個string可以包含第一個string相對應的各個alphabet量，回傳true，否則回傳false。

## 解題

### 想法一:

做法: 創立hash map，迭代magazine，map的key存出現的char，value存出現次數(數量)。而後再迭代ransomNote，把用到的char扣掉。如最後map中有負數，代表magazine中各char的數量無法滿足ransomNote所需數量，回傳false。


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

做法: 使用map比較花空間，因為確定出現的char為a-z，所以可以用array[26]就好。

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