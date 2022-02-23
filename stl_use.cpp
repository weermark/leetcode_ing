#include <vector>

//init
vector<int> v;        // 創立vector:
vector<int> v{1,2,3}; // init，加入1,2,3
vector<int> v(5);     // init，初始空間為5單位
vector<int> v(5, 0);  // init，初始空間為5單位，值皆為0

// change size
v.reserve(20);        // v擴充空間到20單位(原內容保留)
v.resize(20);         // v空間改為20單位
v.shrink_to_fit();    // 減縮v空間到當前使用大小

// add, del ele
v.push_back(2);       // 把2加到vector後面
v.push_front(2);      // 把2加到vector前面
v.pop_back();         // 刪除v最後面一個元素
v.pop_front();        // 刪除v最前面一個元素
v.erase(3);           // 清除index 3
v.clear();            // 清空v

// func
int s = v.size();   // 返回v空間大小(len-1)
int c = v.capacity();	// 返回v當前容量(len)
bool e = v.empty();   // 判斷v是否為空
int a = v.at(3);      // 返回index 3的值
swap(v1, v2);         // 交換v1與v2(v1=原v2)

// iterator
vector<int>::iterator iter; // init
// or
auto iter = v.begin();

iter = v.begin();      // 返回指向v中第一个元素的迭代器。
iter = v.end();        // 返回指向v最後一个元素位置的後一个位置的迭代器。
iter = v.rbegin();     // 返回指向最後一个元素的迭代器。(iter++為往前迭代)
iter = v.rend();       // 返回指向第一个元素所在位置的前一个位置的迭代器。
iter = v.cbegin();     // const的begin()。(不能修改元素)
iter = v.cend();       // const的end()。(不能修改元素)
auto iter = v.crbegin();     // const的rbegin()。(不能修改元素)
auto iter = v.crend();      // const的rend()。(不能修改元素)
