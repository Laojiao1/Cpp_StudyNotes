//评委打分
//有5名选手：A, B, C, D, E, 10个评委分别对每一名选手打分
//去除最高分，去除评委中最低分，取平均分

#include <bits/stdc++.h>
#include <ctime>
using namespace std;

class Person {
	public:
		Person(string name, int score) {
			this->m_name = name;
			this->m_score = score;
		}
	string m_name;
	int m_score;
};

void createPerson(vector<Person> &v) {
	string nameSeed = "ABCDE";
	for(int i = 0; i < 5; i++) {
		string name = "选手";
		name += nameSeed[i];
		
		int score = 0;
		Person p(name, score);
		
		v.push_back(p);
	}
}

void setScore(vector<Person> &v) {
	for(vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
		 deque<int> d;
		for(int i = 0; i < 10; i++) {
		 	int score = rand()%41 + 60; //60~100
		 	d.push_back(score);
		}
		
//		cout << it->m_name << " 打分：" << endl;
//		for(deque<int>::iterator dit = d.begin(); dit != d.end(); dit++) {
//			cout << *dit << " ";
//		}
//		cout << endl;
		
		sort(d.begin(), d.end());
		//去除最高分最低分 
		d.pop_back();
		d.pop_front();
		
		int sum = 0;
		for(deque<int>::iterator dit = d.begin(); dit != d.end(); dit++) {
			sum += *dit;
		}
		int avg = sum / d.size();
		
		//将平均分赋值给选手
		it->m_score = avg; 
	}
}

void showScore(vector<Person> &v) {
	for(vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
		cout << "姓名：" << it->m_name << " 平均分：" << it->m_score << endl; 
	}
}

int main() {
	//随机种子
	srand( (unsigned int)time(NULL) );
	 
	vector<Person> v;
	createPerson(v);
	
//	for(vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
//		cout << "姓名：" << (*it).m_name << " 分数: " << (*it).m_score << endl; 
//	}
	
	setScore(v);
	
	showScore(v);
	
	system("pause");
	return 0;
}
