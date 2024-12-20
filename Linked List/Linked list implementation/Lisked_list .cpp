#include <iostream> // تضمين مكتبة الإدخال والإخراج
using namespace std;

// تعريف هيكلية العقدة
struct node {
    int data;             // تخزين البيانات
    int key;              // المفتاح الفريد للعقدة
    struct node* next;    // مؤشر للعقدة التالية
};

// تعريف رأس القائمة
struct node* head = NULL; // الرأس يبدأ كـ NULL لأن القائمة فارغة

// وظيفة لإضافة عقدة جديدة في بداية القائمة
void insertFirst(int key, int data) {
    struct node* link = new node; // إنشاء عقدة جديدة باستخدام "new"
    link->key = key;             // تعيين المفتاح
    link->data = data;           // تعيين البيانات
    link->next = head;           // الإشارة إلى الرأس الحالي
    head = link;                 // تحديث الرأس ليشير إلى العقدة الجديدة
}

// وظيفة لطباعة القائمة
void printList() {
    struct node* ptr = head;     // البدء من الرأس
    cout << "\n[ ";
    while (ptr != NULL) {        // التنقل عبر القائمة حتى الوصول إلى النهاية
        cout << ptr->key << " , " << ptr->data << "\t"; // طباعة المفتاح والبيانات
        ptr = ptr->next;         // الانتقال إلى العقدة التالية
    }
    cout << " ]";
}

// وظيفة لحذف العقدة الأولى
struct node* deleteFirst() {
    if (head == NULL) {          // التحقق إذا كانت القائمة فارغة
        cout << "List is empty." << endl;
        return NULL;
    }
    struct node* tempLink = head; // حفظ العقدة الحالية ليتم حذفها
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
    while (current->key != key) { // البحث عن المفتاح
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
    struct node* previous = NULL; // عقدة مؤقتة للعقدة السابقة
    if (head == NULL) {           // إذا كانت القائمة فارغة
        return NULL;
    }
    while (current->key != key) { // البحث عن المفتاح
        if (current->next == NULL) { // إذا لم يتم العثور على المفتاح
            return NULL;
        }
        previous = current;       // تحديث العقدة السابقة
        current = current->next;  // الانتقال إلى العقدة التالية
    }
    if (current == head) {        // إذا كانت العقدة هي الرأس
        head = head->next;        // تحديث الرأس ليشير إلى العقدة التالية
    } else {
        previous->next = current->next; // تجاوز العقدة المحذوفة
    }
    delete current;               // تحرير ذاكرة العقدة المحذوفة
    return head;
}

// وظيفة لترتيب القائمة بناءً على البيانات
void sort() {
    int tempKey, tempData;        // متغيرات مؤقتة لتبديل البيانات
    struct node* current;
    struct node* next;
    int size = length();          // حساب طول القائمة
    for (int i = 0; i < size - 1; i++) { // دورة خارجية للمرور عبر القائمة
        current = head;           // البدء من الرأس
        next = head->next;        // العقدة التالية
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
    // إضافة عقد إلى القائمة
    insertFirst(1, 10);
    insertFirst(2, 20);
    insertFirst(3, 30);

    // طباعة القائمة
    cout << "Initial List: ";
    printList();

    // حذف العقدة الأولى
    cout << "\nDeleting first node." << endl;
    deleteFirst();
    printList();

    // البحث عن عقدة بمفتاح معين
    cout << "\nFinding node with key 2." << endl;
    struct node* found = find(2);
    if (found != nullptr) { // إذا تم العثور على العقدة
        cout << "Found node: (" << found->key << ", " << found->data << ")" << endl;
    } else {
        cout << "Node not found." << endl;
    }

    // ترتيب القائمة
    cout << "\nSorting the list." << endl;
    sort();
    printList();

    return 0;
}
