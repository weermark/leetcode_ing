# 20. Valid Parentheses

[leetcode題目連結](https://leetcode.com/problems/valid-parentheses/)

定義: 輸入一字串，內含多個左右括號，回傳字串內括號是否正確配對。

解釋: `()[]{}` 為正確配對，`(}` 為錯誤配對。

## 解題

### 想法一:

做法: 建立 stack，利用 stack 特性比對括號，正確配對就把左括號踢出。如迭代完字串發現 stack 不為空，代表有括號沒有配對到，則回傳 false，反之回傳 true。

程式:

```c++
// success
// time:  O(n)
// space: O(n)

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        st.push(s[0]);
        for(int i = 1; i < s.length(); ++i){
            char c = s[i];
            
            // stack 為空且右括號單獨出現，回傳 false
            if(st.empty() && (c == ')' || c == ']' || c == '}'))
                return false;
            // 左括號出現，放入 stack
            else if(c == '(' || c == '[' || c == '{')
                st.push(c);
            // 括號配對正確，踢出 stack
            // 注意若 stack 為空，取 stack.top() 會報錯
            else if(st.top() == '(' && c == ')')
                st.pop();
            else if(st.top() == '[' && c == ']')
                st.pop();
            else if(st.top() == '{' && c == '}')
                st.pop();
            // 括號配對錯誤，回傳 false
            else
                return false;
        }
        return st.empty() ? true : false; 
    }
};
```

省思: 要注意若 stack 為空，取 stack 最上面的值會出錯。

<!--
<br/>

### 想法二:

做法:

程式:

```
// success
// time:  O()
// space: O()


```

省思: 
-->