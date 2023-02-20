# 13. Roman to Integer

[leetcode題目連結](https://leetcode.com/problems/roman-to-integer/)

定義: 給一符合羅馬數字格式的字串，回傳轉換成阿拉伯數字的值。

解釋: 羅馬數字，數值小的字放在數值大的自前面須減去，否則加上。

## 解題

### 想法一:

做法: 依照解釋迭代字串。

程式:
```python
// success
// time:  O(n)
// space: O(1)

class Solution:
    def romanToInt(self, s: str) -> int:
        map = {
            'I': 1,
            'V': 5,
            'X': 10,
            'L': 50,
            'C': 100,
            'D': 500,
            'M': 1000
        }
        res = 0
        for i in range(0, len(s) - 1):
            # s[i] 位置的數字比 s[i + 1] 小，則減去
            if map[s[i]] < map[s[i + 1]]:
                res -= map[s[i]]
            # 較大，則加上
            else:
                res += map[s[i]]
        # 最後一位數須補加上
        res += map[s[len(s) - 1]]
        return res
```

省思: 只要找到轉換時的加減規則就變很簡單了。