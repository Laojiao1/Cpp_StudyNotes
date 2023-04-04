# STL — vector

## 2.5 容器算法迭代器初识

STL中最常用的容器为vertor，可以理解为数组。

### 2.5.1 vector存放内置数据类型

容器：vector

算法：for_each

迭代器：vector<int> :: iterator

```c++
void MyPrint(int val) {
    cout << val << endl;
}
void test01 {
    //创建一个vector容器
    vector<int> v;
    //插入数据
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    //v.begin()返回迭代器，这个迭代器指向容器中第一个数据
    //v.end()返回迭代器，这个迭代器指向容器元素的最后一个元素的下一个位置
    //vector<int>::iterator 拿到vector<int>这种容器的迭代器类型
    
    vector<int>::iterator pBegin = v.begin();
    vector<int>::iterator pEnd = v.end();
    
    //第一种遍历方式
    while(pBegin != pEnd) {
        cout << *pBegin << endl;
        pBegin++;
    }
    //第二种遍历方式
    for(vector<int>::iterator p = v.begin(); p != v.end(); p++) {
        cout << *p << endl;
    }
    //第三种遍历方式
    for_each(v.begin(), v.end(), MyPrint);
    
}
```

### 2.5.2 vector存放自定义数据类型

```c++
class Person {
    public:
    Person(string name, int age) {
        m_name = name;
        m_age = age;
        
	}
    private:
    int m_age;
   	string m_name;
}
void test01() {
    vector<Person> v;
    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc", 30);
    
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    
    for(vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
        cout << "name = " << (*it).m_name << "age = " <<
             (*it).m_age << endl;
    }
}

void test02() {
    vector<Person*> v;
    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc", 30);
    
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    
    for(vector<Person*>::iterator it = v.begin(); it != v.end(); it++) {
        Person* p = (*it);
        cout << "name = " << p->m_name << "age = " <<
             p->m_age << endl;
    }
}
```

### 2.5.3 vector容器嵌套

```c++
{
    vector< vector<int> > v;
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    
    for(int i = 0; i < 3; i++) {
        v1.push_back(i+1);
        v2.push_back(i+1);
        v2.push_back(i+1);
    }
    
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    
    for(vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++) {
        for(vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++) {
            cout << *vit << " ";
        }
        cout << endl;
    }
}
```

