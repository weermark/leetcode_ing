# 765. Couples Holding Hands

[leetcode題目連結](https://leetcode.com/problems/couples-holding-hands/description/)

定義: 給一隨機排序整數陣列，兩相鄰整數 (ex. 0, 1) 為情侶，回傳最少需要換幾次才能讓每對情侶相鄰而坐。

## 解題

### 想法一:

做法: 并查集。需互換的情侶對一定會成環。而兩對情侶需換一次，三對情侶需換兩次，依此類推。因此只要找出有幾個環，再用情侶對數減去環數即為答案。

程式:
```java
// success
// time:  O(nlgn)
// space: O(n)

class Solution {
    public int minSwapsCouples(int[] row) {
        int len = row.length;
        UnionFind uf = new UnionFind(len);
        // 把每對情侶加入并查集
        for (int i = 0; i < len; i += 2) {
            // 同一對情侶有相同編號，才能成環
            uf.union(row[i] / 2, row[i + 1] / 2);
        }
        return len - uf.getCount();
    }

    private class UnionFind {
        // 記錄連通分量
        private int count;
        // 紀錄每個節點的父節點
        private int[] parent;

        public UnionFind(int n) {
            this.count = n;
            this.parent = new int[n];
            for (int i = 0; i < n; ++i) {
                // 初始化，父節點為自己
                this.parent[i] = i;
            }
        }

        // 回傳根節點
        private int find(int x) {
            if (x == parent[x])
                return x;
            // 路徑壓縮，根節點之下的節點全部直接指向跟節點，節省時間
            parent[x] = find(parent[x]);
            return parent[x];
        }

        // 連結節點 p 和節點 q
        public void union(int p, int q) {
            int rootP = find(p);
            int rootQ = find(q);
            // 根節點相同，代表已連結，不須動作
            if (rootP == rootQ)
                return;
            // 連結兩節點
            this.parent[rootP] = q;
            // 連通
            --count;
        }

        // public boolean isConnected(int p, int q) {
        //     return find(p) == find(q);
        // }

        public int getCount() {
            return this.count;
        }
    }
}
```