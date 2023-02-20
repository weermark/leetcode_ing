# 26. Remove Duplicates from Sorted Array

[leetcode題目連結](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)

定義: 給一有重複元素的有序整數陣列 nums，應把陣列覆寫成無重複元素，並回傳無重複元素的新陣列的長度。

## 解題

### 想法一:

做法: 雙指針。每次循環用 nums[fast] 覆寫 nums[slow]，並判斷 nums[fast] 與 nums[fast + 1] 是否相等，並依照判斷結果更改 slow 位置。

程式:
```python
// success
// time:  O(n)
// space: O(1)

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        # 快慢指針
        slow, fast = 0, 0
        # 判斷是小於 len - 1 而非 len 是為了避免 fast == len - 1 時 if 判斷越界
        while fast < len(nums) - 1:
            nums[slow] = nums[fast]
            # 兩位置元素相等，因此讓 slow 停留
            if nums[fast] != nums[fast + 1]:
                slow += 1
            fast += 1
        # while 沒處理到 nums[len - 1]，補處理
        nums[slow] = nums[fast]
        return slow + 1
```

### 想法二: 

做法: 簡化想法一

程式:
```python
// success
// time:  O(n)
// space: O(1)

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        # 快慢指針
        slow, fast = 0, 1
        while fast < len(nums):
            if nums[slow] != nums[fast]:
                slow += 1
                nums[slow] = nums[fast]
            fast += 1

        return slow + 1
```