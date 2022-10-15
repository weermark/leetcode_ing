`include <algorithm>`

```c++
// vector<int> v;
fill(v.begin(), v.end(), 0);     // v空間保留，值全部歸零
unique(v.begin(), v.end());      // 刪除重複元素
// 以下待完工
swap(v1, v2);       // 交換v1與v2
reverse(v.begin(), v.end());      // 反轉v
sort(v.begin(), v.end());           // 排序v
sort(v.begin(),v.end(),std::greater<int>())         // 逆排序v
count(v.begin(), v.end(), 5);                            // 在v找5

auto var = min();           // 找v內的最小值
auto var = max();           // 找v內的最大值
auto f = find(v.begin(), v.end(), 2);


```