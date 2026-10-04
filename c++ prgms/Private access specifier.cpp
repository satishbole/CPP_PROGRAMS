#include <iostream>
using namespace std;

class Student
{
private:
    int marks;

public:
    void setMarks(int m)
    {
        marks = m;
    }

    void getMarks()
    {
        cout << marks;
    }
};

int main()
{
    Student s;

    s.setMarks(95);
    s.getMarks();

    return 0;
}
