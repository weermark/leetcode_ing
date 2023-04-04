# 2073. Time Needed to Buy Tickets

[leetcode題目連結](https://leetcode.com/problems/time-needed-to-buy-tickets/description/)

定義: 給一整數陣列 `tickets` 和一整數 `k`，其中 `tickets` 陣列上每一個元素值代表該索引位置的人所需買的票數，每一輪只能買一張票，每買一張票需要一秒，還沒買到足夠數量則須到隊尾重排，直到買到足夠票數。回傳位於索引 `k` 的人買到足夠的票所需的時間。

## 解題

### 想法一:

做法: 照著題目文義的邏輯，模擬排隊。

程式:
```java
// success
// time:  O(n^2)
// space: O(1)

class Solution {
    public int timeRequiredToBuy(int[] tickets, int k) {
        int count = 0;
        int len = tickets.length;
        for (int i = 0; tickets[k] > 0; ++i) {
            if (tickets[i % len] > 0) {
                ++count;
                --tickets[i % len];
            }
        }
        return count;
    }
}
```

### 想法二:

做法: 在索引 `k` 前面的元素，比 `k` 小的在 `k` 買到足夠的票前 (歸 0 前) 一定會歸 0，比 `k` 大則會剩餘元素值扣除索引 `k` 元素值的值。在索引 `k` 後面的元素，比 `k` 小的在 `k` 買到足夠的票前 (歸 0 前) 一定也會歸 0，比 `k` 大則會剩餘元素值扣除索引 `k` 的元素值減一的值 (因為 `k` 歸 0 時即停止計算，該次不扣)。依照上述邏輯，迭代陣列一次即可得到答案。

程式:
```java
// success
// time:  O(n)
// space: O(1)

class Solution {
    public int timeRequiredToBuy(int[] tickets, int k) {
        int round = tickets[k];
        int res = 0;
        for (int i = 0; i < k; ++i) {
            res += Math.min(tickets[i], round);
        }
        res += round;
        for (int i = k + 1; i < tickets.length; ++i) {
            res += Math.min(tickets[i], round - 1);
        }
        return res;
    }
}
```