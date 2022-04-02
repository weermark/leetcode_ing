init
```c++
int i = str.length();   // 回傳str長度
int i = str.size();     // 回傳str長度

str.find("aa");     // 回傳aa所在位置

// str[i] === char 
```


# stringstream

init
```c++
sstream ss;
```

buff
```c++
int num;
char c;
string tmp;

cin >> tmp;
tmp >> ss;
ss >> c >> num;
```

```c++
ss.eof();       //ss是否到底
```
