#include <iostream>
using namespace std;

int Parition(int *arr, int left, int right)
{ // 将arr[left]放到合适的位置
    int x = arr[left];
    while (left < right)
    {
        while (arr[right] >= x && left < right)
            right--;
        arr[left] = arr[right];
        while (arr[left] <= x && left < right)
            left++;
        arr[right] = arr[left];
    }
    arr[left] = x;
    return left;
}

void QuickSort(int *arr, int left, int right)
{
    if (left < right)
    {
        int i = Parition(arr, left, right);
        QuickSort(arr, left, i - 1);
        QuickSort(arr, i + 1, right);
    }
}

int main()
{
    int arr[] = {0, 5, 7, 4, 2, 8, 9};
    QuickSort(arr, 0, 6);
    for (int i = 0; i < 7; i++)
}