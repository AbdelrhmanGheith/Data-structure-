#include <iostream>
using namespace std;

int main()
{
    // تعريف المصفوفة والعناصر
    int LA[] = { 1, 3, 5, 7, 8 }; // المصفوفة الأصلية
    int k = 3;                  // الموقع (يبدأ العد من 1) للعنصر الذي سيتم تحديثه
    int n = 5;                  // عدد العناصر في المصفوفة
    int item = 10;              // العنصر الجديد الذي سيتم إدخاله
    int i;                      // مؤشر الحلقة

    // عرض العناصر الأصلية
    cout << "The original array elements are:\n";
    for (i = 0; i < n; i++) {
        cout << "LA[" << i << "] = " << LA[i] << "\n";
    }

    // تحديث العنصر في الموقع k-1
    LA[k - 1] = item;

    // عرض العناصر بعد التحديث
    cout << "\nThe array elements after update:\n";
    for (i = 0; i < n; i++) {
        cout << "LA[" << i << "] = " << LA[i] << "\n";
    }

    return 0;
}
