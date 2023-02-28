# 58. Length of Last Word

[leetcode題目連結](https://leetcode.com/problems/length-of-last-word/)

定義: 給一字串，回傳最後一個單字的長度。(字串最後面可能是空格)

## 解題

### 想法一:

做法: 只記錄單字的長度，空格皆忽略。

程式:
```python
// success
// time:  O(n)
// space: O(1)

class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        length = 0
        count = 0
        s += " "
        # 紀錄是否是新單字
        new_word = False
        for c in s:
            if c == " ":
                # 若為單字的結束，才執行。若一直是空格，則不執行
                if new_word:
                    length = count
                    count = 0
                # 目前是空格，改為 false
                new_word = False
            else:
                # 目前非空格，改為 true
                new_word = True
                count += 1
        return length
```