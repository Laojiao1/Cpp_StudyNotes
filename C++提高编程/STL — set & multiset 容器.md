# set & multiset 容器

## 3.8.1 set基本概念

**简介：**

- 所有元素都会在插入时自动被排序

**本质：**

- set/multiset **属于关联式容器**，底层结构式用**二叉树**实现.

**set和multiset区别：**

- set不允许容器中有重复的元素
- multiset允许容器中有重复的元素

## 3.8.2 set构造和赋值

功能描述：创建set容器以及赋值

构造：

- `set<T> st;`//默认构造
- `set(const set &st);`//拷贝构造

赋值：

- `set& operator=(const set &st);`//重载等号操作符

**示例：**

```c++
void printSet(set<int> &s) {
    for(set<int>::iterator it = s.begin(); it != s.end(); it++) {
        cout << *it <<  " ";
    }
    cout << endl;
}
void test01() {
    set<int> s1;
    //插入数据时只有insert方式
    s1.insert(10);
    s1.insert(40);
    s1.insert(30);
    s1.insert(20);
    s1.insert(30);
    //遍历容器
    printSet(s1);
    //输出10 20 30 40
    //特点：所有的元素在插入的时候会被自动排序
    //set容器不允许插入重复的值
    
    //拷贝构造
    set<int> s2(s1);
    printSet(s2);
    
    //赋值
    set<int> s3;
    s3 = s2;
    printSet(s3);
}
```

# 3.8.3 set大小和交换

**功能描述：**

- 统计set容器大小以及交换set容器

**函数原型：**

- `size();`
- `empty();`
- `swap(st);`

# 3.8.4 set插入和删除

**功能描述：**

- set容器进行插入数据和删除数据

**函数原型：**

- `insert(elem);`
- `clear();`
- `erase(pos);`
- `erase(beg, end);`
- `erase(elem);`

# 3.8.5 set查找和统计

**功能描述：**

- 对set容器进行查找数据以及统计数据

**函数原型：**

- `find(key);`//查找key是否存在，若存在，返回该键的元素的迭代器；若不存在，返回set.end();
- `count(key);`//统计key元素的个数

# 3.8.6 set和multiset区别

**学习目标：**

- 掌握set和mutiset的区别

**区别：**

- set不可以插入重复数据，而multiset可以
- set插入数据的同时会返回插入结果，表示插入是否成功
- multiset不会检测数据，听此可以插入重复数据

```c++
void test01() {
    set<int> s;
    pair<set<int>::iterator, bool> ret = s.insert(10);
    if(ret.second) {
        cout << "第一次插入成功" << endl;
    } else {
        cout << "第一次插入失败" << endl;
    }
    //第一次成功
    ret = s.insert(10);
    if(ret.second) {
        cout << "第二次插入成功" << endl;
    } else {
        cout << "第二次插入失败" << endl;
    }
    //第二次失败
    
    multiset<int> ms;
    //允许插入重复的值
    ms.insert(10);
    ms.insert(10);
    
    for(mutiset<int>::iterator it = ms.begin(); it != ms.end(); it++) {
        cout << *it << endl;
    }
    cout << endl;
    //输出：10 10
    //允许插入多个重复数据
}
```

# 3.8.7 pair对组的创建

**功能描述：**

- 成对出现的数据，利用对组可以返回两个数据

**两种创建方式：**

- `pair<type, type>p (value, value2);`
- `pair<type, type> p = make_pair(value1, value2);`

**示例：**

```c++
void test01() {
    //第一种
    pair<string, int> p("Tom", 18);
    cout << "姓名：" << p.first << " 年龄：" << p.second << endl;
    
    //第二种方式
    pair<string, int> p2 = make pair("Jerry", 30);
    cout << "姓名：" << p.first << " 年龄：" << p.second << endl;
}
```

# 3.8.8 set容器排序

学习目标：

- set容器默认排序为从小到大，掌握如何改变排序规则

主要技术点：

- 利用仿函数，可以改变排序规则

**示例一** 	set存放内置数据类型

```c++
class MyCompare {
    public:
    bool operator()(int v1, int v2) {
        return v1 > v2;
    }
}
void test01() {
    set<int> s1;
    s1.insert(10);
    s1.insert(30);
    s1.insert(40);
    s1.insert(20);
    for(set<int>::iterator it = s.begin(); it != s.end(); it++) {
        cout << *it <<  " ";
    }
    cout << endl;
    //默认升序排序输出
    
    //指定排序规则为降序
    set<int, MyCompare> s2;
    s2.insert(10);
    s2.insert(30);
    s2.insert(40);
    s2.insert(20);
    
}
```

**示例二**	自定义数据类型指定排序规则

```c++
class Person {
    public:
    Person(string name, int age) {
        this->m_name = name;
        this->m_age = age;
    }
    int m_age;
    int m_name;
}
class ComparePerson {
    public:
	bool operator()(const Person&p1, const Person&p2) {
        //按照年龄 降序
        return p1.m_age > p2.m_age;
    }
}
void test01() {
    //自定义数据类型都会指定排序规则
    set<Person> s;
    
    Person p1("Tom", 10);
    Person p2("Bob", 20);
    Person p3("Jack", 30);
    
    s.insert(p1);
    s.insert(p2);
    s.insert(p3);
    
    
}
```

