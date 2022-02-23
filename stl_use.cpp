#include <vector>

vector<int> v;        // 創立vector:

vector<int> v{1,2,3}; // init，加入1,2,3

vector<int> v(5);     // init，初始空間為5單位

vector<int> v(5, 0);  // init，初始空間為5單位，值皆為0

v.reserve(20);        // v擴充空間到20單位(原內容保留)


v.push_back(2);       // 把2加到vector後面

v.push_front(2);      // 把2加到vector前面


int s = v.size();   // 返回v空間大小(len-1)

int c = v.capacity();	// 返回v當前容量(len)

bool e = v.empty();   // 判斷v是否為空
