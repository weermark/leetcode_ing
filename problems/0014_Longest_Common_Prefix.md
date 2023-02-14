# 14. Longest Common Prefix

[leetcode題目連結](https://leetcode.com/problems/longest-common-prefix/)

定義:給定字串陣列，回傳最常字共同字首。

解釋: 字串共同字首是指字串開頭相同的片段。

## 解題

### 想法一:

做法: 每次循環比較兩個字串的共同字首長度，此長度再與之前比較得到的長度比較何者較小。

程式:

```c++
// success
// time:  O(n * m)
// n is the length of strs, m is the length of strs[i]
// space: O(1)

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int newMinLen = 0;
        int oldMinLen = INT_MAX;
        
        for(int i = 0; i < strs.size() - 1; ++i){
            newMinLen = 0;
            // get min len between two string
            // so that we will not get index outside of string
            int strLen = min(strs[i].length(), strs[i + 1].length());
            // finally minimum len wouldn't large than oldMinLen
            int limitLen = min(oldMinLen, strLen);
            // compare common prefix with string i and i+1
            while(newMinLen < limitLen){
                if(strs[i][newMinLen] == strs[i + 1][newMinLen])
                    ++newMinLen;
                else
                    break;
            }
            // get min common prefix length with this time and past record
            oldMinLen = min(oldMinLen, newMinLen);
        }
        return strs[0].substr(0, oldMinLen); 
    }
};
```

問題: 每個字串都被比較兩次。

<br/>

### 想法二:

做法: 每次循環垂直掃描全部 strs 內的字串的同一索引的元素，如有一不相同或長度觸底即可結束並回傳。

程式:

```c++
// success
// time:  O(n * m)
// n is the length of strs, m is the length of strs[i]
// space: O(1)

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs[0] == "")   return "";
        // 垂直比較其他字串同一索引的字元
        for(int index2 = 0; index2 < strs[0].size(); ++index2){
            char c = strs[0][index2];
            for(int index1 = 1; index1 < strs.size(); ++index1){
                // 有一字串不同，或者長度觸底，結束執行
                if(strs[index1][index2] != c || index2 >= strs[index1].length())
                    return strs[0].substr(0, index2);
            }
        }
        // 如果迴圈結束但此函數還沒結束，代表 strs 只有一個元素
        return strs[0]; 
    }
};
```

省思: 比想法一的程式短了很多，也較直觀。