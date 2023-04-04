# 3.6 queue容器

## 3.6.1 queue 基本概念

**概念：**Queue是一种**先进先出**的数据结构，它有两个出口

![image-20220206161446549](C:\Users\44174\AppData\Roaming\Typora\typora-user-images\image-20220206161446549.png)

只有队头和队尾能被外界访问，因此不允许有遍历行为

队列容器允许从一端新增元素，从另一端移除元素

## 3.6.2 queue 常用接口

功能描述：栈容器常用的对外接口

构造函数：

- `queue<T> que;` //queue采用模板类实现，queue对象的默认构造形式
- `queue(const queue &que);`//拷贝构造函数

赋值操作：

- `queue& operator=(const queue &que);`//重载等号操作符

数据存取：

- `push(elem);` //往队尾添加元素
- `pop();`//从队列头移除第一个元素
- `back();`//返回最后一个元素
- `front();`//返回第一个元素

大小操作：

- `empty();`//判断堆栈是否为空
- `size();`//返回栈的大小

**示例：**

```c++
class Person {
    public:
    Person(string name, int age) {
        this->m_name = name;
        this->m_age = age;
    }
    string m_name;
    int m_age;
}

void test01() {
    queue<Person> Q;
    //准备数据
    Person p1("Tom", 10);
    Person p2("Jack", 20);
    Person p3("Bob", 30);
    //入队
    q.push(p1);
    q.push(p2);
    q.push(p3);
    //判断只要队列不为空，查看队头，查看队尾，出队
    while(!q.empty()) {
        //查看对头
        cout << "队头元素 --- 姓名：" << q.front().m_name
             << "年龄：" << q.front().m_age << endl;
        //查看队尾
        cout << "队头元素 --- 姓名：" << q.back().m_name
             << "年龄：" << q.back().m_age << endl;
        //出队
        q.pop();
    }
    cout << "队列的大小：" << q.size() << endl;
}
```

