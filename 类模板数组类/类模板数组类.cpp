#include <iostream>
#include <string>
#include "MyArray.hpp"
using namespace std;

void PrintIntArray(MyArray<int> &arr) {
	for (int i = 0; i < arr.GetSize(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void test01() {
	MyArray<int> arr1(5);
	for (int i = 0; i < 5; i++) {
		arr1.Push_Back(i);
	}
	cout << "arr1的打印输出为: " << endl;
	PrintIntArray(arr1);
	cout << "arr1的大小为：" << arr1.GetSize() << endl;
	cout << "arr1的容量为：" << arr1.GetCapacity() << endl;
	cout << "----------------------------------------" << endl;

	MyArray<int> arr2(arr1);
	cout << "arr2的打印输出为：" << endl;
	PrintIntArray(arr2);
	//尾删
	arr2.Pop_Back();
	cout << "arr2尾删后的打印输出" << endl;
	cout << "arr2的大小为：" << arr2.GetSize() << endl;
	cout << "arr2的容量为：" << arr2.GetCapacity() << endl;
	cout << "----------------------------------------" << endl;

}

//测试自定义数据类型
class Person {
public:
	Person() {

	};
	Person(string name, int age) {
		this->m_name = name;
		this->m_age = age;
	}

	string m_name;
	int m_age;

};

void PrintPersonArray(MyArray<Person>& arr) {
	for (int i = 0; i < arr.GetSize(); i++) {
		cout << "姓名：" << arr[i].m_age << " " 
			 << "年龄：" << arr[i].m_name << endl;
	}
}

void test02() {
	MyArray<Person> arr(10);
	Person P1("孙悟空", 999);
	Person P2("猪八戒", 99);
	Person P3("沙僧", 99);

	//将数据插入到数组中国
	arr.Push_Back(P1);
	arr.Push_Back(P2);
	arr.Push_Back(P3);

	//打印数组
	PrintPersonArray(arr);

	//输出容量和大小
	cout << "arr的大小为：" << arr.GetSize() << endl;
	cout << "arr的容量为：" << arr.GetCapacity() << endl;
}

int main() {
	test01();
	test02();
	return 0;
}