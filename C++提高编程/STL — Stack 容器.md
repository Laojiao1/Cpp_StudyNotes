# 3.5 stack容器

## 3.5.1 stack 基本概念

**概念：**stack是一种**先进后出**的数据结构，它只有一个出口

![image-20220206160027354](C:\Users\44174\AppData\Roaming\Typora\typora-user-images\image-20220206160027354.png)

栈中只有顶端的元素才可以被外界使用，因此栈不允许有遍历行为

## 3.5.2 stack常用接口

功能描述：栈容器常用的对外接口

构造函数：

- `stack<T> stk;` //stack采用模板类实现，stack对象的默认构造形式
- `stack(const stack &stk);`//拷贝构造函数

赋值操作：

- `stack& operator=(const stack &stk);` //重载等号操作符

数据存取：

- `push(elem);` //向栈顶添加元素
- `pop();`//从栈顶移除第一个元素
- `top();`//返回栈顶元素

大小操作：

- `empty();`//判断堆栈是否为空
- `size();`//返回栈的大小

**示例：**

```c++
void test01() {
    stack<int> s;
    //入栈
    s.push(10);
    s.push(20);
    s.push(30);
    //只要栈不为空，查看栈顶，并且执行出栈操作
    while(!s.empty()) {
        //查看栈顶元素
        cout << "栈顶元素为：" << s.top() << endl;
        //出栈
        s.pop();
    }
    cout << "栈的大小：" << s.size() << endl;
}
```

