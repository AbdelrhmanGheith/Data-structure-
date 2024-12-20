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

// دالة للطباعة (التجول في الشجرة بنمط Post-order)
void print(struct node* root_node) {
    if (root_node != NULL) {  // إذا كانت العقدة غير فارغة
        print(root_node->left_child);  // أولاً، زيارة الشجرة اليسرى
        print(root_node->right_child);  // ثم، زيارة الشجرة اليمنى
        cout << " " << root_node->value;  // أخيرًا، طباعة قيمة العقدة
    }
}

// دالة لإدخال قيمة جديدة في الشجرة الثنائية
struct node* insert_node(struct node* node, int value) {
    if (node == NULL) return new_node(value);  // إذا كانت الشجرة فارغة (أو عقدة فارغة)، قم بإنشاء عقدة جديدة بالقيمة المعطاة

    // إذا كانت القيمة أقل من قيمة العقدة الحالية، أدخل القيمة في الشجرة اليسرى
    if (value < node->value) {
        node->left_child = insert_node(node->left_child, value);
    }
    // إذا كانت القيمة أكبر من قيمة العقدة الحالية، أدخل القيمة في الشجرة اليمنى
    else if (value > node->value) {
        node->right_child = insert_node(node->right_child, value);
    }
    // إذا كانت القيمة مكررة، لا نقوم بإدخالها، ونتجاهلها
    else {
        cout << "Duplicate value " << value << " not inserted." << endl;  // طباعة رسالة عندما تكون القيمة مكررة
    }

    return node;  // إرجاع العقدة الحالية بعد إضافة القيمة
}

int main() {
    cout << "Tech Vidvan Tutorial: Implementation of a Binary Tree in C++! \n\n";  // طباعة رسالة توضيحية للمستخدم

    struct node* root_node = NULL;  // بداية الشجرة فارغة
    
    int num_values, value;
    cout << "Enter the number of values to insert into the binary tree: ";
    cin >> num_values;  // طلب عدد القيم التي سيقوم المستخدم بإدخالها

    for (int i = 0; i < num_values; ++i) {
        cout << "Enter value " << i + 1 << ": ";
        cin >> value;  // إدخال القيمة من المستخدم
        root_node = insert_node(root_node, value);  // إدخال القيمة في الشجرة
    }

    cout << "Post-order Traversal of the Binary Tree: ";
    print(root_node);  // طباعة الشجرة بعد إضافة القيم
    cout << endl;  // الانتقال إلى السطر التالي بعد الطباعة
    return 0;  // نهاية البرنامج
}
