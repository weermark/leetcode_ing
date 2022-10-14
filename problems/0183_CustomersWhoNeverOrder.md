# 183. Customers Who Never Order

[leetcode題目連結](https://leetcode.com/problems/customers-who-never-order/)

定義: 給定表格 Customers 含有客戶 id 和 name，以及表格 Orders 含有訂單 id 和 customerId，回傳沒有下過訂單的客戶的 name，也就是 Customers.id 沒有在 Orders.customerId 出現過的 Customers.name。

解釋: 

## 解題

### 想法一:

做法: 使用 NOT EXISTS 找出沒有在 Orders.customerId 出現過的 Customers.id 。

程式:

```sql
-- success

/* Write your T-SQL query statement below */
SELECT C.name AS Customers
FROM Customers AS C
WHERE NOT EXISTS (SELECT *
                 FROM Orders AS O
                 WHERE O.customerId = C.id);

```