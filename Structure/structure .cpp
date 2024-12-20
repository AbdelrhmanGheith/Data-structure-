#include <iostream>
#include <string> // تضمين مكتبة النصوص للتعامل مع النوع string
using namespace std;

// تعريف هيكل (struct) باسم Emp لتخزين بيانات الموظف
struct Emp {
    string name;   
    int age;       
    float salary;  
};

int main()
{
    struct Emp e; // إنشاء متغير من النوع Emp

    // طلب إدخال اسم الموظف
    cout << "Enter the name: ";
    getline(cin, e.name); // استخدام getline لقراءة النصوص التي تحتوي على مسافات

   
    cout << "Enter the age and salary: ";
    cin >> e.age >> e.salary; 

    
    cout << "\nName: " << e.name
        << "\nAge: " << e.age
        << "\nSalary: " << e.salary << endl;

    return 0; 
}
