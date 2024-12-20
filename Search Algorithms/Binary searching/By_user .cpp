#include <iostream>
using namespace std;

int main()
{
    int c, first, last, middle, n, search, array[100];

    // طلب إدخال عدد العناصر
    cout << "Enter number of elements: ";
    cin >> n;

    // إدخال عناصر المصفوفة
    cout << "Enter " << n << " numbers:\n";
    for (c = 0; c < n; c++)
        cin >> array[c];

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
