#pragma once
#include <iostream>
#include "point.h"
using namespace std;

class Circle{
public:
	void setCenter(Point center);
	Point getCenter();
	void setR(int r);
	int getR();

private:
	int m_R;
	Point m_Center;
};
