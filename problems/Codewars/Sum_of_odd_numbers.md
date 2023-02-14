# Sum of odd numbers

段位: 7

定義: 輸入整數 n，回傳奇數三角形第 n 層的總和。

解釋: 奇數三角形如下所示
```
             1
          3     5
       7     9    11
   13    15    17    19
21    23    25    27    29
...
```

輸入 1，回傳 1

輸入 2，回傳 8 (3+5)

做法: 找三角形的規律，每層的第一個開頭數字為上一層開頭數字加上 (n - 1) * 2，每層的總和只需在加上 n 個加 2 的數字。

程式:
```kotlin
// time:  O(n)
// space: O(1)

fun rowSumOddNumbers(n: Int): Int {
    var count = n - 1
    var start = 1
    var plus = 2
    while (count > 0) {
        start += plus
        plus += 2
        count -= 1
    }
    
    var res = start
    for (i in 2..n) {
        start += 2
        res += start
    }
    return res
}
```

## 參考解

n*(n-1)+1 即可算出第 n 層開頭數字。