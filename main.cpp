#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;


//void insertionsort(int* l, int* r) {
//    for (int *i = l + 1; i < r; i++) {
//        int* j = i;
//        while (j > l && *(j - 1) > *j) {
//            swap(*(j - 1), *j);
//            j--;
//        }
//    }
//}

/// original method
int shellsort(int arr[], int arr_size) {

    //Змінна для підрахунку кількості ітерацій
    int krok = 0;

    //починаємо з великим кроком ,поступово зменшуючи його
    for (int step = arr_size / 2; step > 0; step /= 2) {
        //Виконуемо сортування вставками для цього кроку
        //елементи першого кроку a[0..step-1] вже знаходяться у черзі порівняння
        //Продовжуємо додавати ще один елемент, доки не охопимо весь масив
        //крокове сортування
        for (int i = step; i < arr_size; i++) {
            //Додаємо a[i] до елементів , що були кроково відсортовані
            //Зберігаємо a[i] у temp(проміжна змінна, для зберігання елементів) та робимо отвір у позиції і
            int temp = arr[i];


            //Зсуваємо попередньо покроково відсортованні елементи до правильного
            //Місце для a[i] знайдено
            int j;
            for (j = i; j >= step && arr[j - step] > temp ; j -= step) {
                arr[j] = arr[j - step];
                krok++;
            }

            //поміщаємо temp (оригінальний a[i]) у правильне місце
            arr[j] = temp;
        }
    }

    cout << "count of steps:  " << krok << endl;
    return 0;
}

/// hibbard method
//int shellsort(int arr[], int arr_size) {
//
//    int krok = 0;
//    for (int increment = pow(2, (log(arr_size) / log(2))) - 1; increment > 0; increment /= 2) {
//        for (int i = increment; i < arr_size; i++) {
//            int temp = arr[i];
//            int j;
//            for (j = i; j >= increment && arr[j - increment] > temp; j -= increment) {
//                arr[j] = arr[j - increment];
//                krok++;
//            }
//            arr[j] = temp;
//        }
//    }
//
//    cout << "count of steps:  " << krok << endl;
//
//    return 0;
//}







int main() {
    int size;

    cout << "input the size of array: ";
    cin >> size;

    if (size < 1) {
        size = 1000;
    }

    int mas[size];

    for (int i = 0; i < sizeof(mas) / sizeof(mas[0]); i++) {
        mas[i] = rand() % 10000;
    }

    cout << "array" << endl;
    for (int i = 0; i < sizeof(mas) / sizeof(mas[0]); i++) {
        cout << mas[i] << '\t';
    }
    cout << endl << endl << endl;

    auto start = high_resolution_clock::now();
    shellsort(mas, sizeof(mas) / sizeof(mas[0]));

    //insertionsort(&mas[0], &mas[size]);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
    cout << duration.count() << " microseconds" << endl;

    cout << endl << endl << endl;

    cout << "sorted array" << endl;
    for (int i = 0; i < sizeof(mas) / sizeof(mas[0]); i++) {
        cout << mas[i] << '\t';
    }
    cout << endl;

    return 0;
}
