
#include "func.h"


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
