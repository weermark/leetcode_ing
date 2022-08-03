# 202. Happy Number

[leetcode題目連結](https://leetcode.com/problems/happy-number/)

解釋: 判斷 n 是否是快樂數，如果是，回傳 true，否則 false。

補充： 快樂數為數值的各個位數拆開平方後相加，不斷重複此行為，最後會等於 1。

## 解題

### 想法一:

做法: 建立 hashSet，每次計算完的結果加入 set，如計算出的結果在 set 中出現過，回傳 false，或直到結果是快樂數。

程式:

```c++
// success
// n 為計算過程中產生的不循環數數量
// time:  O(n)
// space: O(n)

class Solution {
public:
    int getSum(int n){
        int sum = 0;
        while(n){
            int mod = n % 10;
            sum += (mod * mod);
            n /= 10;
        }
        return sum;
    }
    
    bool isHappy(int n) {
        unordered_set<int> s;
        while(1){
            int sum = getSum(n);
            if(s.count(sum))
                return false;
            else if(sum == 1)
                return true;
            s.insert(sum);
            n = sum;
        }
        return false;
    }
};

```

省思: 計算前無法得知不循環數數量，n會隨不循環數數量增加而線性成長。


