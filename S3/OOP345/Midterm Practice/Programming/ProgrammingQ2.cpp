// assume all necessary headers have been included

int main()
{
    {
        int *arrI = nullptr;
        arrI = insertAtEnd(arrI, 0, 1);  // 1
        arrI = insertAtEnd(arrI, 1, 5);  // 1, 5
        arrI = insertAtEnd(arrI, 2, -3); // 1, 5, -3
        delete[] arrI;
    }
    {
        double *arrD = nullptr;
        arrD = insertAtEnd(arrD, 0, 1.2); // 1.2
        arrD = insertAtEnd(arrD, 1, 2.3); // 1.2, 2.3
        arrD = insertAtEnd(arrD, 2, 3.4); // 1.2, 2.3, 3.4
        delete[] arrD;
    }
    {
        char *arrC = nullptr;
        arrC = insertAtEnd(arrC, 0, 'a'); // a\0
        arrC = insertAtEnd(arrC, 1, 'b'); // ab\0
        arrC = insertAtEnd(arrC, 2, 'c'); // abc\0
        cout << arrC;
        delete[] arrC;
    }
}