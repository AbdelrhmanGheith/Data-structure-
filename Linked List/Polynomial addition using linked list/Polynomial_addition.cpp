#include <iostream>
using namespace std;

// تعريف هيكلية العقدة
struct node {
    int coeff;          // المعامل (قيمة معامل الحدود)
    int pow;            // الأس (درجة الحد)
    struct node* next;  // مؤشر يشير إلى العقدة التالية في القائمة المرتبطة
};

// دالة لإضافة عقدة جديدة في بداية القائمة المرتبطة
void insertNode(struct node** head, int pow, int coeff) {
    // إنشاء عقدة جديدة باستخدام المؤشر link
    struct node* link = new node;
    link->pow = pow;      // تخزين قيمة الأس في العقدة
    link->coeff = coeff;  // تخزين قيمة المعامل في العقدة
    link->next = *head;   // ربط العقدة الجديدة برأس القائمة الحالية
    *head = link;         // تحديث الرأس للإشارة إلى العقدة الجديدة
}

// دالة لطباعة متعدد الحدود
void printPolynomial(struct node* head) {
    struct node* ptr = head; // مؤشر للتنقل في القائمة
    cout << "\nPolynomial: ";
    while (ptr != NULL) { // الاستمرار حتى نهاية القائمة
        cout << ptr->coeff << "x^" << ptr->pow; // طباعة الحد بمعامله وأسه
        if (ptr->next != NULL) { // إذا كان هناك حد آخر، أضف علامة "+"
            cout << " + ";
        }
        ptr = ptr->next; // الانتقال إلى العقدة التالية
    }
    cout << endl; // إنهاء السطر بعد طباعة جميع الحدود
}

// دالة لجمع متعددات الحدود
struct node* addPolynomials(struct node* poly1, struct node* poly2) {
    struct node* result = NULL; // رأس القائمة الناتجة

    // التعامل مع حدود كل من متعددتي الحدود
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->pow > poly2->pow) {
            // إذا كانت درجة الحد في poly1 أكبر، أضف الحد إلى النتيجة
            insertNode(&result, poly1->pow, poly1->coeff);
            poly1 = poly1->next; // انتقل إلى الحد التالي في poly1
        }
        else if (poly1->pow < poly2->pow) {
            // إذا كانت درجة الحد في poly2 أكبر، أضف الحد إلى النتيجة
            insertNode(&result, poly2->pow, poly2->coeff);
            poly2 = poly2->next; // انتقل إلى الحد التالي في poly2
        }
        else {
            // إذا كانت الدرجات متساوية، اجمع المعاملات وأضف الحد إلى النتيجة
            int sumCoeff = poly1->coeff + poly2->coeff;
            insertNode(&result, poly1->pow, sumCoeff);
            poly1 = poly1->next; // انتقل إلى الحد التالي في poly1
            poly2 = poly2->next; // انتقل إلى الحد التالي في poly2
        }
    }

    // إضافة الحدود المتبقية من poly1 إلى النتيجة
    while (poly1 != NULL) {
        insertNode(&result, poly1->pow, poly1->coeff);
        poly1 = poly1->next;
    }

    // إضافة الحدود المتبقية من poly2 إلى النتيجة
    while (poly2 != NULL) {
        insertNode(&result, poly2->pow, poly2->coeff);
        poly2 = poly2->next;
    }

    return result; // إرجاع رأس القائمة الناتجة
}

// الدالة الرئيسية
int main() {
    // بناء متعدد الحدود الأول
    struct node* poly1 = NULL;
    insertNode(&poly1, 2, 3);  // إضافة الحد 3x^2
    insertNode(&poly1, 1, 4);  // إضافة الحد 4x^1
    insertNode(&poly1, 0, 2);  // إضافة الحد 2

    cout << "Polynomial 1:";
    printPolynomial(poly1); // طباعة متعدد الحدود الأول

    // بناء متعدد الحدود الثاني
    struct node* poly2 = NULL;
    insertNode(&poly2, 3, 1);  // إضافة الحد x^3
    insertNode(&poly2, 1, 5);  // إضافة الحد 5x^1
    insertNode(&poly2, 0, 6);  // إضافة الحد 6

    cout << "Polynomial 2:";
    printPolynomial(poly2); // طباعة متعدد الحدود الثاني

    // جمع متعددات الحدود
    struct node* result = addPolynomials(poly1, poly2);

    cout << "Resultant Polynomial:";
    printPolynomial(result); // طباعة النتيجة بعد الجمع

    return 0;
}
