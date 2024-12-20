#include <iostream>
using namespace std;

int main()
{
    int c, first, last, middle, search;

    // تحديد عدد العناصر والمصفوفة
    const int n = 10; // عدد العناصر
    int array[n] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 }; // المصفوفة المحددة مسبقًا

    // طلب إدخال القيمة المراد البحث عنها
    cout << "Enter value to find: ";
    cin >> search;

    // إعداد المتغيرات اللازمة للبحث الثنائي
    first = 0;
    last = n - 1;
    middle = (first + last) / 2;

    // تنفيذ البحث الثنائي
    while (first <= last) {
        if (array[middle] < search) {
            // إذا كانت القيمة في المنتصف أصغر من القيمة المطلوبة
            first = middle + 1;
        }
        else if (array[middle] == search) {
            // إذا تم العثور على القيمة
            cout << search << " found at location " << middle + 1 << ".\n";
            break; // الخروج من الحلقة
        }
        else {
            // إذا كانت القيمة في المنتصف أكبر من القيمة المطلوبة
            last = middle - 1;
        }
        middle = (first + last) / 2; // تحديث قيمة المنتصف
    }

    // إذا لم يتم العثور على القيمة
    if (first > last)
        cout << "Not found! " << search << " isn't present in the list.\n";

    return 0;
}
