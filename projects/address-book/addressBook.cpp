#include<iostream>
#include<string>
#define MAX 1000
using namespace std;
struct addressBook {
	string name;
	string gender;
	int age;
	string phonenumber;
	string address;
};
void showMenu() {
	cout << '\t' << "欢迎使用通讯录管理系统" << '\t' << endl;
	cout << "********" << "按‘1’以添加联系人" << '\t' << "********" << endl;
	cout << "********" << "按‘2’以显示所有联系人" << '\t' << "********" << endl;
	cout << "********" << "按‘3’以删除指定联系人" << '\t' << "********" << endl;
	cout << "********" << "按‘4’以查找指定联系人" << '\t' << "********" << endl;
	cout << "********" << "按‘5’以修改指定联系人" << '\t' << "********" << endl;
	cout << "********" << "按‘6’以清空联系人" << '\t' << "********" << endl;
	cout << "********" << "按‘0’退出本系统" << '\t' << '\t' << "********" << endl;
	cout << "****************************************" << endl;
}
int addContact(addressBook contact[],  int &countContact) {
	if (countContact >= MAX)
	{
		cout << "通讯录已满！请删除一些联系人" << endl;
		system("pause");
		system("cls");
		return 0;
	}
	cout << "请输入联系人姓名:" << endl;
	cin >> contact[countContact].name;
	cout << "请输入联系人性别:" << endl;
	cin >> contact[countContact].gender;
	cout << "请输入联系人年龄:" << endl;
	cin >> contact[countContact].age;
	cout << "请输入联系人联系电话：" << endl;
	cin >> contact[countContact].phonenumber;
	cout << "请输入联系人住址：" << endl;
	cin >> contact[countContact].address;
	cout << "添加成功！" << endl;
	countContact++;
	system("pause");
	system("cls");
}
int printAllInfo(const addressBook contact[], const int countContact) {
	if (countContact == 0)
	{
		cout << "无数据！" << endl;
		system("pause");
		system("cls");
		return 0;
	}
	cout << '\t' << "姓名" << '\t' << "性别" << '\t' << "年龄" << '\t' << "联系电话" << "              " << "住址" << endl;
	for (int i = 0; i < countContact; i++)
		cout << '\t' << contact[i].name << '\t' << contact[i].gender << '\t' << contact[i].age << '\t' << contact[i].phonenumber << "               " << contact[i].address << endl;
	system("pause");
	system("cls");
}
int contactExists(const addressBook contact[], const int countContact, string name) {
	for (int i = 0; i < countContact; i++)
		if (contact[i].name == name)
			return i;
	return -1;
}
int deleteContact(addressBook contact[], int &countContact) {
	cout << "请输入需要删除的联系人的姓名：" << endl;
	string name;
	cin >> name;
	int ret = contactExists(contact, countContact, name);
	if (ret == -1)
	{
		cout << "该联系人不存在！" << endl;
		system("pause");
		system("cls");
		return 0;
	}
	for(int i=ret;i<countContact-1;i++)
	{
		contact[i] = contact[i + 1];
	}
	cout << "删除成功！" << endl;
	countContact--;
	system("pause");
	system("cls");
}
int findContact(const addressBook contact[], const int countContact) {
	cout << "请输入要查找的联系人的姓名：" << endl;
	string name;
	cin >> name;
	int ret;
	ret=contactExists(contact, countContact, name);
	if (ret == -1)
	{
		cout << "该联系人不存在！" << endl;
		system("pause");
		system("cls");
		return 0;
	}
	cout << '\t' << "姓名" << '\t' << "性别" << '\t' << "年龄" << '\t' << "联系电话" << "              " << "住址" << endl;
	cout << '\t' << contact[ret].name << '\t' << contact[ret].gender << '\t' << contact[ret].age << '\t' << contact[ret].phonenumber << "               " << contact[ret].address << endl;
	system("pause");
	system("cls");
}
int updataContact(addressBook contact[], int countContact) {
	cout << "请输入要修改的联系人的姓名："<<endl;
	string name;
	cin >> name;
	int ret;
	ret = contactExists(contact, countContact, name);
	if (ret == -1)
	{
		cout << "该联系人不存在！" << endl;
		system("pause");
		system("cls");
		return 0;
	}
	cout << "请输入联系人姓名:" << endl;
	cin >> contact[ret].name;
	cout << "请输入联系人性别:" << endl;
	cin >> contact[ret].gender;
	cout << "请输入联系人年龄:" << endl;
	cin >> contact[ret].age;
	cout << "请输入联系人联系电话：" << endl;
	cin >> contact[ret].phonenumber;
	cout << "请输入联系人住址：" << endl;
	cin >> contact[ret].address;
	cout << "修改成功！" << endl;
	system("pause");
	system("cls");
}
int deleteAllContact(addressBook contact[], int &countContact) {
	cout << "该操作将会清空通讯录，确定要清空吗？" << endl;
	cout << "按‘y’键确认,‘n’键返回：" << endl;
	char temp;
	cin >> temp;
	if (temp == 'y')
	{
		countContact = 0;
		cout << "通讯录已被清空！"<<endl;
		system("pause");
		system("cls");
		return 0;
	}
	else if (temp == 'n')
	{
		system("pause");
		system("cls");
		return 0;
	}
}
int main()
{
	addressBook contact[MAX];
	int flag = 1;
	int countContact = 0;
	do {
		showMenu();
		cin >> flag;
		switch (flag) {
		case 1:addContact(contact, countContact);  break;
		case 2:printAllInfo(contact, countContact);  break;
		case 3:deleteContact(contact, countContact); break;
		case 4:findContact(contact, countContact); break;
		case 5:updataContact(contact, countContact); break;
		case 6:deleteAllContact(contact, countContact); break;
		case 0:flag = 0; cout << "欢迎再次使用本系统!" << endl; system("pause"); return 0; break;
		default:cout << "无此功能！" << endl; break;
		}
	} while (flag != 0);

}