#include <iostream>
using namespace std;

// تعريف بنية العقدة في القائمة المرتبطة
struct node {
    int data;             // تخزين البيانات
    int key;              // المفتاح الفريد للعقدة
    struct node* next;    // مؤشر للعقدة التالية
};

struct node* head = NULL; // مؤشر إلى بداية القائمة (القائمة تبدأ كـ فارغة)

// وظيفة لإضافة عقدة جديدة في بداية القائمة
void insertFirst(int key, int data) {
    struct node* link = new node; // إنشاء عقدة جديدة باستخدام "new"
    link->key = key;             // تعيين المفتاح
    link->data = data;           // تعيين البيانات
    link->next = head;           // جعل العقدة الجديدة تشير إلى الرأس الحالي
    head = link;                 // تحديث الرأس ليصبح العقدة الجديدة
}

// وظيفة لطباعة القائمة
void printList() {
    struct node* ptr = head;      // البدء من الرأس
    cout << "\n[ ";
    while (ptr != NULL) {         // التنقل عبر القائمة حتى نهاية العقد
        cout << ptr->key << " , " << ptr->data << "\t"; // طباعة المفتاح والبيانات
        ptr = ptr->next;          // الانتقال إلى العقدة التالية
    }
    cout << " ]";
}

// وظيفة لحذف العقدة الأولى
struct node* deleteFirst() {
    if (head == NULL) {           // إذا كانت القائمة فارغة
        cout << "List is empty." << endl;
        return NULL;
    }
    struct node* tempLink = head; // حفظ العقدة الحالية التي سيتم حذفها
    head = head->next;            // تحديث الرأس ليشير إلى العقدة التالية
    delete tempLink;              // تحرير ذاكرة العقدة المحذوفة
    return head;
}

// وظيفة للتحقق مما إذا كانت القائمة فارغة
bool isEmpty() {
    return head == NULL;          // إذا كان الرأس NULL، القائمة فارغة
}

// وظيفة لحساب طول القائمة
int length() {
    int length = 0;               // عداد الطول
    struct node* current = head;  // البدء من الرأس
    while (current != NULL) {     // التنقل عبر القائمة
        length++;                 // زيادة العداد
        current = current->next;  // الانتقال إلى العقدة التالية
    }
    return length;                // إرجاع الطول
}

// وظيفة للبحث عن عقدة باستخدام المفتاح
struct node* find(int key) {
    struct node* current = head;  // البدء من الرأس
    if (head == NULL) {           // إذا كانت القائمة فارغة
        return NULL;
    }
    while (current->key != key) { // التنقل عبر القائمة
        if (current->next == NULL) { // إذا لم يتم العثور على المفتاح
            return NULL;
        }
        current = current->next;  // الانتقال إلى العقدة التالية
    }
    return current;               // إرجاع العقدة التي تحتوي على المفتاح
}

// وظيفة لحذف عقدة باستخدام المفتاح
struct node* delet(int key) {
    struct node* current = head;  // البدء من الرأس
    struct node* previous = NULL; // مؤشر للعقدة السابقة
    if (head == NULL) {           // إذا كانت القائمة فارغة
        return NULL;
    }
    while (current->key != key) { // التنقل عبر القائمة للبحث عن المفتاح
        if (current->next == NULL) { // إذا لم يتم العثور على المفتاح
            return NULL;
        }
        previous = current;       // تحديث العقدة السابقة
        current = current->next;  // الانتقال إلى العقدة التالية
    }
    if (current == head) {        // إذا كانت العقدة التي سيتم حذفها هي الرأس
        head = head->next;        // تحديث الرأس ليشير إلى العقدة التالية
    } else {
        previous->next = current->next; // تجاوز العقدة الحالية
    }
    delete current;               // تحرير ذاكرة العقدة المحذوفة
    return head;
}

// وظيفة لترتيب القائمة باستخدام التبديل
void sort() {
    int tempKey, tempData;        // متغيرات مؤقتة لتبديل البيانات
    struct node* current;
    struct node* next;
    int size = length();          // حساب طول القائمة
    for (int i = 0; i < size - 1; i++) { // دورة خارجية للتكرار
        current = head;           // البدء من الرأس
        next = head->next;        // الإشارة إلى العقدة التالية
        while (next != NULL) {    // التنقل عبر القائمة
            if (current->data > next->data) { // إذا كانت البيانات غير مرتبة
                // تبديل البيانات
                tempData = current->data;
                current->data = next->data;
                next->data = tempData;

                tempKey = current->key;
                current->key = next->key;
                next->key = tempKey;
            }
            current = next;       // الانتقال إلى العقدة التالية
            next = next->next;
        }
    }
}

// الدالة الرئيسية
int main() {
    int choice, key, data;

    // قائمة الخيارات
    while (true) {
        cout << "\nMenu:";
        cout << "\n1. Insert a node";
        cout << "\n2. Print the list";
        cout << "\n3. Delete the first node";
        cout << "\n4. Find a node by key";
        cout << "\n5. Delete a node by key";
        cout << "\n6. Sort the list";
        cout << "\n7. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: // إدخال عقدة جديدة
            cout << "Enter key: ";
            cin >> key;
            cout << "Enter data: ";
            cin >> data;
            insertFirst(key, data);
            break;

        case 2: // طباعة القائمة
            printList();
            break;

        case 3: // حذف العقدة الأولى
            deleteFirst();
            break;

        case 4: // البحث عن عقدة بالمفتاح
            cout << "Enter key to find: ";
            cin >> key;
            {
                struct node* found = find(key);
                if (found != nullptr) {
                    cout << "Found node: (" << found->key << ", " << found->data << ")" << endl;
                } else {
                    cout << "Node not found." << endl;
                }
            }
            break;

        case 5: // حذف عقدة بالمفتاح
            cout << "Enter key to delete: ";
            cin >> key;
            delet(key);
            break;

        case 6: // ترتيب القائمة
            sort();
            cout << "List sorted successfully." << endl;
            break;

        case 7: // إنهاء البرنامج
            cout << "Exiting program." << endl;
            return 0;

        default: // خيار غير صالح
            cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}
