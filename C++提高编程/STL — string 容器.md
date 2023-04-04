#  string容器

## 3.1.1 string 基本概念

string 类内部封装了很多成员方法

例如：查找find、拷贝copy、删除delete、替换replace、插入insert

string管理char*所分配的内存，不用担心复制越界和取值越界等，由类内部进行负责

## 3.1.2 string构造函数

构造函数原型：

- `string();`   						   //创建一个空的字符串 例如：string str；
- `string(const char* s); `         //使用字符串s初始化
- `string(const string& str);` //使用一个string对象初始化另一个string对象
- `string(int n, char c);`         //n个字符c组成的字符串

## 3.1.3 string赋值操作

- `string& operator=(const char*s);`
- `string& operator=(const string &s);`
- `string& operator=(char c);`
- `string& assign(const char *s);`
- `string& assign(const char *s, int n);` //把字符串s的前n个字符赋给当前的字符串
- `string& assign(const string &s);`//把字符串s赋给当前字符
- `string& assign(int n, char c);`//n个字符c组成的字符串

## 3.1.4 string字符串拼接

- `string& operator+=(const char* str);`
- `string& operator+=(const char c);`
- `string& operator+=( const string& str);`
- `string& append(const char* s);`
- `string& append(const char *s, int n);`
- `string& append(const string &s);`
- `string& append(const string &s, int pos, int n);` //字符串s中从pos开始的n个字符连接到字符串结尾 

## 3.1.5 string查找和替换

- `int find(const string& str, int pos = 0) const;`
- `int find(const char* s, int pos = 0) const;`
- `int find(const char* s, int pos, int n) const;`
- `int find(const char c, int pos = 0) const;`
- `int rfind(const string& str, int pos = npos) const;`//查找str最后一次出现的位置，从pos开始找
- `int rfind(const char* s, int pos = npos) const;`//查找s最后一次出现的位置，从pos开始查找
- `int rfind(const char* s, int pos, int n) const;`//从pos查找s的前n个字符最后一次位置
- `int rfind(const char c, int pos = 0) const;`
- `string& replace(int pos, int n, const string& str);`//替换从pos开始的n个字符为字符串str
- `string& replace(int pos, int n, const char* s);`//替换从pos开始的n个字符为字符串s

**find 从左往右查找；rfind从右往左查找**

## 3.1.6 string字符串比较

**比较方式：**

- 字符串ASCII码进行对比

` = -> 0` 

`> -> 1`

`< -> -1`

**函数原型:**

- `int compare(const string &s) const;`

- `int compare(const char *s) const;`

## 3.1.7 string字符存取

string中单个字符存取方式有两种

- `char& operator[](int n);`
- `char& at(int n);`

## 3.1.8 string插入和删除

- `string& insert(int pos, const char* s);`
- `string& insert(int pos, const string& str);`
- `string& insert(int pos, int n, char c);`//在指定位置插入n个字符c
- `string& erase(int pos, int n = npos);` //删除从pos开始的n个字符

## 3.1.9 string字串

**功能：**从字符串中获取想要的字串

**函数原型：**`string substr(int pos = 0, int n = npos) const;`

//返回由pos开始的n个字符组成的字符串