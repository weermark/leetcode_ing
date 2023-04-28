# 1154. Day of the Year

[leetcode題目連結](https://leetcode.com/problems/day-of-the-year/)

定義: 給一字串，格式為 `YYYY-MM-DD`，回傳該天是該年的第幾天。

## 解題

### 想法一:

做法: 若為閏年，二月有 29 天，需特別加上，其餘照一般常識計算日期數。

程式:
```java
// success
// time:  O(1)
// space: O(1)

class Solution {
    private boolean isLeap(int year) {
        return (year % 400 == 0) || (year % 100 != 0 && year % 4 == 0);
    }

    public int dayOfYear(String date) {
        int[] daysEachMonth =  {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 
        int years = Integer.parseInt(date.substring(0, 4));
        int months = Integer.parseInt(date.substring(5, 7));
        int days = Integer.parseInt(date.substring(8, 10));

        int res = 0;
        // day
        res += days;
        // month
        for (int i = 0; i < months - 1; ++i) {
            res += daysEachMonth[i];
        }
        // leap
        if (isLeap(years) && months > 2) {
            res += 1;
        }
        return res;
    }
}
```