# 520. Detect Capital

[leetcode題目連結](https://leetcode.com/problems/detect-capital/description/)

定義: 給一字串，回傳該字串是否符合大寫的使用格式。

解釋: 大寫使用格式有如下三種
1. 全部大寫
2. 全部小寫
3. 首字大寫，後續小寫

## 解題

### 想法一:

做法: 正則表達式匹配上列三種格式。

程式:
```java
// success
// time:  O(n)
// space: O(1)

import java.util.regex.*;

class Solution {
    public boolean detectCapitalUse(String word) {
        // 要麼全部大寫，要麼全部小寫，要麼首字大寫，後續小寫
        String pattern = "^[A-Z]*|[a-z]*|[A-Z][a-z]*$";
        return Pattern.matches(pattern, word);
    }
}
```