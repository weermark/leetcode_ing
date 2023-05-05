# 1456. Maximum Number of Vowels in a Substring of Given Length

[leetcode題目連結](https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/description/)

定義: 給一字串和一整數 `k`，回傳長度為 `k` 的子字串最多有幾個母音字元。

解釋: 母音字元為 `a, e, i, o, u`。

## 解題

### 想法一:

做法: 類似滑動窗口，但因長度固定，所以不用維護左邊界。

程式:
```java
// success
// time:  O(n)
// space: O(1)

class Solution {
    public int maxVowels(String s, int k) {
        int count = 0;
        Set<Character> set = new HashSet<>() {{
            add('a');
            add('e');
            add('i');
            add('o');
            add('u');
        }};

        for (int right = 0; right < k; ++right) {
            if (set.contains(s.charAt(right)))
                ++count;
        }
        int res = count;
        for (int right = k; right < s.length(); ++right) {
            if (set.contains(s.charAt(right)))
                ++count;
            // 左邊界的前一個字元，也就是窗口要離開的字元
            int left = right - k;
            if (set.contains(s.charAt(left)))
                --count;
            res = Math.max(count, res);
        }
        return res;
    }
}
```