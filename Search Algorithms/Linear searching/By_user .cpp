#include <iostream>
using namespace std;

int main()
{
    int array[100], search, c, n;

    // طلب إدخال عدد العناصر
    cout << "Enter the number of elements: ";
    cin >> n; // كان يجب طلب إدخال n قبل استخدامه

    // إدخال عناصر المصفوفة
    cout << "Enter integer(s):\n";
    for (c = 0; c < n; c++) {
        cin >> array[c];
    }

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
