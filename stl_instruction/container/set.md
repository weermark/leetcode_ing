`#include <set>`

set為關聯式容器(associated container)，元素不重複，有序，底層為紅黑樹。

mutliset與set差在元素可以重複。

`#include <unordered_set>`

無序的set，搜尋更有效率，底層為hash表。

init
```c++
set<int> s;
```

change size
```c++

```

add, del ele
```c++
s.insert(2);    // 2加到s
s.erase(2);     // 從s中刪除2
s.clear();      // 清空s
```

func
```c++
int i = s.size();       // 返回s已使用空間大小
bool b = s.count(3);    // 判斷3是否存在於s
set<int>::iterator iter = s.find(3);    // 回傳3在s內的位址
bool e = s.empty();     // 判斷s是否為空
```