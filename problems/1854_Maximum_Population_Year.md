# 1854. Maximum Population Year 

[leetcode題目連結](https://leetcode.com/problems/maximum-population-year/)

定義: 給一整數二維陣列 `logs`，`logs[i][0]` 代表第 `i` 人出生年份，`logs[i][0]` 代表第 `i` 人死亡年份 (該年死亡，不算人口)，回傳第一個人口數最多的年份。

解釋: 

## 解題

### 想法一:

做法: 掃描線。

程式:
```java
// success
// time:  O(nlgn)
// space: O(n)

class Solution {
    public int maximumPopulation(int[][] logs) {
        int len = logs.length;
        // 紀錄出生年份
        int[] begins = new int[len];
        // 紀錄死亡年份
        int[] ends = new int[len];
        for (int i = 0; i < len; ++i) {
            begins[i] = logs[i][0];
            ends[i] = logs[i][1];
        }
        Arrays.sort(begins);
        Arrays.sort(ends);

        // 最多人口數的數量
        int population = Integer.MIN_VALUE;
        // 最多人口數的年份
        int res = begins[0];
        // 某年人口數
        int count = 0;
        // 雙指針
        int i = 0, j = 0;
        while (i < len && j < len) {
            if (begins[i] < ends[j]) {
                // 某一人出生比某一人死亡早，人口數增加
                ++count;
                if (population < count) {
                    population = count;
                    res = begins[i];
                }
                ++i;
            } else if (begins[i] >= ends[j]) {
                // 某一人死亡比某一人出生早，人口數減少
                --count;
                ++j;
            }
        }
        return res;
    }
}
```