# C++ 保留小数

头文件

```c++
#include <iomanip>
```

```c++
//第一种写法
cout << setiosflags(ios::fixed) << setprecision(n);
// n 代表保留几位小数
```

```c++
//第二种写法
cout.setf(ios::fixed);
cout << setprecision(n);
```

```c++
//第三种写法=
cout << fixed << setprecision(n);
```

- 以上的语句写一次就够了，对之后的数字都有效

例如：

```c++
#include <iostream>
#include <iomanip>　　　//设置必备的头文件
using namespace std;
int main()
{
	double s=12.345;
	cout<<setiosflags(ios::fixed)<<setprecision(2);
	cout<<s<<endl;　　　//输出12.35
	
	float pi=3.14159;
	cout<<pi<<endl;　　　//输出3.14
	
	return 0;
}

```



## 深入理解：

## 1.setprecision(n)

功能：控制浮点数显示的有效数字个数

![image-20211205090604644](C:\Users\44174\AppData\Roaming\Typora\typora-user-images\image-20211205090604644.png)

- 8-9行看出，只需要写一次就可以
- 8-10行看出，只是四舍五入修改了数字的显示方法，并不是修改原数字。从常识我们可以知道，如果12.345数字本身改变，那就是两位有效数字变为12，那从两位有效数字改为四位有效数字会变成12.00，而不是12.34.
- 11-12行可以看出如果要保留的位数过多，是不会补上0的
- 13行中可以看出，如果小数点前的位数多于你要保留的位数，则会使用科学计数法。

## **2.showpoint**

![image-20211205091003759](C:\Users\44174\AppData\Roaming\Typora\typora-user-images\image-20211205091003759.png)

```c
	double s=12.345;
	cout<<s<<endl;　　　//输出原数12.345
	cout<<setprecision(2);
	cout<<s<<endl;　　　//输出保留两位有效数字12
	cout.setf(ios::showpoint);//或者写cout<<setiosflags(ios::showpoint);
	cout<<s<<endl;　　　//输出保留两位有效数字外加一个小数点12.

```

## **3.fixed**

setprecision(n)和fixed(n)合用可以控制小数点后有几位

只要加上以下**任意一个**语句就可以

```c++
cout << setiosflags(ios::fixed);
cout.setf(ios::fixed);
cout << fixed;
```

此时要保留的位数多于数字原来的小数时，后面就会补上0

![image-20211205091420234](C:\Users\44174\AppData\Roaming\Typora\typora-user-images\image-20211205091420234.png)