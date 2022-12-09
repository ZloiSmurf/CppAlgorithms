#pragma once
/******************************************************************************
* Файл: Sorts.h
* Описание : Файл содержит 3 различных алгоритма сортировки
* Создан : 29 апреля 2022
* Автор : Сергей Манкевич
* *****************************************************************************/


void BubbleSort(int* array, int len) {
    /**
    * Реализует сортировку пузырьком
    * @param *array - неотсортированный массив
    * @param len - длина массив
    * @return отсортированный массив
    */
    for (int i = 0; i < len - 1; i++) {
        // сравниваем два соседних элемента.
        for (int j = 0; j < len - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                // если они идут в неправильном порядке, то меняем их местами. 
                int tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }
}

void QuickSort(int* array, int first, int last) {
    /**
    * Реализует быструю сортировку
    * @param *array - неотсортированный массив
    * @param len - длина массив
    * @param first - первый элемент
    * @param last - последний элемент
    * @return отсортированный массив
    */
    if (first < last)
    {
        //находим серединный элемент 
        int left = first, right = last, middle = array[(left + right) / 2];
        do
        {
            while (array[left] < middle) left++;
            while (array[right] > middle) right--;
            //сортировка
            if (left <= right)
            {
                int tmp = array[left];
                array[left] = array[right];
                array[right] = tmp;
                left++;
                right--;
            }
        } while (left <= right);
        //рекурсивный вызов
        QuickSort(array, first, right);
        QuickSort(array, left, last);
    }
}


void ShellSort(int* array, int size) {
    /**
    * Реализует сортировку Шелла
    * @param *array - неотсортированный массив
    * @param len - длина массив
    * @return отсортированный массив
    */
    int i, j, d;
    //d берём равным N/2 
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
