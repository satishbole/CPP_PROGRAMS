//static member function
#include<iostream>
using namespace std;
class student
{
	public:
		static int count;
		static void showcount(){
			cout<<"count="<<count;
		}
};
int student::count=10;
int main(){
	student::showcount();
	return 0;
	}

