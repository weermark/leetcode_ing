init
```c++
int i = str.length();   // 回傳 str 長度
int i = str.size();     // 回傳 str 長度

str.find("aa");     // 回傳 aa 所在位置

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
ss << tmp;
ss >> c >> num;
```

```c++
ss.eof();       // 回傳 ss 是否觸底
```
