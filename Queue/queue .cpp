#include <iostream> // استدعاء مكتبة الإدخال والإخراج
using namespace std;

// تعريف متغيرات الصف (Queue)
int queue[100], n = 100, front = -1, rear = -1;

// دالة لإضافة عنصر إلى الصف
void Insert() {
    int val;
    if (rear == n - 1) // التحقق إذا كانت الصف ممتلئة
        cout << "Queue Overflow "; // طباعة رسالة تفيد بأن الصف ممتلئ
    else {
        if (front == -1) // إذا كان الصف فارغًا، يتم تعيين المؤشر الأمامي إلى أول موقع
            front = 0;
        cout << "Insert the element in queue: "; 
        cin >> val; // إدخال العنصر الجديد
        rear++; // زيادة المؤشر الخلفي
        queue[rear] = val; // تخزين العنصر في موقع المؤشر الخلفي
    }
}

// دالة لحذف عنصر من الصف
void Delete() {
    if (front == -1 || front > rear) { // التحقق إذا كان الصف فارغًا
        cout << "Queue Underflow "; // طباعة رسالة تفيد بأن الصف فارغ
        return; // الخروج من الدالة
    } else {
        cout << "Element deleted from queue is: " << queue[front]; // طباعة العنصر المحذوف
        front++; // زيادة المؤشر الأمامي لحذف العنصر الأول
    }
}

// دالة لعرض محتويات الصف
void Display() {
    if (front == -1) // التحقق إذا كان الصف فارغًا
        cout << "Queue is empty " << endl; // طباعة رسالة تفيد بأن الصف فارغ
    else {
        cout << "Queue elements are: "; 
        for (int i = front; i <= rear; i++) // عرض العناصر من المؤشر الأمامي إلى المؤشر الخلفي
            cout << queue[i] << " "; // طباعة كل عنصر في الصف
        cout << endl;
    }
}

int main() {
    int ch; // تعريف متغير للاختيار من القائمة
    cout << "1) Insert element to queue \n"; // الخيار الأول لإضافة عنصر
    cout << "2) Delete element from queue \n"; // الخيار الثاني لحذف عنصر
    cout << "3) Display all the elements of queue \n"; // الخيار الثالث لعرض جميع العناصر
    cout << "4) Exit \n"; // الخيار الرابع للخروج

    do {
        cout << "Enter your choice: "; // طلب إدخال الخيار من المستخدم
        cin >> ch;

        switch (ch) { // التبديل بناءً على اختيار المستخدم
        case 1: 
            Insert(); // استدعاء دالة الإضافة
            break;
        case 2: 
            Delete(); // استدعاء دالة الحذف
            break;
        case 3: 
            Display(); // استدعاء دالة العرض
            break;
        case 4: 
            cout << "Exit "; // طباعة رسالة الخروج
            break;
        default: 
            cout << "Invalid choice"; // طباعة رسالة إذا كان الخيار غير صحيح
        }
    } while (ch != 4); // الاستمرار في عرض القائمة حتى يختار المستخدم الخروج

    return 0; // إنهاء البرنامج بنجاح
}
