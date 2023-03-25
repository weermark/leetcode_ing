# 278. First Bad Version

[leetcode題目連結](https://leetcode.com/problems/first-bad-version/)

定義: 給一整數 n，其中 1 ~ n 中的某一整數，大於該數值的數 (包含該數) 只要傳入 API `bool isBadVersion(int version)` 皆會回傳 `true`。回傳第一個結果為 `true` 的整數。


## 解題

### 想法一:

做法: 二分搜索。

程式:

左閉右開
```java
// success
// time:  O(lgn)
// space: O(1)

/* The isBadVersion API is defined in the parent class VersionControl.
      boolean isBadVersion(int version); */

public class Solution extends VersionControl {
    public int firstBadVersion(int n) {
        int left = 0;
        int right = n;
        // 左閉右開
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (isBadVersion(mid)) {
                // 第一個 bad 在 mid 或 mid 左邊
                right = mid;
            } else if (!isBadVersion(mid)) {
                // 第一個 bad 在 mid 右邊
                left = mid + 1;
            }
        }
        return left;
    }
}
```

左閉右閉
```java
// success
// time:  O(lgn)
// space: O(1)

/* The isBadVersion API is defined in the parent class VersionControl.
      boolean isBadVersion(int version); */

public class Solution extends VersionControl {
    public int firstBadVersion(int n) {
        int left = 0;
        int right = n;
        // 左閉右閉
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isBadVersion(mid)) {
                // 第一個 bad 在 mid 或 mid 左邊
                right = mid - 1;
            } else if (!isBadVersion(mid)) {
                // 第一個 bad 在 mid 右邊
                left = mid + 1;
            }
        }
        return left;
    }
}
```