#include<iostream>
using namespace std;
class Complex
{
	public:
		int real;
		int imag;
		
	// constructor
	Complex(int r=0, int i =0)
	{
		real =r;
		imag = i;
	}
	//operator overloading 
	Complex operator+(Complex c)
	{
		Complex temp;
		temp.real = real + c.real;
		temp.imag = imag+c.imag;
		return temp;
	}
};
int main()
{
	Complex c1(3,4);
	Complex c2(5,6);
	Complex c3;
	c3=c1+c2;
	cout<<"First Complex number="
		<< c1.real<<"+"<<c2.imag<<"i"<<endl;
	cout<<"Second Complex number="
		<<c2.real<<"+"<<c2.imag<<"i"<<endl;
}
