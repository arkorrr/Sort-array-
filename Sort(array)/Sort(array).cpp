#include <iostream>
#include <time.h>
using namespace std;

//Task1
void random(int m[], int size)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        m[i] = rand() % 41 - 20;
    }
}

int pointI(int array[], int size)
{
    int pointI = 0;
    for (int i = 0; i < size;i++)
        if (array[i] < pointI)
        {
            pointI = i;
            break;
        }
    return pointI;
}

int pointJ(int array[], int size)
{
    int pointJ = 0;
    for (int i = size;i >= 0;i--)
    {
        if (array[i] < pointJ)
        {
            pointJ = i;
            break;
        }
    }
    return pointJ;
}

void sort(int pointI, int pointJ, int size, int array[])
{
    int value = 0;
    for (int i = pointI;i < pointJ;i++)
    {
        for (int j = pointI;j < pointJ - 1;j++)
        {
            if (array[j] > array[j + 1])
            {
                value = array[j];
                array[j] = array[j + 1];
                array[j + 1] = value;
            }
        }
    }
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << endl;
    }
}

//Task2
void random1(int m[], int size)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        m[i] = rand() % 21;
        cout << m[i] << endl;
    }
}

void Shuffle(int* x, int n, int index,int index1)
{
    for (int i = 0;i < n;i++)
    {
        int t = x[index];
        x[index] = x[index1];
        x[index1] = t;
        break;
    }
}

void randomDigit(int arr[], int size)
{
    int num = rand() % 21;
        for (int i = 0; i < size; i++) {
            if (arr[i] == num) {
                cout << "Index of random digit = " << i << endl;
                return;
            }
        }
        cout << "Random digit was not founded in array." << endl;
}

int main()
{
    /*1) Дан массив случайных чисел в диапазоне от –20 до + 20.
         Необходимо найти позиции крайних отрицательных
         элементов(самого левого отрицательного элемента
         и самого правого отрицательного элемента) и отсортировать элементы, находящиеся между ними.*/
         const int size = 10;
         int array[size];
         random(array, size);
         sort(pointI(array,size), pointJ(array,size), size, array);

         /*2) Дан массив из 20 целых чисел со значениями от 1 до 20.
         Необходимо:
         ■ написать функцию, разбрасывающую элементы массива произвольным образом;
         ■ создать случайное число из того же диапазона и найти
             позицию этого случайного числа в массиве;
         ■ отсортировать элементы массива, находящиеся слева от найденной позиции, по убыванию, а элементы
             массива, находящиеся справа от найденной позиции, по возрастанию.*/
    const int s = 20;
    int arr[s];
    random1(arr, s) ;
    cout << endl;
    int b = 1;
    while (b != 0)
    {
        int funct;
        cout << "Enter 1 if you want to shaffle digit in array." << endl;
        cout << "Enter 0 if dont want to shaffle digit in array." << endl;
        cin >> funct;
        switch (funct)
        {
        case 1:
            int index, index1;
            cout << "Enter enter the index which number you will want to swap." << endl;
            cin >> index;
            cout << "Enter enter the index at which this number will be." << endl;
            cin >> index1;
            Shuffle(arr, s, index, index1);
            break;
        case 0:
            cout << "Array after shuffle. " << endl;
            for (int i = 0; i < s; i++)
            {
                cout << arr[i] << endl;
            }
            b--;
            break;
        }
    };
    cout << endl;
    randomDigit(arr, s);
}