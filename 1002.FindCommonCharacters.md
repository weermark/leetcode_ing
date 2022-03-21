# 1002. Find Common Characters

[leetcode題目連結](https://leetcode.com/problems/find-common-characters/)

解釋: 給予string vector，內含數個單字，回傳在每個單字中都出現過的alphabet。

## 解題

### 想法一:

做法: 創立26個空間的array，每個單字的char轉成0-25(a-z)，並把該index加一，如果遍歷完後該index的值等於words.size()，代表該index映對的char重複出現，如值等於words.size()*2，代表兩個重複出現。

程式:

```c++
// error: Wrong Answer

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> record(26, 0);
        int index;
        int count;
        string c;
        vector<string> ans;
        for(int i = 0; i < words.size(); i++){
            for(int j = 0; j < words[i].size(); j++){
                index = words[i][j] - 'a';
                record[index]++;
            }
        }
        for(int i = 0; i < record.size(); i++){
            c = i + 'a';
            count = record[i] / words.size();
            for(int j = 0; j < count; j++){
                ans.push_back(c);
            }
        }
        
        return ans;
    }
};
```

問題: 同一個單字出現同一個char的次數可能等於words.size()。

<br/>

### 想法二(修正想法一):

做法: 創立26個空間的array，每個單字的char轉成0-25(a-z)，並把該index加1。同時時用兩個vector，一個記錄舊的，一個更新。每次遍歷完一個單字，就用min()取每個char出現最小次數存回紀錄舊的vector。

程式:

```c++
// success
// time:  O(n*m)
// space: O(1)

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> recordOld(26, 0);
        vector<int> recordNew(26, 0);
        vector<string> ans;
        int index;
        string s;
        
        for(int i = 0; i < words[0].size(); i++){
            index = words[0][i] - 'a';
            recordOld[index]++;
        }
        
        for(int i = 1; i < words.size(); i++){
            fill(recordNew.begin(), recordNew.end(), 0);
            for(int j = 0; j < words[i].size(); j++){
                index = words[i][j] - 'a';
                recordNew[index]++;
            }
            for(int j = 0; j < 26; j++){
                recordOld[j] = min(recordOld[j], recordNew[j]);
            }
        }
        for(int i = 0; i < 26; i++){
            while(recordOld[i] != 0){
                s = i + 'a';
                ans.push_back(s);
                recordOld[i]--;
            }
        }
        return ans;
    }
};
```

省思: 程式碼與變數名太長，或許可用range for代替。

<br/>

### 網路解一:

更簡潔

```c++
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> cnt(26, INT_MAX);
        vector<string> res;
        
        for(auto s : words){
            vector<int> cnt1(26, 0);
            for(auto c : s)
                cnt1[c - 'a']++;
            for(int i = 0; i < 26; i++)
                // 無出現的char的index值皆為0
                cnt[i] = min(cnt[i], cnt1[i]);
        }
        for(int i = 0; i < 26; i++){
            for(int j = 0; j < cnt[i]; j++)
                res.push_back(string(1, i + 'a'));
        }
        return res;
    }
};
```
