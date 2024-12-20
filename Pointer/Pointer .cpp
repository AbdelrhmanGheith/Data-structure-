#include <iostream> 
using namespace std; 

int main()
{
    int* p, x; // تعريف متغير x و مؤشر p
    p = &x;    // إسناد عنوان المتغير x إلى المؤشر p

    // طلب إدخال قيمة من المستخدم
    cout << "\n Enter a number ";
    cin >> x;  // قراءة القيمة وتخزينها في المتغير x

    // طباعة القيمة المخزنة في x باستخدام المؤشر p
    cout << "\n the value of X (THROUGH POINTER) IS " << *p;

    // طباعة القيمة المخزنة في x مباشرة
    cout << "\n the value of x is " << x;

    // طباعة عنوان الذاكرة الذي يشير إليه المؤشر p
    cout << "\n the value of p " << p;

    // تعديل القيمة المخزنة في x باستخدام المؤشر p
    *p = 101;

    // طباعة القيمة الجديدة لـ x باستخدام المؤشر
    cout << "\n the value of X (THROUGH POINTER) IS " << *p;

    // طباعة القيمة الجديدة لـ x مباشرة
    cout << "\n the value of x is " << x;

    // طباعة عنوان الذاكرة الذي يشير إليه المؤشر p (لم يتغير)
    cout << "\n the value of p " << p;

    return 0; 
}
