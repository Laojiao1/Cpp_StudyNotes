#include "circle.h"

void Circle::setCenter(Point center) {
	m_Center = center;
}
Point Circle::getCenter() {
	return m_Center;
}

void Circle::setR(int r) {
	m_R = r;
}
int Circle::getR() {
	return m_R;
}