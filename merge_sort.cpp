#include <iostream>
#include <vector>

using namespace std;
void merge(int low, int mid, int high, vector<int> &arr)
{
    int i, j, k = low;
    vector<int> Larr;
    vector<int> Rarr;
    for (i = low; i <= mid; i++)
    {
        Larr.push_back(arr[i]);
    }
    for (j = mid + 1; j <= high; j++)
    {
        Rarr.push_back(arr[j]);
    }
    i = 0, j = 0;

    while (i <= mid && j + mid + 1 <= high)
    {
        if (Larr[i] > Rarr[j])
        {
            arr[k] = Rarr[j];
            j++;
        }
        else
        {
            arr[k] = Larr[i];
            i++;
        }
        k++;
    }
    while (i <= mid)
    {
        arr[k] = Larr[i];
        i++;
        k++;
    }
    while (j + mid + 1 <= high)
    {
        arr[k] = Rarr[j];
        j++;
        k++;
    }
}
void mergeSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(low, mid, high, arr);
    }
}
int main()
{
    vector<int> arr;
    int size, temp;
    cout << "enter size: ";
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cin >> temp;
        arr.push_back(temp);
    }
    for (auto &it : arr)
    {
        cout << it << " ";
    }
    mergeSort(arr, 0, size - 1);
    cout << "after sorting";
    for (auto &it : arr)
    {
        cout << it << " ";
    }
    return 0;
}