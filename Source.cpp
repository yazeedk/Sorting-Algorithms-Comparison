#include <iostream>
#include <algorithm>
#include <chrono>
#include <random>
using namespace std;

const int SIZE = 100;

int random_number(int low, int high) {
    static mt19937 engine(random_device{}());
    uniform_int_distribution<int> dist(low, high);
    return dist(engine);
}

void fill_random(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = random_number(1, 1000);
    }
}

void merge_sort(int* arr, int size) {
    if (size < 2) return;

    int mid = size / 2;
    int* left = arr;
    int* right = arr + mid;
    int left_size = mid;
    int right_size = size - mid;

    merge_sort(left, left_size);
    merge_sort(right, right_size);

    int* temp = new int[size];
    int i = 0, j = 0, k = 0;
    while (i < left_size && j < right_size) {
        if (left[i] < right[j]) {
            temp[k] = left[i];
            i++;
        }
        else {
            temp[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < left_size) {
        temp[k] = left[i];
        i++;
        k++;
    }
    while (j < right_size) {
        temp[k] = right[j];
        j++;
        k++;
    }

    for (int i = 0; i < size; i++) {
        arr[i] = temp[i];
    }

    delete[] temp;
}

void quick_sort(int* arr, int size) {
    if (size < 2) return;

    int pivot = arr[size / 2];


    int i = 0, j = size - 1;
    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            std::swap(arr[i], arr[j]);
            i++;
        }
    }
}
