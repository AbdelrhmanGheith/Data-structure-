#include <iostream>
using namespace std;

int main()
{
    const int MAXSIZE = 100; // الحد الأقصى لعدد العناصر في المصفوفة
    int array[MAXSIZE]; // تعريف المصفوفة
    int i, j, num, temp; // تعريف المتغيرات

    // طلب عدد العناصر في المصفوفة من المستخدم
    cout << "Enter the value of num (number of elements): \n";
    cin >> num;

    // إدخال عناصر المصفوفة
    cout << "Enter the elements one by one:\n";
    for (i = 0; i < num; i++) {
        cin >> array[i];
    }

    // تنفيذ خوارزمية الفرز الفقاعي
    for (i = 0; i < num - 1; i++) {         // الحلقة الخارجية لتكرار العملية
        for (j = 0; j < (num - i - 1); j++) { // الحلقة الداخلية لمقارنة العناصر
            if (array[j] > array[j + 1])
            {   // إذا كانت العناصر غير مرتبة
                // تبديل القيم بين العنصرين
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    // عرض المصفوفة بعد الفرز
    cout << "Sorted array is:\n";
    for (i = 0; i < num; i++) {
        cout << array[i] << "\n";
    }

    return 0; 
}
