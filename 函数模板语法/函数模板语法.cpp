#include <iostream>
using namespace std;

template<typename T>
void MySwap(T &a, T &b) {
	T temp = a;
	a = b;
	b = temp;
}

template<typename T>
void mySort(T arr[], int len) {
	for (int i = 0; i < len; i++) {
		int max = i;
		for (int j = i + 1; j < len; j++) {
			if (arr[j] > arr[max]) {
				max = j;
			}
		}
		if (max != i) {
			MySwap(arr[max], arr[i]);
		}
	}
}

template<typename T>
void PrintArray(T arr[], int len) {
	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}


void test01() {
	char charArr[] = "defcab";
	int len = sizeof(charArr) / sizeof(char);
	mySort(charArr, len);
	PrintArray(charArr, len);
}

void test02() {
	int intArr[] = { 7, 5, 9, 3, 2, 4, 1 };
	int intlen = sizeof(intArr) / sizeof(int);
	mySort(intArr, intlen);
	PrintArray(intArr, intlen);
}

int main() {
	test01();
	test02();
	return 0;
}