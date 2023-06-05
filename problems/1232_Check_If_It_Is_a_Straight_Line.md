# 1232. Check If It Is a Straight Line

[leetcode題目連結](https://leetcode.com/problems/check-if-it-is-a-straight-line/description/)

定義:

解釋: 

## 解題

### 想法一:

做法: 求取兩點間的斜率，並迭代全部點，點之間的斜率都要相同。

這題要注意，線段平行 x 軸，斜率為 0；線段平行 y 軸，斜率為無限大。

另外，測資中，點的數值並不是遞增，會導致取不同點作為基準而有不同斜率 (會有正有負)。

程式:
```java
// success
// time:  O(n)
// space: O(1)

class Solution {
    public boolean checkStraightLine(int[][] coordinates) {
        double m = getSlope(coordinates[0], coordinates[1]);

        for (int i = 1; i < coordinates.length; ++i) {
            double cur_m = getSlope(coordinates[0], coordinates[i]);
            if (m != cur_m) {
                return false;
            }
        }
        return true;
    }

    /**
    * 取得兩個點的斜率
    */
    private double getSlope(int[] point1, int[] point2) {
        // 設定 y 值大的點為 point2
        if (point2[1] < point1[1]) {
            final int[] tmp = point1;
            point1 = point2;
            point2 = tmp;
        }
        int x = point2[0] - point1[0];
        int y = point2[1] - point1[1];
        
        // 線段平行 x 軸
        if (x == 0)
            return 0;
        // 線段平行 y 軸
        else if (y == 0)
            return Double.MAX_VALUE;
        else
            return (double)y / x;
    } 
}
```