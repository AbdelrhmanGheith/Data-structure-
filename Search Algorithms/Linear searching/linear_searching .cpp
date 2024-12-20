#include <iostream>
using namespace std;

int main()
{
    // تعريف المصفوفة مسبقًا مع القيم المطلوبة
    int array[] = { 100,80,50,60,10,20,30,40,90,70 };
    int n = 10; // عدد العناصر في المصفوفة
    int search, c;

    // طلب الرقم المراد البحث عنه
    cout << "Enter a number to search: ";
    cin >> search;

    // البحث في المصفوفة
    for (c = 0; c < n; c++) {
        if (array[c] == search) {
            // طباعة النتيجة عند العثور على العنصر
            cout << search << " is present at location " << c + 1 << ".\n";
            break; // الخروج من الحلقة عند العثور على العنصر
        }
    }

    // إذا لم يتم العثور على العنصر
    if (c == n) {
        cout << search << " isn't present in the array.\n";
    }

    return 0; 
}
