# list 容器

## 3.7.1 list基本概念

**功能：**将数据进行链式存储

**链表**是一种物理存储单元上非连续的存储结构，数据元素的逻辑顺序是通过链表中的指针链接实现的



链表的组成：链表由一系列**结点**组成

结点的组成：一个是存储数据元素的**数据域**，另一个是存储下一个结点地址的**指针域**

STL中链表是一个==双向循环链表==

![image-20220214091628946](C:\Users\44174\AppData\Roaming\Typora\typora-user-images\image-20220214091628946.png)

由于链表的存储方式并不是连续的内存空间，因此链表list中的迭代器只支持前移和后移，属于==双向迭代器==

list优点：

- 采用动态存储分配，不会造成内存浪费和溢出
- 链表执行插入和删除操作十分方便，修改指针即可，不需要移动大量元素

list缺点：

- 链表灵活，但是空间（指针域）和时间（遍历）额外耗费较大

list有一个重要的性质，插入操作和删除操作都不会造成原有list迭代器的失效，这在vector是不成立的

## 3.7.2 list构造函数

**功能：**

- 创建list容器

**函数原型：**

- `list<T> lst;`//list采用模板类实现，对象的默认构造形式
- `list(beg, end);`//构造函数将[beg, end)区间中的元素拷贝给本身
- `list(n, elem);`//构造函数将n个elem拷贝给本身
- `list(const list &lst);`//拷贝构造函数

**示例：**

```c++
void printList(const list<int> &L) {
    for(list<int>::iterator it = L.begin(); it != L.end(); it++) {
        cout << *it << " ";
	}
    cout << endl;
}
void test01() {
    list<int> L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    printList(L);
    
    //区间构造
    list<int>L2(L1.befin(), L1.end());
    printList(L2);
    
    //拷贝构造
    list<int> L3(L2);
    printList(L3);
    
    //n个elem
    list<int> L4(10, 1000);
    printList(L4);
    
}
```

## 3.7.3 list 赋值和交换

**功能描述：**

- 给list容器进行赋值，以及交换list容器

**函数原型：**

- `assign(beg, end);`//将[beg, end)区间中的数据拷贝赋值给本身
- `assign(n, elem);`//将n个elem拷贝赋值给本身
- `list& operator=(const list &lst);` //重载等号操作符
- `swap(lst);`//将lst与本身的元素互换

**示例：**

```c++
void test01() {
    list<int> L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    
    //operator=赋值
    list<int> L2;
    L2 = L1;
    
    list<int> L3;
    L3.assign(L2.begin(), L2.end());
    
    list<int> L4;
    L4.assign(10, 100);
    
}
//交换
void test02() {
    list<int> L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    
    list<int> L2;
    L2.assign(10, 100);
    L1.swap(L2);
    
}
```

## 3.7.4 list 大小操作

**功能描述：**

- 对list容器的大小进行操作

**函数原型：**

- `size();` //返回容器中元素的个数
- `empty();`//判断容器是否为空
- `resize(num);`//重新指定容器长度为num，若容器变长，则以默认值填充新位置；若容器变短，则末尾超出容器长度的元素被删除
- `resize(num, elem);`//重新指定容器长度为num，若容器变长，则以elem值填充新位置；若容器变短，则末尾超出容器长度的元素被删除

##  3.7.5 list插入和删除

**功能描述：**

- 对list容器进行数据插入和删除

**函数原型：**

- `push_back(elem);`
- `pop_back();`
- `push_front(elem);`
- `pop_front();`
- `insert(pos, elem);`//在pos位置插入elem元素的拷贝，返回新数据的位置
- `insert(pos, n, elem);`//在pos位置插入n个elem数据，无返回值
- `insert(pos, beg, end);`//在pos位置插入区间内的数据，无返回值
- `clear();`
- `erase(beg, end);`
- `erase(pos);`
- `remove(elem);`//删除容器中所有与elem值匹配的元素

## 3.7.6 list 数据存取

**函数原型：**

- `front();`
- `back();`

**注意：**

- 不可以用`[]`访问list容器中的元素

- 不可以用at方式访问list容器中的元素

- 原因是list本质是链表，并不是连续的线性空间存储数据

- `it = it+1`是错误的，不可以跳跃性访问，即使是+1

- 验证迭代器是不是支持随机访问的

  - ```c++
    list<int>::iterator it = L1.begin();
    it++;
    it--;
    it = it + 1;
    //看这几个语句是否正确即可
    ```

## 3.7.7 反转和排序

**功能描述：**

- 将容器中的元素反转，以及将容器中的数据进行排序

**函数原型：**

- `reverse();`//反转链表
- `sort();`//链表排序

**示例：**

```c++
void test01() {
    //反转
    list<int> L1;
    L1.push_back(10);
    L1.push_back(30);
    L1.push_back(20);
    L1.push_back(40);
    printList(L1);
    //10 30 20 40
    
    L1.reverse();
    printList(L1);
    //40 20 30 10   
}

bool MyCompare(v1, v2) {
    //降序 让第一个数>第二个数
    return v1 > v2;
}

//排序
void test02() {
    list<int> L1;
    L1.push_back(10);
    L1.push_back(30);
    L1.push_back(20);
    L1.push_back(40);
    printList(L1);
    //10 30 20 40
    
    //所有不支持随机访问的迭代器，不可以用标准算法
    //不支持随机访问迭代器的容器，内部会提供对应一些算法
    //sort(L1.begin(), L1.end());
    
    L1.sort();
    printList(L1);
    //10 20 30 40
    //默认升序
    
    //自定义降序
    L1.sort(MyCompare);
    printList(L1);
    //40 30 20 10
}
```

