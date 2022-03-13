>以一個物件表現出容器元素的位置

iterator
```c++
vector<int>::iterator iter; // init
// or
auto iter = v.begin();

iter = v.begin();      // 返回指向v中第一个元素的迭代器。
iter = v.end();        // 返回指向v最後一个元素位置的後一个位置的迭代器。
iter = v.rbegin();     // 返回指向最後一个元素的迭代器。(iter++為往前迭代)
iter = v.rend();       // 返回指向第一个元素所在位置的前一个位置的迭代器。
iter = v.cbegin();     // const的begin()。(不能修改元素)
iter = v.cend();       // const的end()。(不能修改元素)
iter = v.crbegin();     // const的rbegin()。(不能修改元素)
iter = v.crend();      // const的rend()。(不能修改元素)
```

loop, use iter
```c++
for(auto iter = v.begin(); iter != v.end(); ++iter){};  // normal for loop(++iter效率會比iter++好)

for(auto iter : v){};     // range base for loop

auto iter = v.begin();
while(iter != v.end()){ iter++ };
```