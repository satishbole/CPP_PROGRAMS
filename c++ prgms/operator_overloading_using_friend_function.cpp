//operator overloading using friend function
#include<iostream>
using namespace std;
class Money{
	int rupees;
	public:
		Money(int r=0):rupees(r){}
		friend Money operator+(Money a, Money b);
		
		void display()
		{
			cout<<"Rs."<<rupees;
		}	
};
//friend function defined outside the class
Money operator+(Money a, Money b)
{
	Money temp;
	temp.rupees=a.rupees+b.rupees;
	return temp;
}
main()
{
	Money m1(15),m2(25),m3;
	m3=m1+m2;
	m3.display();
}
