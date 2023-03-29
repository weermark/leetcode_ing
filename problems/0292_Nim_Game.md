# 292. Nim Game

[leetcode題目連結](https://leetcode.com/problems/nim-game/)

定義: 給一整數 `n`，回傳該整數在 Nim 遊戲下我方是否可獲勝。

解釋: Nim 遊戲的規則，有 `n` 個石頭，兩人遊戲，我方先手，一次可拿取 1~3 個石頭 (扣 `n` 1~3)，能使石頭被拿完者獲勝 ( `n` 歸零者獲勝)。假設雙方以最優方式進行遊戲。

## 解題

### 想法一:

做法: 遞迴，列出全部可能，只要我方有一種機會贏，那就是算我方贏，回傳 true。

程式:
```java
// fail: Wrong Answer
// reason: n = 8

class Solution {
    private boolean win;
    private boolean isIWin(int round) {
        // 如果 round % 2 == 1 為 true，代表我贏
        return round % 2 == 1;
    }
    private void backtracking(int n, int round) {
        // base case
        if (n <= 3) {
            if (isIWin(round)){
                win = true;
            }
            return;
        }
        // recursive case
        for (int i = 1; i <= 3; ++i) {
            backtracking(n - i, round + 1);
        }
    }
    // 只要我方有一種機會贏，那就是算我方贏，回傳 true
    public boolean canWinNim(int n) {
        win = false;
        if (n <= 3) return true;
        backtracking(n, 1);
        return win;
    }
}
```

問題: 題目假設雙方以最優的方式進行遊戲，因此遞迴列出的全部可能組合中，有非最優遊玩方式 (敵方在我方會輸的情況下，仍以非最優方式拿取，導致我方有機會贏)。

<br/>

### 想法二:

做法: 數字規律，`n` 若為 4 的倍數，則我方會輸，其餘我方會贏。

1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13  
---|---|---|---|---|---|---|---|---|---|---|---|---
W | W | W | L | W | W | W | L | W | W | W |  L | W

程式:
```java
// success
// time:  O(1)
// space: O(1)

class Solution {
    public boolean canWinNim(int n) {
        return (n % 4 != 0);
    }
}
```
<br/>

### 網路解:

[來源](https://leetcode.com/problems/nim-game/editorial/)

做法: 動態規劃，

```java
public boolean canWinBash(int n) {
    if(n <= 0) throw new IllegalArgumentException();
    if(n < 4) return true;
    boolean[] res = new boolean[n + 1];
    res[1] = true;
    res[2] = true;
    res[3] = true;
    for(int i = 4 ; i <= n ; i++)
        res[i] = !(res[i - 1] && res[i - 2] && res[i - 3]);
    return res[n];
}
```