#include <stdio.h>  // تضمين مكتبة الإدخال/الإخراج لطباعة النصوص
#include <stdlib.h>  // تضمين مكتبة العمليات العامة مثل تخصيص الذاكرة
#include <stdbool.h>  // تضمين مكتبة القيم البوليانية (true/false)
#define MAX 5  // تعريف الحد الأقصى لعدد الرؤوس في الرسم البياني

// تعريف هيكل Vertex الذي يمثل الرأس في الرسم البياني
struct Vertex {
    char label;  // تسمية الرأس (مثل 'S', 'A', 'B' ...)
    bool visited;  // علم يشير إذا كان الرأس قد تم زيارته أثناء البحث
};

// تعريف مصفوفة لحفظ عناصر الصف
int queue[MAX];  // مصفوفة للصف بحد أقصى MAX
int rear = -1;  // مؤشر نهاية الصف
int front = 0;  // مؤشر بداية الصف
int queueItemCount = 0;  // عدد العناصر في الصف

// مصفوفة لتخزين رؤوس الرسم البياني
struct Vertex* lstVertices[MAX];  // مصفوفة تحتوي على مؤشرات للرؤوس

// مصفوفة الجوار التي تمثل الرسم البياني
int adjMatrix[MAX][MAX];  // مصفوفة لتمثيل العلاقات بين الرؤوس (مصفوفة الجوار)

int vertexCount = 0;  // عداد الرؤوس في الرسم البياني

// دالة لإدراج عنصر في الصف
void insert(int data) {
    queue[++rear] = data;  // إضافة عنصر في نهاية الصف
    queueItemCount++;  // زيادة عدد العناصر في الصف
}

// دالة لإزالة عنصر من الصف
int removeData() {
    queueItemCount--;  // تقليل عدد العناصر في الصف
    return queue[front++];  // إزالة العنصر من بداية الصف
}

// دالة للتحقق مما إذا كان الصف فارغًا
bool isQueueEmpty() {
    return queueItemCount == 0;  // إذا كان عدد العناصر صفرًا فإن الصف فارغ
}

// دالة لإضافة رأس إلى الرسم البياني
void addVertex(char label) {
    struct Vertex* vertex = (struct Vertex*)malloc(sizeof(struct Vertex));  // تخصيص ذاكرة لرأس جديد
    vertex->label = label;  // تعيين التسمية للرأس
    vertex->visited = false;  // تعيين أن الرأس لم يُزر بعد
    lstVertices[vertexCount++] = vertex;  // إضافة الرأس إلى المصفوفة وزيادة عداد الرؤوس
}

// دالة لإضافة حافة بين رأسين
void addEdge(int start, int end) {
    adjMatrix[start][end] = 1;  // تعيين قيمة 1 في المصفوفة لتشير إلى وجود حافة بين الرأسين
    adjMatrix[end][start] = 1;  // لأن الرسم البياني غير موجه
}

// دالة لعرض رأس معين
void displayVertex(int vertexIndex) {
    printf("%c ", lstVertices[vertexIndex]->label);  // طباعة التسمية الخاصة بالرأس
}

// دالة لإيجاد رأس غير مزار في الجوار
int getAdjUnvisitedVertex(int vertexIndex) {
    int i;
    for (i = 0; i < vertexCount; i++) {
        if (adjMatrix[vertexIndex][i] == 1 && lstVertices[i]->visited == false) {
            return i;  // إذا كان هناك حافة ولم يتم زيارة الرأس بعد، إرجاع المؤشر
        }
    }
    return -1;  // إذا لم توجد رؤوس غير مزارة في الجوار
}

// دالة تنفيذ البحث باستخدام العرض الأول (BFS)
void breadthFirstSearch() {
    int i;
    lstVertices[0]->visited = true;  // تعيين الرأس الأول كمزار
    displayVertex(0);  // عرض الرأس الأول
    insert(0);  // إضافة الرأس الأول إلى الصف

    int unvisitedVertex;
    while (!isQueueEmpty()) {  // طالما أن الصف ليس فارغًا
        int tempVertex = removeData();  // إزالة رأس من الصف
        while ((unvisitedVertex = getAdjUnvisitedVertex(tempVertex)) != -1) {  // العثور على رأس غير مزار في الجوار
            lstVertices[unvisitedVertex]->visited = true;  // تعيين الرأس كمزار
            displayVertex(unvisitedVertex);  // عرض الرأس
            insert(unvisitedVertex);  // إضافة الرأس إلى الصف
        }
    }

    // إعادة تعيين كافة الرؤوس كغير مزارة بعد انتهاء البحث
    for (i = 0; i < vertexCount; i++) {
        lstVertices[i]->visited = false;
    }
}

// دالة main لتنفيذ البرنامج
int main() {
    int i, j;
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            adjMatrix[i][j] = 0;  // تهيئة مصفوفة الجوار لتكون كلها 0 (لا توجد حواف في البداية)
        }
    }

    // إضافة الرؤوس إلى الرسم البياني
    addVertex('S');
    addVertex('A');
    addVertex('B');
    addVertex('C');
    addVertex('D');

    // إضافة الحواف بين الرؤوس
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(0, 3);
    addEdge(1, 4);
    addEdge(2, 4);
    addEdge(3, 4);

    // تنفيذ البحث باستخدام العرض الأول (BFS)
    printf("Breadth First Search: ");
    breadthFirstSearch();

    return 0; 
}
