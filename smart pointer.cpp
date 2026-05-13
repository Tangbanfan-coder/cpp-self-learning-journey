#include<iostream>
using namespace std;
int main()
{//尝试使用unqiue_ptr
	unique_ptr<int> a(new int(10));//通过裸指针构造
	cout << *a << endl;
	unique_ptr<int[]> p(new int[10]);//通过裸指针构造数组
	for (int i = 0; i < 10; i++)
		p[i] = i + 100;//赋值
	for (int i = 0; i < 10; i++)
		cout << p[i] << endl;//输出看看结果
	unique_ptr<int> b = move(a);//体验一下智能指针的独占性，和可以移动的特点
	cout << *b << endl;//输出一下看看是否真的可以移动
	auto c = make_unique<int[]>(10);//使用make_unique创建一个智能指针
	for (int i = 0; i < 10; i++)//赋值
		c[i] = 200 + i;
	for (int i = 0; i < 10; i++)
		cout << c[i] << endl;//输出看看
	//尝试使用shared_ptr
	auto p1 = make_shared<int>(666);//直接用make_shared创造指针
	cout << *p1 << endl;//尝试解引用共享指针
	cout << p1.use_count() << endl;//查看共享特性
	{
		auto p2 = p1;//把p1拷贝给p2
		cout << *p2 << endl;//拷贝成功了吗？
		cout << p2.use_count() << endl;//计数变化
		cout << p1.use_count() << endl;//计数都是一样的吗？
	}
	cout << p1.use_count() << endl;//p2脱离了作用范围，计数是否真的会变化？
	weak_ptr<int> p3 = p1;//尝试使用weak_ptr
	cout << p1.use_count() << endl;//拷贝给weak_ptr创建的指针不会增加计数
}
