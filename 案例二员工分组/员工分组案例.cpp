//公司招聘了10个员工，员工进入公司后，需要指派员工在
//哪个部门工作
//员工信息：姓名，工资组成；部门分为：策划、美术、研发
//随机给10名员工分配部门和工资
//通过multimap进行信息插入 key(部门编号) value(员工)
//分部门显示员工信息 

#include <bits/stdc++.h>
using namespace std;
#define CEHUA 0
#define MEISHU 1
#define YANFA 2

class Worker{
	
	public:
		string m_name;
		int m_salary;
};

void CreateWorker(vector<Worker>&v) {
	string nameSeed = "ABCDEFGHIJ";
	for(int i = 0; i < 10; i++) {
		Worker worker;
		worker.m_name = "员工";
		worker.m_name += nameSeed[i];
		
		worker.m_salary = rand()%10000 + 10000;
		v.push_back(worker);
	}
}

void setGroup(vector<Worker>&v, multimap<int, Worker>&m) {
	for(vector<Worker>::iterator it = v.begin(); it != v.end(); it++) {
		int deptID = rand() % 3;
		//将员工插入到分组中
		m.insert(make_pair(deptID, *it)); 
		//key代表部门编号，value代表员工 
	}
}

void showWorkerByGroup(multimap<int, Worker>&m) {
	cout << "策划部门：" << endl;
	multimap<int, Worker>::iterator pos = m.find(CEHUA);
	int index = 0;
	int cnt = m.count(CEHUA);
	for( ; pos != m.end() && index < cnt; index++, pos++) {
		cout << "姓名：" << pos->second.m_name 
			 << "  工资：" << pos->second.m_salary << endl;
	}
	cout << "-----------------------------" << endl;
	cout << "美术部门：" << endl;
	pos = m.find(MEISHU);
	index = 0;
	cnt = m.count(MEISHU);
	for( ; pos != m.end() && index < cnt; index++, pos++) {
		cout << "姓名：" << pos->second.m_name 
			 << "  工资：" << pos->second.m_salary << endl;
	}
	cout << "-----------------------------" << endl;
	cout << "研发部门：" << endl;
	pos = m.find(YANFA);
	index = 0;
	cnt = m.count(YANFA);
	for( ; pos != m.end() && index < cnt; index++, pos++) {
		cout << "姓名：" << pos->second.m_name 
			 << "  工资：" << pos->second.m_salary << endl;
	}
}

int main() {
	srand((unsigned int) time(NULL));
	//创建员工
	vector<Worker> vWorker;
	CreateWorker(vWorker);
	//测试
//	for(vector<Worker>::iterator it = vWorker.begin(); it != vWorker.end(); it++) {
//		cout << "姓名：" << it->m_name << 
//				"  工资：" << it->m_salary << endl; 
//	} 

	//员工分组
	multimap<int, Worker> mWorker; 
	setGroup(vWorker, mWorker);
	 
	//分组显示员工
	showWorkerByGroup(mWorker); 
	 
	system("pause");
	return 0;
}
