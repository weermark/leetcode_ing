`#include <set>`

set 為關聯式容器(associated container)，元素不重複，有序，底層為紅黑樹。

multiset 與 set 差在元素可以重複。

`#include <unordered_set>`

無序的 set，搜尋更有效率，底層為 hash 表。

init
```c++
set<int> s;
```

change size
```c++

```

add, del ele
```c++
s.insert(2);    // 2 加到 s
s.erase(2);     // 從 s 中刪除 2
s.clear();      // 清空 s
```

func
```c++
int i = s.size();       // 返回 s 已使用空間大小
bool b = s.count(3);    // 判斷 3 是否存在於 s
set<int>::iterator iter = s.find(3);    // 回傳 3 在 s 內的位址
bool e = s.empty();     // 判斷 s 是否為空
```