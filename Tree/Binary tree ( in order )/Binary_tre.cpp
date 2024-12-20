#include <iostream>  
using namespace std; 

/* تعريف هيكل الشجرة (Node structure) */
struct node {
    int value;  // قيمة العقدة (بيانات العقدة)
    struct node* left_child, * right_child;  // مؤشرات للعقدة اليسرى والعقدة اليمنى
};

// دالة لإنشاء عقدة جديدة في الشجرة
struct node* new_node(int value) {
    struct node* tmp = new struct node;  // تخصيص ذاكرة لعقدة جديدة باستخدام "new" بدلاً من malloc (طريقة أكثر أمانًا في C++)
    tmp->value = value;  // تعيين القيمة للعقدة
    tmp->left_child = tmp->right_child = NULL;  // تعيين المؤشرات للعقدة اليسرى واليمنى إلى NULL (بداية الشجرة تكون فارغة)
    return tmp;  // إرجاع المؤشر إلى العقدة الجديدة
}

// دالة للطباعة (التجول في الشجرة بنمط الترتيب التزايدي Inorder)
void print(struct node* root_node) {
    if (root_node != NULL) {  // إذا كانت العقدة غير فارغة
        print(root_node->left_child);  // أولاً، طباعة الشجرة اليسرى
        cout << " " << root_node->value;  // ثم طباعة قيمة العقدة
        print(root_node->right_child);  // أخيرًا، طباعة الشجرة اليمنى
    }
}

// دالة لإدخال قيمة جديدة في الشجرة الثنائية
struct node* insert_node(struct node* node, int value) {
    if (node == NULL) return new_node(value);  // إذا كانت الشجرة فارغة (أو عقدة فارغة)، قم بإنشاء عقدة جديدة بالقيمة المعطاة

    if (value < node->value) {  // إذا كانت القيمة أصغر من قيمة العقدة الحالية، أدخل القيمة في الشجرة اليسرى
        node->left_child = insert_node(node->left_child, value);
    }
    else if (value > node->value) {  // إذا كانت القيمة أكبر من قيمة العقدة الحالية، أدخل القيمة في الشجرة اليمنى
        node->right_child = insert_node(node->right_child, value);
    }
    
    // لا نفعل شيء إذا كانت القيمة مكررة (يمكنك إضافة check هنا إذا أردت منع القيم المكررة)

    return node;  // إرجاع العقدة الحالية بعد إضافة القيمة
}

int main() {
    cout << "Tech Vidvan Tutorial : Implementation of a Binary Tree in C++! \n\n";  // طباعة رسالة توضيحية للمستخدم

    struct node* root_node = NULL;  // بداية الشجرة فارغة
    root_node = insert_node(root_node, 10);  // إضافة القيمة 10 في الشجرة
    insert_node(root_node, 10);  // إضافة قيمة مكررة 10 (سيتم قبولها في الكود الحالي)
    insert_node(root_node, 30);  // إضافة القيمة 30 في الشجرة
    insert_node(root_node, 25);  // إضافة القيمة 25 في الشجرة
    insert_node(root_node, 36);  // إضافة القيمة 36 في الشجرة
    insert_node(root_node, 56);  // إضافة القيمة 56 في الشجرة
    insert_node(root_node, 78);  // إضافة القيمة 78 في الشجرة

    print(root_node);  // طباعة الشجرة بعد إضافة القيم
    return 0;  
}
