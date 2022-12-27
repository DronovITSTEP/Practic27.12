#include <iostream>

using namespace std;

/*
Написать функцию, которая получает указатель на массив и его размер,
и возвращает сумму и произведение его элементов в двух параметрах-указателях.
*/
void f1(int* arr, int size, int& sum, int& mult) {
    sum = 0, mult = 1;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
        mult *= arr[i];
    }
}

/*
Написать функцию, которая получает указатель
на массив и его размер, и возвращает количество отрицательных, 
положительных и нулевых элементов массива.
*/
int* f2(int* arr, int size) {
    int* countArr = new int[3]{0,0,0};
    int& poz = countArr[0];
    int& neg = countArr[1];
    int& zero = countArr[2];

    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) poz++;
        else if (arr[i] < 0) neg++;
        else zero++;
    }
    return countArr;
}

/*
Написать функцию, принимающую в качестве аргумента, указатели на два массива 
(А и В) и размеры массивов.
Функция проверяет, является ли массив В подмножеством
массива А и возвращает указатель на начало найденного
фрагмента, либо возвращает 0 в противном случае.
*/
int* f3(int* A, int* B, int sA, int sB) {
    int flag;
    for (int i = 0; i < sA - sB; i++) {
        flag = 0;
        if (B[0] == A[i]) {
            for (int j = 1; j < sB; j++) {
                if (B[j] != A[i + j]) flag = 1;
            }
            if (flag == 0) return &i;
        }
    }
    return &flag;
}

/*
Написать функцию, которая получает указатель
на динамический массив и его размер. Функция должна
удалить из массива все отрицательные числа и вернуть
указатель на новый динамический массив.
*/
int* f4(int* arr, int s, int& sP) {
    sP = 0;
    for (int i = 0; i < s; i++) {
        if (arr[i] >= 0) sP++;
    }

    int* temp = new int[sP];
    for (int i = 0, j = 0; i < s; i++) {
        if (arr[i] >= 0) {
            temp[j] = arr[i];
            j++;
        }
    }
    return temp;
}
/*
Создать функцию, позволяющую добавлять
блок элементов в конец массива.
*/
void f5(int* arr, int s, int* addArr, int new_s) {
    int* new_arr = new int[s + new_s];
    for (int i = 0, j = 0; i < s+ new_s; i++) {
        if (i < s) new_arr[i] = arr[i];
        else new_arr[i] = addArr[j++];
    }
    delete[]arr;
    arr = new_arr;
}


int main()
{
    /*const int size = 5;
    int arr[size]{ 5,7,6,3,1 };
    int sum, mult;
    f1(arr, size, sum, mult);
    cout << sum << " " << mult << endl;*/

    /*const int size = 10;
    int arr[size] = { 8,9,-4,5,0,0,-7,4,6,-2 };
    int* p = f2(arr, size);
    cout << "Pozitive = " << p[0] << endl
        << "Negative = " << p[1] << endl
        << "Zero = " << p[2];*/

    /*const int sizeA = 10;
    const int sizeB = 3;
    int arrA[sizeA]{ 8,7,9,6,3,4,2,1,3,0 };
    int arrB[sizeB]{ 3,4,2 };
    cout << *(f3(arrA, arrB, sizeA, sizeB));*/

    int arrA[10]{ 8,-7,9,-6,-3,4,2,1,-3,0 };
    int s;
    int* p = f4(arrA, 10, s);
    for (int i = 0; i < s; i++) {
        cout << p[i] << " ";
    }
}
