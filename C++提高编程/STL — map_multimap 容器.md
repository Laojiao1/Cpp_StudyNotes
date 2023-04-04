# map/multimap 容器

## 3.9.1 map基本概念

**简介:**

- map中所有元素都是pair
- pari中第一个元素为key（键值），起到索引的作用，第二个元素为value（实值）
- 所有元素都会根据元素的键值自动排序

**本质：**

- map/multimap**属于关键式容器**，底层结构是用二叉树实现

**优点：**

- 可以根据key值快速找到value值

**map和multimap区别** :

- map不允许容器中有重复的key值元素
- multimap允许容器中有重复key值元素

## 3.9.2 map构造和赋值

**功能描述：**

- 对map容器进行构造和赋值操作

**函数原型：**

**构造：**

- `map<T1, T2> mp;` //map默认构造函数
- `map(const map &mp);`//拷贝构造函数

**赋值：**

- `map& operator=(const map &mp);`//重载等号操作符

**示例：**

```c++
void printMap(map<int, int>& m) {
    for(map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
        cout << "key = " << (*it).first << "value = " << it->second << endl;
    }
    cout << endl;
}
void test01() {
    map<int, int> m;
    m.insert(pair<int, int>(1, 10));
    m.insert(pair<int, int>(2, 20));
    m.insert(pair<int, int>(3, 30));
    
    printMap(m);
    //打印出的结果按照key值排序后输出
    
    //拷贝构造
    map<int, int> m2(m);
    printMap(m2);
    
    //赋值
    map<int, int> m3;
    m3 = m2;
    printMap(m3);
}
```

## 3.9.3 map大小和交换

**功能描述：**

- 统计map容器大小以及交换map容器

**函数原型：**

- `size();`//返回容器中元素的数目
- `empty();`//判断容器是否为空
- `swap(st);`//交换两个集合容器

## 3.9.4 map插入和删除

**功能描述：**

- map容器进行插入数据和删除数据

**函数原型：**

- `insert(elem);` //在容器中插入元素
- `clear();`//清除所有元素
- `erase(pos);`//删除pos迭代器所指的元素，返回下一个元素的迭代器
- `erase(beg, end);`//删除区间[beg, end）的所有元素，返回下一个元素的迭代器
- `erase(key);`//删除容器中值为key的元素

## 3.9.5 map查找和统计

**功能描述：**

- 对map容器进行查找数据以及统计数据

**函数原型：**

- `find(key);`//查找key是否存在，返回该键元素的迭代器；若不存在，返回set.end();
- `count(key);`//统计key中元素的个数

**示例：**

```c++
void test01() {
    map<int, int> m;
    m.insert(pair<int, int>(1, 10));
    m.insert(pair<int, int>(2, 20));
    m.insert(pair<int, int>(3, 30));
    
    //查找
    map<int, int>::iterator pos = m.find(3);
    if(pos != m.end())
        cout << "查找到该元素key = " << (*pos).first << "value = " << pos->second << endl;
    else 
        cout << "为找到该元素" << endl;
    
    //统计
    //map不允许插入两个key值一样的元素,因此count的值要么是1要么是0
    //multimap的count统计可能大于1
    int num = m.count(3);
    cout << "num = " << num << endl;
} 
```

## 3.9.6 map容器排序

**学习目标：**

- map容器默认排序规则为 按照key值进行从小到大排序，掌握如何改变排序规则

**主要技术点：**

- 利用仿函数，可以改变排序规则

**示例：**

```c++
class MyCompare {
    public:
    bool operator()(int v1, int v2) {
  		//降序
        return v1 > v2;
    }
};
void test01() {
    map<int, int, MyCompare> m;
    m.insert(pair<int, int>(1, 10));
    m.insert(pair<int, int>(2, 20));
    m.insert(pair<int, int>(3, 30));
    m.insert(pair<int, int>(4, 40));
    m.insert(pair<int, int>(5, 50));
    
    for(map<int, int, MyCompare>::iterator it = m.begin(); it != m.end(); it++) {
        cout << "key = " << (*it).first << "value = " << 	it->second << endl;
   	}
    cout << endl;	
}
```

