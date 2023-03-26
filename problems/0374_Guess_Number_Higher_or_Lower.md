# 374. Guess Number Higher or Lower

[leetcode題目連結](https://leetcode.com/problems/guess-number-higher-or-lower/)

定義: 給一整數 `n`，找出一數字，使得該數字傳入 `int guess(int num)` 回傳 `0`，小於該數的數回傳 `1`，大於該數的數回傳 `-1`。回傳該數字。

## 解題

### 想法一:

做法: 二元搜尋。

程式:
```java
// success
// time:  O(lgn)
// space: O(1)

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

public class Solution extends GuessGame {
    public int guessNumber(int n) {
        int left = 1;
        int right = n;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            // higher
            if (guess(mid) == -1) {
                right = mid - 1;
            // lower
            } else if (guess(mid) == 1) {
                left = mid + 1;
            // equal
            } else if (guess(mid) == 0) {
                return mid;
            }
        }
        return -1;
    }
}
```