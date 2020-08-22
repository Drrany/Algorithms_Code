#include <iostream>
using namespace std;

void Merge(int *arr, int left, int mid, int right) // 将排好序的两段元素[left,mid]和[mid+1,right]合并
{

    int *copy = new int[right - left + 1];
    int i = left, j = mid + 1, index = 0;
    while (index < right - left + 1)
    {
        if (i > mid || (j <= right && arr[i] >= arr[j]))
            copy[index++] = arr[j++];
        else
            copy[index++] = arr[i++];
    }

    for (int k = left; k <= right; k++)
        arr[k] = copy[k - left];
}

void MergeSort(int *arr, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);
        Merge(arr, left, mid, right);
    }
}

int main()
{
    int arr[] = {0, 5, 7, 4, 2, 11, 9};
    cout << endl;
    MergeSort(arr, 0, 6);
    for (int i = 0; i < 7; i++)
    {
        cout << arr[i];
    }
}