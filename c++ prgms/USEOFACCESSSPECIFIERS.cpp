//Illustrate the use of access specifiers.
#include<bits/stdc++.h>
using namespace std;
class Student
{
	private:
		int age=19;
	protected:
		int marks = 90;
	public:
		string name = "sajil";
		void display()
		{
			cout<<"Age:"<<age<<endl;
			cout<<"Marks:"<<marks<<endl;
			cout<<"Name:"<<name<<endl;
		}
};
int main()
{
	Student s;
	cout<<"Name:"<<s.name<<endl;
	s.display();
}
