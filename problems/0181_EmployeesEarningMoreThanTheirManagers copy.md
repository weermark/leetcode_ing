# 181. Employees Earning More Than Their Managers

[leetcode題目連結](https://leetcode.com/problems/employees-earning-more-than-their-managers/)

定義: 給定表格 Employee，內含有 id, name, salary, managerId，回傳員工 salary 比主管 salary 高的 name。

解釋: 

## 解題

### 想法一:

做法: JOIN Employee 表格，比較 salary 和 managerId 的 salary 誰高。

程式:

```sql
-- success

/* Write your T-SQL query statement below */
SELECT E.name AS Employee
FROM Employee AS E JOIN Employee AS M ON E.managerId = M.id
WHERE E.salary > M.salary;
```