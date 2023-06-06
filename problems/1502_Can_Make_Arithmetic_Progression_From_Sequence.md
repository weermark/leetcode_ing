# 1502. Can Make Arithmetic Progression From Sequence

[leetcode題目連結](https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/description/)

定義: 給一整數陣列，回傳此陣列經過重新排列後是否能成為等差級數。

## 解題

### 想法一:

做法: 排序後，檢查每個元素間之差是否相等，即是否為等差。

程式:
```java
// success
// time:  O(nlgn)
// space: O(1)

class Solution {
    public boolean canMakeArithmeticProgression(int[] arr) {
        Arrays.sort(arr);
        int minus = arr[1] - arr[0];

        for (int i = 1; i < arr.length - 1; ++i) {
            if (arr[i + 1] - arr[i] != minus)
                return false;
        }
        return true;
    }
}
```

### 想法二:

做法: 找出陣列中最小值，把所有元素減去該最小值，每個減完的結果 mod 非零的最小結果應當都要為 0。測資中可能含有兩個為 0 的結果，因此要判斷是否只有一個 0，若有兩個且等差非 0，應當回傳 false。

程式:
```
// time:  O(n)
// space: O(n)

// 有空再做
```