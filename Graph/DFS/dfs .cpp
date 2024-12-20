#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 5

// تعريف هيكل يمثل العقدة (Vertex) في الرسم البياني
struct Vertex {
    char lable;   // الحرف الذي يمثل العقدة
    bool visited; // لمعرفة إذا تمت زيارة هذه العقدة أثناء البحث
};

// تعريف stack (مكدس) لتتبع العقد أثناء البحث
int stack[MAX];
int top = -1; // مؤشر أعلى عنصر في المكدس

// قائمة لحفظ كل العقد في الرسم البياني
struct Vertex* lstVertices[MAX];

// مصفوفة التلاصق لتمثيل العلاقات بين العقد
int adjMatrix[MAX][MAX];

// عدد العقد الموجودة في الرسم البياني
int vertexCount = 0;

// دالة لدفع عنصر جديد إلى المكدس
void push(int item) {
    stack[++top] = item;
}

// دالة لإزالة العنصر العلوي من المكدس
int pop() {
    return stack[top--];
}

// دالة للحصول على العنصر العلوي من المكدس دون إزالته
int peek() {
    return stack[top];
}

// دالة للتحقق إذا كان المكدس فارغًا
bool isStackEmpty() {
    return top == -1;
}

// دالة لإضافة عقدة جديدة إلى الرسم البياني
void addVertex(char lable) {
    struct Vertex* vertex = new Vertex; // تخصيص ذاكرة للعقدة الجديدة
    vertex->lable = lable;              // تعيين الحرف الذي يمثل العقدة
    vertex->visited = false;            // لم يتم زيارتها بعد
    lstVertices[vertexCount++] = vertex; // إضافتها إلى قائمة العقد
}

// دالة لإضافة حافة (Edge) بين عقدتين
void addEdge(int start, int end) {
    adjMatrix[start][end] = 1; // تعيين 1 في مصفوفة التلاصق لتمثيل وجود علاقة
    adjMatrix[end][start] = 1; // تمثيل العلاقة في الاتجاه الآخر لأن الرسم ثنائي الاتجاه
}

// دالة لطباعة العقدة بناءً على الفهرس
void displayVertex(int vertexIndex) {
    printf("%c", lstVertices[vertexIndex]->lable);
}

// دالة للحصول على العقدة المجاورة غير المزارة
int getAdjUnvisitedVertex(int vertexIndex) {
    int i;
    for (i = 0; i < vertexCount; i++) {
        // تحقق إذا كانت هناك علاقة ولم تتم زيارة العقدة
        if (adjMatrix[vertexIndex][i] == 1 && lstVertices[i]->visited == false) {
            return i;
        }
    }
    return -1; // إذا لم توجد عقدة مجاورة غير مزارة
}

// دالة للبحث المتعمق (Depth First Search)
void depthFirstSearch() {
    int i;
    lstVertices[0]->visited = true; // بدء البحث من العقدة الأولى
    displayVertex(0);               // طباعة العقدة الأولى
    push(0);                        // إضافتها إلى المكدس

    // أثناء وجود عناصر في المكدس
    while (!isStackEmpty()) {
        int unvisitedVertex = getAdjUnvisitedVertex(peek()); // احصل على العقدة المجاورة غير المزارة
        if (unvisitedVertex == -1) {
            pop(); // إذا لم توجد عقدة، أزل العقدة من المكدس
        }
        else {
            lstVertices[unvisitedVertex]->visited = true; // علم العقدة كمزارة
            displayVertex(unvisitedVertex);               // طباعة العقدة
            push(unvisitedVertex);                        // أضفها إلى المكدس
        }
    }

    // إعادة تعيين كل العقد كغير مزارة بعد البحث
    for (i = 0; i < vertexCount; i++) {
        lstVertices[i]->visited = false;
    }
}

int main() {
    int i, j;

    // تهيئة مصفوفة التلاصق إلى 0
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            adjMatrix[i][j] = 0;
        }
    }

    // إضافة العقد إلى الرسم البياني
    addVertex('S'); // العقدة S
    addVertex('A'); // العقدة A
    addVertex('B'); // العقدة B
    addVertex('C'); // العقدة C
    addVertex('D'); // العقدة D

    // إضافة الحواف بين العقد
    addEdge(0, 1); // حافة بين S و A
    addEdge(0, 2); // حافة بين S و B
    addEdge(0, 3); // حافة بين S و C
    addEdge(1, 4); // حافة بين A و D
    addEdge(2, 4); // حافة بين B و D
    addEdge(3, 4); // حافة بين C و D

    // بدء البحث المتعمق
    printf("Depth First Search : ");
    depthFirstSearch();

    return 0;
}
