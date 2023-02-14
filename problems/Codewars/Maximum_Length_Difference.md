# Maximum Length Difference

段位: 7

定義: 給定兩陣列 a1, a2，回傳 a1 (或 a2) 中最長字串的長度減去 a2 (或 a1) 中最短字串的長度的最大值。如果有一陣列為空，回傳 -1。

## 解題

### 想法一:

做法: 個別找出 a1 和 a2 中最大和最小字串的長度，再算出何者相減較大。

程式:

```kotlin
// success
// time:  O(n)
// n 為兩陣列中較長者的長度
// space: O(1)

package maxlendiff

fun mxdiflg(a1:Array<String>, a2:Array<String>):Int {
    // 特殊情況
    if (a1.isEmpty() || a2.isEmpty()) {
        return -1
    }
    // a1 最長字串長度減去 a2 最短字串長度
    val res1 = getLongest(a1) - getSmallest(a2)
    // a2 最長字串長度減去 a1 最短字串長度
    val res2 = getLongest(a2) - getSmallest(a1)
    return if (res1 > res2) res1 else res2
}

// 回傳陣列最短字串長度
fun getSmallest(arr: Array<String>): Int{
    var smallest = arr[0].length
    for (str in arr) {
       smallest = if (smallest < str.length) smallest else str.length
    }
    return smallest
}

// 回傳陣列最長字串長度
fun getLongest(arr: Array<String>): Int{
    var longest = arr[0].length
    for (str in arr) {
       longest = if (longest > str.length) longest else str.length
    }
    return longest
}
```