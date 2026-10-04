//MULTIPLE INHERITANCE
#include<iostream>
using namespace std;
class Father
{
	public:
		string surname;
		Father(string s)
		{
			surname=s;
		}
		
};
class Mother
{
	public:
		string blood_group;
		Mother(string b)
		{
			blood_group=b;
		}
};
class Child: public Father,public Mother
{
	public:
		Child(string s,string b):Father(s),Mother(b)
		{
			
		}
	void display()
	{
		cout<<"Surname:"<<surname<<endl;
		cout<<"Blood group:"<<blood_group<<endl;
	}
};
main()
{
	Child c("SUDARSANAN","B+");
	c.display();
}
