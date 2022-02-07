#include <iostream>
#include <cstdlib>

using namespace std;

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(int a[], int low, int high)
{
    int pivot, index, i;
    index = low;
    pivot = high;

    for (i = low; i < high; i++)
    {
        if (a[i] < a[pivot])
        {
            swap(&a[i], &a[index]);
            index++;
        }
    }
    swap(&a[pivot], &a[index]);

    return index;
}


int QuickSort(int a[], int low, int high)
{
    int pindex;
    if (low < high)
    {
        pindex = Partition(a, low, high);
        QuickSort(a, low, pindex - 1);
        QuickSort(a, pindex + 1, high);
    }
    return 0;
}

int main()
{
    int t;
    cin >> t;
    while (t > 0)
    {
        int n = 0;
        cin >> n;

        int A[n], ct = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        QuickSort(A, 0, n - 1);
        for (int i = 0; i < n; i++)
        {
            cout << A[i] << " ";
        }

        t--;
    }
    return 0;
}