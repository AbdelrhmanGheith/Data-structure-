#include <iostream>  
using namespace std; 

int stack[5];  // تعريف مصفوفة مكدس (Stack) بسعة 5 عناصر
int top = 0;  // تعريف المتغير top الذي يشير إلى الموضع الحالي في المكدس

// تعريف دوال المكدس
void push(int value);  // دالة لإدخال قيمة إلى المكدس
int pop();  // دالة لإزالة العنصر العلوي من المكدس
void traverse();  // دالة لعرض كل العناصر في المكدس
int is_empt();  // دالة للتحقق إذا كان المكدس فارغًا
int top_element();  // دالة لإرجاع العنصر العلوي في المكدس

int main() {
    int element, choice;  // تعريف متغيرات لاستقبال المدخلات من المستخدم

    // التكرار اللانهائي لاستقبال المدخلات وتنفيذ العمليات
    for (;;) {
        // عرض الخيارات المتاحة للمستخدم
        cout << "1. Insert into stack (Push operation).\n";
        cout << "2. Delete from stack (Pop operation).\n";
        cout << "3. Print top element of stack.\n";
        cout << "4. Check if stack is empty.\n";
        cout << "5. Traverse stack.\n";
        cout << "6. Exit.\n";
        cout << "Enter your choice: ";
        cin >> choice;  // استقبال الخيار من المستخدم

        switch (choice)  // التحقق من الخيار الذي اختاره المستخدم
        {
        case 1:
            // إذا كان المكدس ممتلئًا
            if (top == 5) {
                cout << "Error: Overflow\n\n";  // المكدس ممتلئ
            }
            else {
                cout << "Enter a value to insert: ";
                cin >> element;  // استقبال العنصر لإضافته إلى المكدس
                push(element);  // إضافة العنصر إلى المكدس
            }
            break;
        case 2:
            // إذا كان المكدس فارغًا
            if (top == 0) {
                cout << "Error: Underflow.\n";  // المكدس فارغ
            }
            else {
                element = pop();  // إزالة العنصر العلوي من المكدس
                cout << "Element removed from the stack is: " << element << "\n";  // عرض العنصر الذي تم إزالته
            }
            break;
        case 3:
            // إذا لم يكن المكدس فارغًا
            if (!is_empt()) {
                element = top_element();  // الحصول على العنصر العلوي
                cout << "Element at the top of the stack is: " << element << "\n";  // عرض العنصر العلوي
            }
            else {
                cout << "The stack is empty.\n\n";  // إذا كان المكدس فارغًا
            }
            break;
        case 4:
            // التحقق إذا كان المكدس فارغًا
            if (is_empt()) {
                cout << "The stack is empty.\n\n";  // المكدس فارغ
            }
            else {
                cout << "The stack isn't empty.\n\n";  // المكدس يحتوي على عناصر
            }
            break;
        case 5:
            traverse();  // عرض العناصر في المكدس
            break;
        case 6:
            exit(0);  // إيقاف البرنامج
            break;
        default:
            cout << "Invalid choice. Please try again.\n";  // خيار غير صحيح
        }
    }
}

// دالة لإدخال عنصر إلى المكدس
void push(int value) {
    stack[top] = value;  // إضافة القيمة إلى المكان الحالي في المصفوفة
    top++;  // زيادة قيمة top للإشارة إلى العنصر التالي في المكدس
}

// دالة لإزالة العنصر العلوي من المكدس وإرجاعه
int pop() {
    top--;  // تقليل قيمة top للإشارة إلى العنصر الذي سيتم إزالته
    return stack[top];  // إرجاع العنصر الذي كان في أعلى المكدس
}

// دالة لعرض كل العناصر في المكدس
void traverse() {
    int d;
    // إذا كان المكدس فارغًا
    if (top == 0) {
        cout << "The stack is empty.\n\n";  // إذا كان المكدس فارغًا
        return;
    }
    // إذا كان المكدس يحتوي على عناصر، عرض كل العناصر من الأعلى إلى الأسفل
    cout << "There are " << top << " elements in the stack:\n";
    for (d = top - 1; d >= 0; d--) {  // التكرار من أعلى المكدس إلى أسفله
        cout << stack[d] << "\n";  // عرض العنصر في المكدس
    }
}

// دالة للتحقق إذا كان المكدس فارغًا
int is_empt() {
    return top == 0;  // إرجاع 1 إذا كان المكدس فارغًا، و0 إذا كان يحتوي على عناصر
}

// دالة لإرجاع العنصر الموجود في أعلى المكدس
int top_element() {
    return stack[top - 1];  // إرجاع العنصر الذي في أعلى المكدس
}
