#include <iostream>
#include <string>
using namespace std;
#define MAX 1000 // 最大人数

//设计联系人结构体
struct Person {
	//姓名
	string m_name;
	//性别 1.男 2.女
	int m_Sex;
	//年龄
	int m_age;
	//电话
	string m_Phone;
	//住址
	string m_Addr;
};

//设置通讯录结构体
struct Addressbooks {
	//通讯录中保存的联系人数组
	struct Person personArray[MAX];

	//通讯录中当前记录的总联系人个数
	int m_Size;
	
};

//菜单界面
void shouMeau() {
	for (int i = 0; i < 4; i++) {
		cout << endl;
	}
	cout << "\t\t\t\t\t  *****************************" << endl;
	cout << "\t\t\t\t\t  *****   1. 添加联系人   *****" << endl;
	cout << "\t\t\t\t\t  *****   2. 显示联系人   *****" << endl;
	cout << "\t\t\t\t\t  *****   3. 删除联系人   *****" << endl;
	cout << "\t\t\t\t\t  *****   4. 查找联系人   *****" << endl;
	cout << "\t\t\t\t\t  *****   5. 修改联系人   *****" << endl;
	cout << "\t\t\t\t\t  *****   6. 清空联系人   *****" << endl;
	cout << "\t\t\t\t\t  *****   0. 退出通讯录   *****" << endl;
	cout << "\t\t\t\t\t  *****************************" << endl;
}

//添加联系人
void addPerson(Addressbooks* abs) {
	if (abs->m_Size == MAX) {
		cout << "添加人数已达上限，无法继续添加" << endl;
		return;
	}
	else {
		//添加成员信息
		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_name = name;
		//性别
		cout << "请输入性别(1->男，2->女)：" << endl;
		int sex = 0;
		while (true) {
			cin >> sex; // 1——男， 2——女
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			else {
				cout << "输入有错误，请重新输入" << endl;
			}
		}
		//年龄
		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_age = age;
		//联系电话
		cout << "请输入联系电话" << endl;
		string phone = "";
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;
		//家庭住址
		cout << "请输入家庭住址：" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		abs->m_Size++;
		cout << "添加成功" << endl;
		system("pause");
		system("cls");
	}
}

//显示联系人
void ShowPerson(Addressbooks* abs) {
	if (abs->m_Size == 0) {
		cout << "当前记录为空" << endl;
	}
	else {
		for (int i = 0; i < abs->m_Size; i++) {
			cout << "姓名：" << abs->personArray[i].m_name << "\t";
			cout << "性别：" << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << "\t";
			cout << "年龄：" << abs->personArray[i].m_age << "\t";
			cout << "住址：" << abs->personArray[i].m_Addr << "\t";
			cout << "电话：" << abs->personArray[i].m_Phone << endl;
		}
	}
	system("pause");
	system("cls");
}

//寻找联系人
int IsExit(Addressbooks* abs, string name) {
	for (int i = 0; i < abs->m_Size; i++) {
		if (abs->personArray[i].m_name == name) {
			return i;
		}
	}
	return -1;
}

//删除联系人
void DelectPerson(Addressbooks* abs) {
	cout << "请输入要删除的联系人姓名：" << endl;
	string name;
	cin >> name;
	int ret = IsExit(abs, name);
	if (ret != -1) {
		for (int i = ret; i < abs->m_Size; i++) {
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		cout << "删除成功" << endl;
	}
	else {
		cout << "暂无此人" << endl;
	}
	system("pause");
	system("cls");
}

//查找联系人
void SearchPerson(Addressbooks* abs) {
	string name;
	cout << "请输入您要查找的联系人姓名：" << endl;
	cin >> name;
	int ret = IsExit(abs, name);
	cout << "姓名：" << abs->personArray[ret].m_name << "\t";
	cout << "性别：" << (abs->personArray[ret].m_Sex == 1 ? "男" : "女") << "\t";
	cout << "年龄：" << abs->personArray[ret].m_age << "\t";
	cout << "住址：" << abs->personArray[ret].m_Addr << "\t";
	cout << "电话：" << abs->personArray[ret].m_Phone << endl;

	system("pause");
	system("cls");
}

//修改联系人
void FixPerson(Addressbooks* abs) {
	string name;
	cout << "请输入您要修改的联系人姓名：" << endl;
	cin >> name;
	int ret = IsExit(abs, name);
	This:
	cout << "请输入您要修改的信息：" << endl;
	cout << "1->姓名" << endl << "2->性别" << endl << "3->年龄" << endl << "4->电话" << endl << "5->住址" << endl;
	int flag;
	cin >> flag;
	switch (flag) {	
	case 1:
	{
		cout << "请输入新的姓名：" << endl;
		string newsname;
		cin >> newsname;
		abs->personArray[ret].m_name = newsname;
	}
		break;
	case 2:
	{
		cout << "请输入新的性别(1->男，2->女)：" << endl;
		int newsex = 0;
		while (true) {
			cin >> newsex; // 1——男， 2——女
			if (newsex == 1 || newsex == 2) {
				abs->personArray[ret].m_Sex = newsex;
				break;
			}
			else {
				cout << "输入有错误，请重新输入" << endl;
			}
		}
	}
		break;
	case 3:
	{
		cout << "请输入新的年龄：" << endl;
		int newage;
		cin >> newage;
		abs->personArray[ret].m_age = newage;
	}
		break;
	case 4:
	{
		cout << "请输入新的电话：" << endl;
		string newphone = "";
		cin >> newphone;
		abs->personArray[ret].m_Phone = newphone;
	}
		break;
	case 5:
	{
		cout << "请输入新的地址：" << endl;
		string newadder;
		cin >> newadder;
		abs->personArray[ret].m_Addr = newadder;
	}
		break;
	default:
		break;
	}

	cout << "修改成功" << endl;
	cout << "请问您还需要修改其他信息吗？(Y/N)" << endl;
	string Tag;
	cin >> Tag;
	if (Tag == "Y") {
		goto This;
	}
	else {
		cout << "已保存" << endl;
		system("pause");
		system("cls");
	}
}

//清空联系人
void CleanPerson(Addressbooks* abs) {
	abs->m_Size = 0;
	cout << "清空成功" << endl;
	system("pause");
	system("cls");
}


int main() {

	//创建通讯录结构体变量
	Addressbooks abs;
	//初始化通讯录中当前人员个数
	abs.m_Size = 0;

	int select = 0; //创建用户选择输入变量

	while (true) {
		//菜单调用
		shouMeau();
		cin >> select;
		switch (select) {
		case 1: //1. 添加联系人
			addPerson(&abs); //利用地址传递可以修饰实参
			break;
		case 2: //2. 显示联系人
			ShowPerson(&abs);
			break;
		case 3: //3. 删除联系人
			DelectPerson(&abs);
			break;
		case 4: //4. 查找联系人
			SearchPerson(&abs);
			break;
		case 5: //5. 修改联系人
			FixPerson(&abs);
			break;
		case 6: //6. 清空联系人
			CleanPerson(&abs);
			break;
		case 0: //0. 退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
		default:
			break;
		}

	}

	return 0;
}