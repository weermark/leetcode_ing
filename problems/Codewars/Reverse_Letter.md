# Reverse Letter

段位: 7

定義: 輸入一字串，回傳翻轉後的字串，該字串不含有非字母的元素 (字串內元素皆為字母)。

做法: 先翻轉字串，再去除非字母元素。可參考 [LeetCode 344 反轉字串] 以及 [LeetCode 27 移除元素]。

程式:
```kotlin
// time:  O(n)
// space: O(n)

fun reverseLetter(str: String): String {
    // 在 kotlin 中轉陣列才可用中括號與下標取索引，較方便
    var s = CharArray(str.length)
    var left = 0
    var right = s.size - 1
    // 翻轉字串
    while (left <= right) {
        val temp = str[left]
        s[left] = str[right]
        s[right] = temp
        left += 1
        right -= 1
    }

    // 利用快慢指針去除非字母元素
    left = 0
    right = 0
    // 紀錄去除元素數量
    var rewrite = 0
    while (right < s.size) {
        // right 所在索引值元素非字母，則加速 right 前進
        while (right < s.size && s[right] !in 'a'..'z' && s[right] !in 'A'..'Z') {
            rewrite += 1
            right += 1
        }       
        if (right < s.size) {
            s[left] = s[right] 
        }
        left += 1
        right += 1
    }
    // s 經過去除，長度應變，然現在長度未變，最後面含有不應存在之元素，因此建立新陣列，複製應有長度之元素之陣列
    var res = s.copyOf(s.size - rewrite)
    return String(res)
}
```