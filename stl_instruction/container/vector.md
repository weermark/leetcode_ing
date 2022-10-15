`#include <vector>`

vector 為動態陣列。

init
```c++
vector<int> v;        // 創立 vector
vector<int> v{1,2,3}; // init，加入 1,2,3
vector<int> v = {1,2,3}; // init，加入 1,2,3
vector<int> v(5);     // init，初始空間為 5 單位，值預設為 0
vector<int> v(5, 0);  // init，初始空間為 5 單位，值皆為 0
```

change size
```c++
v.reserve(20);        // v 擴充空間到 20 單位(不建立元素，原空間有元素則保留)
v.resize(20);         // v 空間改為 20 單位(建立元素，移除沒空間存的元素)
v.shrink_to_fit();    // 減縮 v 的空間到當前使用大小
```

add, del ele
```c++
v.push_back(2);                 // 把 2 加到 vector 後面
v.insert(v.begin() + 3, 5);      // 把 5 插入到 v[3]
v.pop_back();                   // 刪除 v 最後面一個元素
v.erase(v.begin());             // 清除位置 v.begin()
v.clear();                      // 清空 v
```

func
```c++
int e = v[2];           // 取得 v 索引 2 的元素
int s = v.size();       // 返回 v 已使用空間大小 (等於len)
int c = v.capacity();  //返回 v 總空間大小
bool e = v.empty();   // 返回 v 是否為空
int a = v.at(3);      // 返回索引 3 的值
```

補充:
```c++
vector<vector<int> > v; // 創立二維vector (c++98)
vector<vector<int>> v(10, vector<int>(6, 0)); // 創立二維vector (c++11)，初始空間為 10X6，值全為 0
vector<int> v[10];      //創立內含 10 個 vector 的陣列
```
