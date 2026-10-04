//object as a parameter
#include<iostream>
using namespace std;
class Student
{
	int id;
	public:
	void getdata()
	{
		cin>>id;
	}
	void display(Student stu)
	{
		cout<<"Ids are:"<<stu.id;
	}
};
main()
{
	Student s;
	s.getdata();
	s.display(s);
}
