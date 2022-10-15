# 595. Big Countries

[leetcode題目連結](https://leetcode.com/problems/big-countries/)

定義: 給定表格 World，內含有 name, area, population，回傳 area 大於 3,000,000 或 population 大於 25,000,000 的國家的 name, area, population。

解釋: 

## 解題

### 想法一:

做法: 用比較運算子做判斷即可。

程式:

```sql
-- success

/* Write your T-SQL query statement below */
SELECT W.name, W.population, W.area
FROM World AS W
WHERE W.area >= 3000000 OR W.population >= 25000000;
```