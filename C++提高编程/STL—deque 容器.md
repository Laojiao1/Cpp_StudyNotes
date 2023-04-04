# deque 容器

## 3.3.1 deque 容器基本概念

**功能：**

- 双端数组，可以对头端进行插入删除操作

**deque与vector的区别：**

- vector对于头部的插入删除效率低，数据量越大，效率越低
- deque相对而言，对头部的插入删除速度会比vector快
- vector访问元素时的速度会比deque快，这和两者内部实现有关

![image-20220207150056237](C:\Users\44174\AppData\Roaming\Typora\typora-user-images\image-20220207150056237.png)

deque内部工作原理：

deque内部有个**中控器**，维护每段缓冲区中的内容，缓冲区中存放真实数据

中控器维护的是每个缓冲区的地址，使得使用deque时像一片连续的内存空间

![image-20220207150537066](C:\Users\44174\AppData\Roaming\Typora\typora-user-images\image-20220207150537066.png)

- deque容器的迭代器也是支持随机访问的

## 3.3.2 deque构造函数

**功能描述：**

- deque容器构造

**函数原型：**

- `deque<T> deqT;`//默认构造形式
- `deque(beg, end);`//构造函数将[beg, end)区间的元素拷贝给本身
- `deque(n, elem);`//构造函数将n个elem拷贝给本身
- `deque(const deque *deq);`//拷贝构造函数

**示例：**

```c++
void printDeque(const deque<int> &d) {
    for(deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
} 
void test01() {
    deque<int> d1;
    for(int i = 0; i < 10; i++) {
        d1.push_back(i);
    }
    printDeque(d1);
    
    deque<int> d2(d1.begin(), d1.end());
    printDeque(d2);
    
    deque<int>d3(10, 100);
    printDeque(d3);
    
    deque<int>d4(d3);
    printDeque(d4);
 }
```

##  3.3.2 deque赋值操作

**功能描述：**

- 给deque容器进行赋值

**函数原型：**

- `deque& operator=(const deque &deq);` //重载等号运算符
- `assign(beg, end);`//将[beg, end)区间中的数据拷贝赋值给本身
- `assign(n, elem);`//将n个elem拷贝赋值给本身

**示例：**

```c++
void printDeque(const deque<int> &d) {
    for(deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
} 
void test01() {
    deque<int> d1;
    for(int i = 0; i < 10; i++) {
        d1.push_back(i);
	}
    printDeque(d1);
    
    deque<int> d2;
    d2 = d1;
    printDeque(d2);
    
    deque<int> d3;
    d3.assign(d1.begin(), d1.end());
    printDeque(d3);
    
    deque<int> d4;
    d4.assign(10, 100);
    printDeque(d4);
}
```

## 3.3.4 deque大小操作

**功能描述：**

- 对deque容器的大小进行操作

**函数原型：**

- `deque.empty();`
- `deque.size();`
- `deque.resize(num);`
- `deque.resize(num, elem);`

## 3.3.5 deque插入和删除

**功能描述：**

- 向deque容器中插入和删除数据

**函数原型：**

两端插入操作：

- `push_back(elem);`//在容器尾部添加一个数据
- `push_front(elem);`//在容器头部插入一个数据
- `pop_back();`//删除容器最后一个数据
- `pop_front();`//删除容器第一个数据

指定位置操作：

- `insert(pos, elem);` //在pos位置插入一个elem元素的拷贝，返回新数据的位置
- `insert(pos, n, elem);`//在pos位置插入n个elem数据，无返回值
- `insert(pos, beg, end);`//在pos位置插入[beg， end）区间的数据，无返回值
- `clear();`//清空容器内所有数据
- `erase(beg, end);`//删除[beg，end）区间的数据，返回下一个数据的位置
- `erase(pos);`//删除pos位置的数据，返回下一个数据的位置

```c++
void printDeque(const deque<int> &d) {
    for(deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}
void test01() {
    deque<int> d1;
    
    d1.push_back(10);
    d1.push_back(20);
    d1.push_front(100);
    d1.push_front(200);
    printDeque(d1);
    //200 100 10 20
    
    //尾删
    d1.pop_back();
    printDeque(d1);
    //200 100 10
    
    //头删
    d1.pop_front();
    printDeque(d1);
    //100 10
}
void test02() {
    d1.push_back(10);
    d1.push_back(20);
    d1.push_front(100);
    d1.push_front(200);
    printDeque(d1);
    //200 100 10 20
    
    //insert
    d1.insert(d1.begin(), 1000);
    //1000 200 100 10 20
    d1.insert(d1.begin(), 2, 10000);
    //10000 10000 1000 200 100 10 20
    
    //按照区间插入
    deque<int> d2;
    d2.push_back(1);
    d2.push_back(2);
    d2.push_back(3);
    
    d1.insert(d1.begin(), d2.begin(), d2.end());
    //1 2 3 10000 10000 1000 200 100 10 20
    
}
void test03() {
    deque<int> d1;
    
    d1.push_back(10);
    d1.push_back(20);
    d1.push_front(100);
    d1.push_front(200);
    
    //区间方式删除
    d1.erase(d1,begin(), d1.end());//clear();
    //NULL
    
    //删除
    deque<int>::iterator it = d1.begin();
    it++;
    d1.erase(it);
    //200 10 20
    
}
```

## 3.3.6 deque 数据存取

**功能描述：**

- 对deque中的数据的存取操作

**函数原型：**

- `at(int idx);` //返回索引idx所指的数据
- `operator[];`//返回索引idx所指的数据
- `front();`//返回容器中第一个数据元素
- `back();`//返回容器中最后一个数据元素

## 3.3.7 deque 排序

**功能描述：**

- 利用算法实现对deque容器进行排序

**算法：**

- `sort(iterator beg, iterator end);`//对beg和end区间内的元素进行排序

**示例：**

```c++
void printDeque(const deque<int> &d) {
    for(deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}
void test01() {
    deque<int> d;
    d.push_back(10);
    d.push_back(20);
    d.push_back(30);
    d.push_back(100);
    d.push_back(200);
    d.push_back(300);
    //300 200 100 10 20 30
    
    //默认从小到大 升序排序
    //对于支持随机访问的迭代器的容器，都可以利用sort算法直接对其进行排序
    //vector容器也可以利用sort进行排序
    sort(d.begin(), d.end());
    cout << "排序后：" << endl;
    printDeque(d);
}
```

