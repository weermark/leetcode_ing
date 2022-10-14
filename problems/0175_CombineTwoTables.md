# 175. Combine Two Tables

[leetcode題目連結](https://leetcode.com/problems/combine-two-tables/)

解釋: 合併表格 Person 和 Address，Person 資料留下。

## 解題

### 想法一:

做法: 用 LEFT JOIN 即可。

程式:

```sql
-- success

/* Write your T-SQL query statement below */
SELECT P.firstName, P.lastName, A.city, A.state
FROM Person AS P LEFT JOIN Address AS A ON P.personId = A.personId;
```

<!--

<br/>

### 想法二:

做法:

程式:

```c++
// success
// time:  O()
// space: O()


```

省思: 

<br/>

<!--
### 網路解一:

```c++

```
-->
