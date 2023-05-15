# 1721. Swapping Nodes in a Linked List

[leetcode題目連結](https://leetcode.com/problems/swapping-nodes-in-a-linked-list/description/)

定義: 給一鏈結頭節點，交換鏈結中第 k 個節點與倒數第 k 個節點的值。回傳頭節點。

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
```

## 解題

### 想法一:

做法: 一開始，保存第 k 個節點。迭代中保持兩節點間距離 k 個節點，即可取得倒數第 k 個節點。最後交換第 k 個節點與倒數第 k 個節點的值。

程式:
```java
// success
// time:  O(n)
// space: O(1)

class Solution {
    public ListNode swapNodes(ListNode head, int k) {
        ListNode cur = head;
        ListNode prev = head;

        // 把 cur 移動 k 個節點，並保存該節點
        for (int i = 1; i < k; ++i) {
            cur = cur.next;
        }
        ListNode kthNode = cur;
        
        // 當 cur 移到尾時，prev 所在節點是倒數第 k 個節點
        while (cur.next != null) {
            cur = cur.next;
            prev = prev.next;
        }
        // 交換第 k 個節點與倒數第 k 個節點的值
        int tmp = kthNode.val;
        kthNode.val = prev.val;
        prev.val = tmp;

        return head;
    }
}
```