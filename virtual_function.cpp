#ifdef A
#include<iostream>
using namespace std;

class A
{
public :
	virtual void print1()
	{
		cout << "print1" << endl;
	}
	virtual void print2()
	{
		cout << "print2" << endl;
	}
	virtual void print3()
	{
		cout << "print3" << endl;
	}
};
typedef void(*func)();
int main()
{
	A a;
	func print1 = (func)*((int*)*(int*)&a);
	print1();
	cin.get();
}
#endif