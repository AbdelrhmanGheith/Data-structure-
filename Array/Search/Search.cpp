#include <iostream>
using namespace std;

int main()
{
    // تعريف المصفوفة والعناصر
    int LA[] = { 1, 3, 5, 7, 8 }; // المصفوفة الأصلية
    int item = 5;               // العنصر المطلوب البحث عنه
    int n = 5;                  // عدد العناصر في المصفوفة
    int i = 0, j = 0;           // i و j هما مؤشرات

    // عرض العناصر الأصلية
    cout << "The original array elements are:\n";
    for (i = 0; i < n; i++) {
        cout << "LA[" << i << "] = " << LA[i] << "\n";
    }

    // البحث عن العنصر في المصفوفة
    while (j < n) {
        if (LA[j] == item) { // إذا تم العثور على العنصر
            cout << "\nFound element " << item << " at position " << j + 1 << "\n";
            break; // خروج من الحلقة
        }
        j = j + 1; // الانتقال إلى العنصر التالي
    }

    // إذا لم يتم العثور على العنصر
    if (j == n) {
        cout << "\nElement " << item << " not found in the array.\n";
    }

    return 0;
}
