`#include <map>`

map為關聯式容器(associated container)，元素不重複，有序，底層為紅黑樹。

multimap與map差在元素可以重複。

`#include <unordered_map>`

無序的map，搜尋更有效率，底層為hash表。

init
```c++
map<string, int> m;
```

change size
```c++

```

add, del ele
```c++
m.insert({"小明", 60});    // {"小明", 60}加到s
m["小明"] = 60;
m.erase(2);     // 
m.clear();      // 清空s
```

func
```c++
int i = m.size();       // 返回s已使用空間大小
bool b = m.count(3);    // 判斷3是否存在於s
map<int>::iterator iter = m.find(3);    // 回傳3在s內的位址
bool e = m.empty();     // 判斷s是否為空
```