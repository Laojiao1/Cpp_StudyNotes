//自己通用的数组类
#pragma once
#include <iostream>
using namespace std;

template<class T>
class MyArray {
public:
	MyArray(int Capacity) {
		this->m_Capacity = Capacity;
		this->m_Size = 0;
		pAddress = new T[this->m_Capacity];
	}

	//拷贝构造,解决浅拷贝带来的问题
	MyArray(const MyArray& arr) {
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[arr.m_Capacity];

		for (int i = 0; i < this->m_Size; i++) {
			this->pAddress[i] = arr.pAddress[i];
		}
	}

	//operator= 防止浅拷贝的问题
	MyArray& operator=(const MyArray& arr) {
		if (this->pAddress != NULL) {
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Size = 0;
			this->m_Capacity = 0;
		}

		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[arr.m_Capacity];

		for (int i = 0; i < this->m_Size; i++) {
			this->pAddress[i] = arr.pAddress[i];
		}

		return *this;
	}

	//通过下标的方式访问数组元素
	T& operator[](int index) {

		return this->pAddress[index];

	}

	//尾插法
	void Push_Back(const T & val) {
		if (this->m_Capacity == this->m_Size) {
			cout << "数组容量已满！无法插入！" << endl;
			return;
		}
		this->pAddress[this->m_Size] = val;
		this->m_Size++;
	}

	//尾删法
	void Pop_Back() {
		if (this->m_Size == 0) {
			cout << "删除失败！数组元素已为零！" << endl;
			return;
		}
		this->m_Size--;
	}

	//返回数组容量
	int GetCapacity() {
		return this->m_Capacity;
	}

	//返回数组大小
	int GetSize() {
		return this->m_Size;
	}

	~MyArray() {
		if (this->pAddress != NULL) {
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
	}


private:
	T* pAddress;//指针指向堆区真实开辟的数组

	int m_Capacity;//容量

	int m_Size;//大小

};