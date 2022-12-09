#pragma once
/******************************************************************************
* ����: Sorts.h
* �������� : ���� �������� 3 ��������� ��������� ����������
* ������ : 29 ������ 2022
* ����� : ������ ��������
* *****************************************************************************/


void BubbleSort(int* array, int len) {
    /**
    * ��������� ���������� ���������
    * @param *array - ����������������� ������
    * @param len - ����� ������
    * @return ��������������� ������
    */
    for (int i = 0; i < len - 1; i++) {
        // ���������� ��� �������� ��������.
        for (int j = 0; j < len - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                // ���� ��� ���� � ������������ �������, �� ������ �� �������. 
                int tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }
}

void QuickSort(int* array, int first, int last) {
    /**
    * ��������� ������� ����������
    * @param *array - ����������������� ������
    * @param len - ����� ������
    * @param first - ������ �������
    * @param last - ��������� �������
    * @return ��������������� ������
    */
    if (first < last)
    {
        //������� ���������� ������� 
        int left = first, right = last, middle = array[(left + right) / 2];
        do
        {
            while (array[left] < middle) left++;
            while (array[right] > middle) right--;
            //����������
            if (left <= right)
            {
                int tmp = array[left];
                array[left] = array[right];
                array[right] = tmp;
                left++;
                right--;
            }
        } while (left <= right);
        //����������� �����
        QuickSort(array, first, right);
        QuickSort(array, left, last);
    }
}


void ShellSort(int* array, int size) {
    /**
    * ��������� ���������� �����
    * @param *array - ����������������� ������
    * @param len - ����� ������
    * @return ��������������� ������
    */
    int i, j, d;
    //d ���� ������ N/2 
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
