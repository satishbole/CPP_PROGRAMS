//ARRAY OF OBJECT
#include<iostream>
using namespace std;
class Student
{
	int Rno;
	public:
		void Getdata()
		{
			cin>>Rno;
		}
		void display()
		{
			cout<<"Roll No:"<<Rno<<endl;
			
		}
};
int main()
{
	cout<<"Enter the value of n: ";
	int n;
	cin>>n;
	Student s[n];
	cout<<"enter the rollno of students:";
	for(int i=0;i<n;i++)
	{
		s[i].Getdata();
	}
	
	for(int i=0;i<n;i++)
	{
		s[i].display();
	}
	
}
