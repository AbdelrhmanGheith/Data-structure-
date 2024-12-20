#include <iostream> 
using namespace std;

// تعريف هيكلية العقدة التي تمثل حدًا في متعدد الحدود
struct node {
    int coeff;          // المعامل (قيمة معامل الحد)
    int pow;            // الأس (درجة الحد)
    struct node* next;  // مؤشر يشير إلى العقدة التالية في القائمة المرتبطة
};

// دالة لإضافة عقدة جديدة في بداية القائمة المرتبطة
void insertNode(struct node** head, int pow, int coeff) {
    struct node* link = new node; // إنشاء عقدة جديدة ديناميكيًا
    link->pow = pow;              // تخزين قيمة الأس في العقدة الجديدة
    link->coeff = coeff;          // تخزين قيمة المعامل في العقدة الجديدة
    link->next = *head;           // ربط العقدة الجديدة برأس القائمة الحالية
    *head = link;                 // تحديث الرأس للإشارة إلى العقدة الجديدة
}

// دالة لطباعة متعدد الحدود
void printPolynomial(struct node* head) {
    struct node* ptr = head;       // مؤشر للتنقل عبر العقد
    cout << "\nPolynomial: ";     // طباعة عنوان
    while (ptr != NULL) {         // التكرار حتى نهاية القائمة المرتبطة
        cout << ptr->coeff << "x^" << ptr->pow; // طباعة الحد بصيغة المعامل والأس
        if (ptr->next != NULL) {  // إذا كانت هناك حدود أخرى بعده
            cout << " + ";        // أضف علامة الجمع بين الحدود
        }
        ptr = ptr->next;          // الانتقال إلى العقدة التالية
    }
    cout << endl;                 // إنهاء السطر بعد طباعة جميع الحدود
}

// دالة لجمع متعددات الحدود
struct node* addPolynomials(struct node* poly1, struct node* poly2) {
    struct node* result = NULL; // رأس القائمة الناتجة للجمع

    // التكرار على الحدود في متعددتي الحدود الأولى والثانية
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->pow > poly2->pow) { // إذا كان الأس في poly1 أكبر
            insertNode(&result, poly1->pow, poly1->coeff); // أضف الحد من poly1
            poly1 = poly1->next;        // انتقل إلى الحد التالي في poly1
        }
        else if (poly1->pow < poly2->pow) { // إذا كان الأس في poly2 أكبر
            insertNode(&result, poly2->pow, poly2->coeff); // أضف الحد من poly2
            poly2 = poly2->next;        // انتقل إلى الحد التالي في poly2
        }
        else { // إذا كان الأس متساويًا
            int sumCoeff = poly1->coeff + poly2->coeff; // اجمع المعاملات
            insertNode(&result, poly1->pow, sumCoeff);  // أضف النتيجة إلى القائمة الناتجة
            poly1 = poly1->next;        // انتقل إلى الحد التالي في poly1
            poly2 = poly2->next;        // انتقل إلى الحد التالي في poly2
        }
    }

    // إضافة الحدود المتبقية في poly1 إلى القائمة الناتجة
    while (poly1 != NULL) {
        insertNode(&result, poly1->pow, poly1->coeff);
        poly1 = poly1->next;
    }

    // إضافة الحدود المتبقية في poly2 إلى القائمة الناتجة
    while (poly2 != NULL) {
        insertNode(&result, poly2->pow, poly2->coeff);
        poly2 = poly2->next;
    }

    return result; // إرجاع رأس القائمة الناتجة
}

// دالة لإدخال حدود متعدد الحدود من المستخدم
struct node* inputPolynomial() {
    struct node* poly = NULL; // بداية القائمة فارغة
    int terms; // عدد الحدود في متعدد الحدود
    cout << "Enter the number of terms in the polynomial: ";
    cin >> terms; // إدخال عدد الحدود

    // إدخال كل حد من متعدد الحدود
    for (int i = 0; i < terms; i++) {
        int coeff, pow; // المعامل والأس
        cout << "Enter coefficient and power for term " << i + 1 << ": ";
        cin >> coeff >> pow; // إدخال القيم
        insertNode(&poly, pow, coeff); // إضافة الحد إلى القائمة
    }

    return poly; // إرجاع رأس القائمة
}

// الدالة الرئيسية
int main() {
    // إدخال متعدد الحدود الأول من المستخدم
    cout << "Input Polynomial 1:\n";
    struct node* poly1 = inputPolynomial(); // بناء متعدد الحدود الأول
    cout << "Polynomial 1:";
    printPolynomial(poly1); // طباعة متعدد الحدود الأول

    // إدخال متعدد الحدود الثاني من المستخدم
    cout << "Input Polynomial 2:\n";
    struct node* poly2 = inputPolynomial(); // بناء متعدد الحدود الثاني
    cout << "Polynomial 2:";
    printPolynomial(poly2); // طباعة متعدد الحدود الثاني

    // جمع متعددات الحدود
    struct node* result = addPolynomials(poly1, poly2); // جمع متعددات الحدود
    cout << "Resultant Polynomial:";
    printPolynomial(result); // طباعة متعدد الحدود الناتج

    return 0; 
}
