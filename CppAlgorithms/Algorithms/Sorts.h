#pragma once
/******************************************************************************
* File: Sorts.h
* Description : Contains various sorting algorithms
* Created : April 29, 2022
* Author : Sergey Mankevich
* *****************************************************************************/


void BubbleSort(int* array, int len) {
    /**
    * Implements bubble sorting
    * @param *array - unsorted array
    * @param len - array length
    * @return sorted array
    */
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }
}

void QuickSort(int* array, int first, int last) {
    /**
    * Implements quick sorting
    * @param *array - unsorted array
    * @param len - array length
    * @param first - first element
    * @param last - last element
    * @return sorted array
    */
    if (first < last) {

        int left = first, right = last, middle = array[(left + right) / 2];
        do {
            while (array[left] < middle) left++;
            while (array[right] > middle) right--;

            if (left <= right)
            {
                int tmp = array[left];
                array[left] = array[right];
                array[right] = tmp;
                left++;
                right--;
            }
        } while (left <= right);

        QuickSort(array, first, right);
        QuickSort(array, left, last);
    }
}


void ShellSort(int* array, int size) {
    /**
    * Implements Shell sorting
    * @param *array - unsorted array
    * @param len - array length
    * @return sorted array
    */
    int i, j, d;
    for (d = size / 2; d > 0; d /= 2) {
        for (i = d; i < size; ++i) {
            int tmp = array[i];
            for (j = i; j >= d; j -= d) {
                if (tmp < array[j - d]) {
                    array[j] = array[j - d];
                }
                else {
                    break;
                }
            }
            array[j] = tmp;
        }
    }
}
