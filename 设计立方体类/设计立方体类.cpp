#include <iostream>
using namespace std;

class Cube {
public:
	void setL(int l) {
		m_L = l;
	}
	int getL() {
		return m_L;
	}

	void setW(int w) {
		m_W= w;
	}
	int getW() {
		return m_W;
	}

	void setH(int h) {
		m_H = h;
	}
	int getH() {
		return m_H;
	}
	int calculateS() {
		return 2 * m_H * m_W + 2 * m_L * m_H + 2 * m_W * m_L;
	}
	int calculateV() {
		return m_L* m_H * m_W;
	}
	bool compareByCube(Cube& p) {
		if (m_H == p.getH() && m_W == p.getW() && m_H == p.getH()) {
			return true;
		}
		else {
			return false;
		}
	}

private:
	int m_L;
	int m_W;
	int m_H;
};

bool compareCube(Cube& p1, Cube& p2) {
	if (p1.getH() == p2.getH() && p1.getW() == p2.getW() && p1.getL() == p2.getL()) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	Cube p1;
	p1.setL(10);
	p1.setH(10);
	p1.setW(10);
	cout << "p1的面积为：" << p1.calculateS() << endl;
	cout << "p1的体积为：" << p1.calculateV() << endl;
	Cube p2;
	p2.setL(10);
	p2.setH(10);
	p2.setW(10);
	cout << "p2的面积为：" << p2.calculateS() << endl;
	cout << "p2的体积为：" << p2.calculateV() << endl;

	bool ret = compareCube(p1, p2);
	if (ret) {
		cout << "全局函数：两个立方体相等" << endl;
	}
	else {
		cout << "全局函数：两个立方体不相等" << endl;
	}

	ret = p1.compareByCube(p2);
	if (ret) {
		cout << "局部函数：两个立方体相等" << endl;
	}
	else {
		cout << "局部函数：两个立方体不相等" << endl;
	}

	system("pause");
	return 0;
}