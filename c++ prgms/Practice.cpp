#include<iostream>
using namespace std;
class Student{
	public:
		void display();
		
};
void Student::display()
{
	cout<<"Hello";
}
int main()
{
	Student s;
	s.display();
}
