# 1002. Find Common Characters

[leetcode題目連結](https://leetcode.com/problems/find-common-characters/)

解釋: 給字串陣列，內含數個單字，回傳在每個單字中都出現過的字母。

## 解題

### 想法一:

做法: 創立 26 個空間的陣列，每個字母的 char 轉成 0-25(a-z)。如有出現某字母，把陣列中對應索引的元素值加一，如果遍歷完後對應的索引的元素值等於 words.size()，代表索引映對的字母重複出現，如元素值等於 words.size()*2，代表兩個重複出現。

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

問題: 同一個單字出現同一個 char 的次數可能等於 words.size()。

<br/>

### 想法二(修正想法一):

做法: 創立 26 個空間的陣列，每個字母的 char 轉成 0-25(a-z)，如有出現某字母，把陣列中對應索引的元素值加一。同時時用兩個vector，一個記錄舊的，一個更新。每次遍歷完一個單字，就用min() 取每個字母出現最小次數存回紀錄舊的陣列。

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

省思: 程式碼與變數名太長，或許可用 range for 代替。

