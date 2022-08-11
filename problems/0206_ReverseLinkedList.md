# 206. Reverse Linked List 

[leetcode題目連結](https://leetcode.com/problems/reverse-linked-list/)

定義:

解釋: 

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

做法: 遞迴。在後序改變節點的 next。

程式:

```java
// success
// time:  O()
// space: O()

// java
class Solution {
    public ListNode res = null;
    public ListNode traverse(ListNode head) {
        if(head == null)    return null;
        System.out.println(head.val);
        ListNode nextNode = traverse(head.next);
        if(nextNode == null){
            res = head;
            return head;
        }
        nextNode.next = head;
        return head;
    }
    public ListNode reverseList(ListNode head) {
        if(head == null)    return null;
        traverse(head);
        head.next = null;
        return res;
    }
}
```

省思: 可在優化。

<br/>

### 想法二:

做法: 迭代加上三指針。一個指向要被指向的節點，一個指向要改變 next 的節點，一個指向原本 next 指向的節點。

程式:

```
// success
// time:  O()
// space: O()


```

省思: 