# 9. Palindrome Number

[leetcode題目連結](https://leetcode.com/problems/palindrome-number/)

定義: 給定一整數，回傳是否是迴文。

解釋: 

## 解題

### 想法一:

做法: 雙指針。先把整數轉字串，並讓兩指針從最左、右出發，如元素相等，則往中間一步，如不同，返回 false。

程式:

```c#
// success
// time:  O(n)
// space: O(1)

public class Solution {
    public bool IsPalindrome(int x) {
        String palindromeStr = x.ToString();
        int left = 0;
        int right = palindromeStr.Length - 1;
        
        while(left < right){
            if(palindromeStr[left] != palindromeStr[right]){
                return false;
            }
            ++left;
            --right;
        }
        return (palindromeStr[left] != palindromeStr[right]) ? false : true;
    }
}
```

省思: 這題參數給整數，代表要試著不轉字串，用整數判斷。

<br/>

### 想法二:

做法: 用整數變數儲存倒過來的參數，並比較兩者是否相同。

程式:

```
// success
// time:  O()
// space: O()


```

省思: 