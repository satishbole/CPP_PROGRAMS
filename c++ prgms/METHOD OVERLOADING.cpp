//method overloading
#include<iostream>
using namespace std;
class Demo
{
	public:
		void show()
		{
			cout<<"No arguments";
		}
		void show(int a)
		{
			cout<<"One argument"<<a;
		}
		void show(int x,int y)
		{
			cout<<"Two arguments"<<x<<y;
		}
};
int main()
{
	Demo d;
	d.show();
	d.show(20);
	d.show(10,20);
	
}
