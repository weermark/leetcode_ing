# 1572. Matrix Diagonal Sum

[leetcode題目連結](https://leetcode.com/problems/matrix-diagonal-sum/description/)

定義: 給一方形矩陣，回傳對角線數值總和。

## 解題

### 想法一:

做法: 用 `mat[i][i]` 可算出單邊對角線 `\`，另一邊 `/` 用 `mat[i][len - 1]`，兩邊相加 `X` 即為答案。若矩陣長度為基數，中心會算到兩次，須扣除。

程式:
```java
// success
// time:  O(n)
// space: O(1)

class Solution {
    public int diagonalSum(int[][] mat) {
        int sum = 0;
        final int len = mat.length;
        
        for (int i = 0; i < len; ++i) {
            // \ + / = X
            sum += mat[i][i] + mat[i][len - i - 1];
        }
        // 扣除重複中心
        if (len % 2 != 0) {
            sum -= mat[len / 2][len / 2];
        }
        return sum;
    }
}
```