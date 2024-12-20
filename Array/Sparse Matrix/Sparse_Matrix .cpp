#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // تعريف المصفوفة النادرة
    int sparseMatrix[4][5] =
    {
        {0, 0, 3, 0, 4},
        {0, 0, 5, 7, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 6, 0, 0}
    };

    int size = 0; // عد العناصر غير الصفرية

    // حساب عدد العناصر غير الصفرية
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            if (sparseMatrix[i][j] != 0) {
                size++;
            }
        }
    }

    // تعريف المصفوفة المضغوطة باستخدام vector
    vector<vector<int>> compactMatrix(3, vector<int>(size));
    int k = 0;

    // تعبئة المصفوفة المضغوطة
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            if (sparseMatrix[i][j] != 0) {
                compactMatrix[0][k] = i;                 // الصف
                compactMatrix[1][k] = j;                 // العمود
                compactMatrix[2][k] = sparseMatrix[i][j]; // القيمة
                k++;
            }
        }
    }

    // عرض المصفوفة المضغوطة
    cout << "The compact matrix is:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < size; j++) {
            cout << compactMatrix[i][j] << " "; // إضافة مسافة بين العناصر
        }
        cout << "\n"; // الانتقال إلى السطر التالي بعد كل صف
    }

    return 0;
}
