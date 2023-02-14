# 182. Duplicate Emails

[leetcode題目連結](https://leetcode.com/problems/duplicate-emails/)

定義: 給定含有重複 email 的表格 Person，回傳重複的 email。

解釋: 

## 解題

### 想法一:

做法: 分群彙總，找出出現兩次以上的資料。

程式:

```sql
-- success

/* Write your T-SQL query statement below */
SELECT P.email
FROM Person AS P
GROUP BY P.email
HAVING COUNT(P.email) >= 2;
```