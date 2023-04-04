# C++ 头文件常用函数

## cctype

1、`isalpha(x)` 判断x是否为字母

2、`isdigit(x)` 判断x是否为数字

3、`islower(x)` 判断x是否为小写字母

4、`isupper(x)` 判断x是否为大写字母

5、`isalnum(x)` 判断x是否为字母或数字

6、`ispunct(x)` 判断x是否为标点符号

7、`isspace(x)` 判断x是否为空格

对于以上函数，如果x符合条件的话，均会返回`true`，否则返回`false`

8、`toupper(x)` 如果x是小写字母，将其转换成大写字母

9、`tolower(x)` 如果x是大写字母，将其转换成小写字母

## string

1、`s.erase(x,y)` 表示将字符串s从x位置起删除y个字符

2、`s.insert(x,y)` 表示将字符串y（或字符y）插入到s的x位置处

3、`s.push_back(x)` 表示在s的末尾插入字符x

4、`reverse(s.begin(),s.end())` 将字符串s翻转

5、`atoi(x)` 把x字符串转换为一个整数 (int)

6、`getline(cin, str)` 读入一串字符，忽略换行

7、`find(str, position)` str ：要找的元素，position：从哪个位置开始找（可以不填，默认从0开始），返回值为最早出现目标字符的位置，当没有找到目标字符时返回string::npos(-1)