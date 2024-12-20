#include <iostream>
using namespace std;

int main()
{
    int LA[] = { 1, 3, 5, 7, 8 };
    int k = 3; // الموقع المراد حذفه (تبدأ العد من 1)
    int n = 5; // عدد العناصر الحالية في المصفوفة
    int i, j = k;

    // عرض العناصر الأصلية
    cout << "The original array elements are:\n";
    for (i = 0; i < n; i++) {
        cout << "LA[" << i << "]=" << LA[i] << "\n";
    }

    // حذف العنصر
    while (j < n) {
        LA[j - 1] = LA[j]; // نقل العنصر التالي إلى الموقع الحالي
        j = j + 1;
    }
    n = n - 1; // تقليل حجم المصفوفة

    // عرض العناصر بعد الحذف
    cout << "\nThe array elements after deletion:\n";
    for (i = 0; i < n; i++) {
        cout << "LA[" << i << "]=" << LA[i] << "\n";
    }

    return 0;
}
