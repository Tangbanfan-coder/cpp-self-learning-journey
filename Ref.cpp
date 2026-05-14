#include<iostream>
using namespace std;
int main()
{
	int a = 10;
	int& b=a;//给a取别名
	cout << "a=" << a << endl;//看看a和b是否有区别
	cout << "b=" << b << endl;
	int c = 20;
	b = 20;//试试看更改b，b不能再成为别的变量的别名了，但是可以进行赋值操作
	cout << "a=" << a << endl;//b的值被改变了，a的值会变吗？
}