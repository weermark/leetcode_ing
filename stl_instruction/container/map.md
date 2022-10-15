`#include <map>`

map 為關聯式容器(associated container)，元素不重複，有序，底層為紅黑樹。

multimap 與 map 差在元素可以重複。

`#include <unordered_map>`

無序的 map，搜尋更有效率，底層為 hash 表。

init
```c++
map<string, int> m;
```

change size
```c++

```

add, del ele
```c++
m.insert({"小明", 60});    // {"小明", 60} 加到 s
m["小明"] = 60;             // 新增 key 小明，value 為 60
m.erase(2);     // 清除 key 為 2 的 pair
m.clear();      // 清空 s
```

func
```c++
int i = m.size();       // 返回 s 已使用空間大小
bool b = m.count(3);    // 判斷 3 是否存在於 s
map<int>::iterator iter = m.find(3);    // 回傳 3 在 s 內的位址
bool e = m.empty();     // 判斷 s 是否為空
```