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
// time:  O(n)
// space: O(n)

// java
class Solution {
    private ListNode lastNode = null;

    private boolean nodeIsNull(ListNode node){
        return (node == null);
    }
    
    private void nodeLinkToNode(ListNode frontNode, ListNode backNode){
        frontNode.next = backNode;
    }

    private boolean nodeIsLastOne(ListNode node){
        return (node.next == null);
    }

    public ListNode reverseListUtil(ListNode curNode) {
        // base case
        if(nodeIsLastOne(curNode)){
            lastNode = curNode;
            return curNode;
        }
        // recursive case
        ListNode nextNode = reverseListUtil(curNode.next);
        
        nodeLinkToNode(nextNode, curNode);
        nodeLinkToNode(curNode, null);
        return curNode;
    }

    // main
    public ListNode reverseList(ListNode head) {
        if(nodeIsNull(head))    return null;

        reverseListUtil(head);
        return lastNode;
    }
}
```

省思: 可再優化。

<br/>

### 想法二:

做法: 迭代加上三指針。一個指向要被指向的節點，一個指向要改變 next 的節點，一個指向原本 next 指向的節點。

程式:

```java
// success
// time:  O(n)
// space: O(1)

// java
class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode pre = null;
        ListNode cur = head;
        ListNode tmp = null;
        while(cur != null){
            tmp = cur.next;
            cur.next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
}
```

省思: 