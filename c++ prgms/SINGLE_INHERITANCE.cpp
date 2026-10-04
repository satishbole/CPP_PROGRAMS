//SINGLE INHERITANCE
#include<iostream>
using namespace std;
class Parent
{
	public:
		void parentclass()
		{
			cout<<"Parent class";
			}	
};
class Child:public Parent
{
	public:
		void childclass()
		{
			cout<<"child class"<<endl;
		}
};
main()
{
	Child c;
	c.childclass();
	c.parentclass();
}
