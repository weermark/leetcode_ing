# 21. Merge Two Sorted Lists

[leetcode題目連結](https://leetcode.com/problems/merge-two-sorted-lists/)

定義:

解釋: 合併兩個鏈結。

## 解題

### 想法一:

做法:

程式:

```java
// success
// time:  O(n + m)
// space: O(1)

// java
class Solution {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode dummyHead = new ListNode(-1);
        ListNode cur = dummyHead;
        while(list1 != null && list2 != null){
            if(list1.val <= list2.val){
                cur.next = list1;
                cur = cur.next;
                list1 = list1.next;
            }
            else if(list1.val > list2.val){
                cur.next = list2;
                cur = cur.next;
                list2 = list2.next;
            }
        }
        while(list1 != null){
            cur.next = list1;
            cur = cur.next;
            list1 = list1.next;
        }
        while(list2 != null){
            cur.next = list2;
            cur = cur.next;
            list2 = list2.next;
        }
        return dummyHead.next;
    }
}
```

省思: 