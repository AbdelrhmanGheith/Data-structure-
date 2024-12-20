  #include <iostream>  
using namespace std;  

// تعريف هيكل العقدة (Node) في الشجرة الثنائية
struct node
{
    int value;  // القيمة المخزنة في العقدة
    struct node* left_child, * right_child;  // المؤشرات إلى الطفل الأيسر والطفل الأيمن
};

// دالة لإنشاء عقدة جديدة تحتوي على قيمة معينة
struct node* new_node(int value)
{
    struct node* tmp = new struct node;  // إنشاء عقدة جديدة باستخدام new بدلاً من malloc
    tmp->value = value;  // تعيين القيمة للعقدة الجديدة
    tmp->left_child = tmp->right_child = NULL;  // تعيين المؤشرات إلى NULL (لا يوجد أطفال بعد)
    return tmp;  // إرجاع المؤشر إلى العقدة الجديدة
}

// دالة للطباعة (التجول في الشجرة بنمط الترتيب التزايدي Inorder)
void print(struct node* root_node)
{
    if (root_node != NULL)  // إذا كانت العقدة الحالية ليست فارغة
    {
        print(root_node->left_child);  // أولاً، قم بزيارة الطفل الأيسر
        cout << " " << root_node->value;  // ثم طباعة قيمة العقدة
        print(root_node->right_child);  // أخيرًا، قم بزيارة الطفل الأيمن
    }
}

// دالة لإدخال قيمة جديدة في الشجرة الثنائية
struct node* insert_node(struct node* node, int value)
{
    if (node == NULL) return new_node(value);  // إذا كانت الشجرة فارغة (أو عقدة فارغة)، قم بإنشاء عقدة جديدة بالقيمة المعطاة

    // إذا كانت القيمة أقل من قيمة العقدة الحالية، أدخل القيمة في الشجرة اليسرى
    if (value < node->value) {
        node->left_child = insert_node(node->left_child, value);
    }
    // إذا كانت القيمة أكبر من قيمة العقدة الحالية، أدخل القيمة في الشجرة اليمنى
    else if (value > node->value) {
        node->right_child = insert_node(node->right_child, value);
    }
    
    // لا نفعل شيء إذا كانت القيمة مكررة (يمكنك إضافة check هنا إذا أردت منع القيم المكررة)

    return node;  // إرجاع العقدة الحالية بعد إضافة القيمة
}

// دالة لإدخال قيم الشجرة من المستخدم
void input_tree(struct node*& root_node) {
    int number_of_nodes;  // عدد العقد التي يريد المستخدم إدخالها
    cout << "Enter the number of nodes you want to insert: ";
    cin >> number_of_nodes;  // إدخال عدد العقد من المستخدم

    for (int i = 0; i < number_of_nodes; ++i) {
        int value;  // القيمة التي سيتم إدخالها
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> value;  // إدخال القيمة من المستخدم
        root_node = insert_node(root_node, value);  // إدخال القيمة في الشجرة
    }
}

int main()
{
    cout << "Tech Vidvan Tutorial: Implementation of a Binary Tree in C++! \n\n";

    struct node* root_node = NULL;  // بداية الشجرة فارغة (لا توجد عقد)

    input_tree(root_node);  // طلب إدخال قيم من المستخدم وإضافتها إلى الشجرة

    cout << "Inorder traversal of the binary tree:" << endl;
    print(root_node);  // طباعة الشجرة باستخدام الترتيب التزايدي (Inorder Traversal)

    return 0;  
}
