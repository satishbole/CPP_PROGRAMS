//NESTED CLASS
#include<iostream>
using namespace std;
class Faculty
{
	public:
		class Student
		{
			public:
				void display()
				{
					cout<<"STUDENTS ARE PRESENT";
				}
		};
};
main()
{
	Faculty::Student s;
	s.display();
}
