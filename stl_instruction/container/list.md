`#include <list>`

list 為雙向鏈結  (double linked list)。

init
```c++
list<int> mylist;           // 創立 list
list<int> mylist = {1,2,3}   // init，加入 1,2,3
list<int> myList{1,2,3};     // init，加入 1,2,3
```

add, del ele
```c++
mylist.push_front(2) // 把 2 加到 list 前面
mylist.push_back(2)  // 把 2 加到 list 後面
mylist.pop_front()  // 刪除 list 最前面一個元素
mylist.pop_back()  // 刪除 list 最後面一個元素
mylist.clear();     // 清空 list
```

func
```c++
int e = mylist.front(); // 取得 list 最前面的元素
int e = mylist.back(); // 取得 list 最後面的元素
int s = v.size();       // 返回 list 已使用空間大小 (等於len)
bool e = v.empty();   // 返回 list 是否為空
```

補充:
```c++

```