`#include <vector>`

init
```c++
vector<int> v;        // 創立vector:
vector<int> v{1,2,3}; // init，加入1,2,3
vector<int> v(5);     // init，初始空間為5單位，值預設為0
vector<int> v(5, 0);  // init，初始空間為5單位，值皆為0
```

change size
```c++
v.reserve(20);        // v擴充空間到20單位(不建立元素，原空間有元素則保留)
v.resize(20);         // v空間改為20單位(移除沒空間存的元素)
v.shrink_to_fit();    // 減縮v空間到當前使用大小
```

add, del ele
```c++
v.push_back(2);       // 把2加到vector後面
v.push_front(2);      // 把2加到vector前面
v.insert(v.begin() + 3, 5)      // 把5插到v[3];
v.pop_back();         // 刪除v最後面一個元素
v.pop_front();        // 刪除v最前面一個元素
v.erase(3);           // 清除index 3
v.clear();            // 清空v
```

func
```c++
int s = v.size();       // 返回v已使用空間大小(等於len)
int c = v.capacity();  //返回v總空間大小
bool e = v.empty();   // 判斷v是否為空
int a = v.at(3);      // 返回index 3的值
```

補充:
```c++
vector<vector<int> > v; // 創立二維vector(c++98)
vector<vector<int>> v(10, vector<int>(6, 0)); // 創立二維vector(c++11)，初始空間為10X6，值全為0
vector<int> v[10];      //創立內含10個vector的陣列
```