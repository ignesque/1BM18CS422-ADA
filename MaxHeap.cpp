#include <stdio.h>
#include <limits.h>

bool isHeap(int arr[], int size)
{
    for (int i = 0; i <= (size - 2) / 2; i++)
    {
        if (arr[2 * i + 1] > arr[i])
            return false;
        if (2 * i + 2 < size && arr[2 * i + 2] > arr[i])
            return false;
    }
    return true;
}

int main()
{
    int size;
    printf("Enter size of array:");
    scanf("%d", &size);
    int arr[size];
    printf("Enter array elements:");
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);
    isHeap(arr, size) ? printf("The given arrya is a binary max heap") : printf("The given array is not a binary max heap");
    return 0;
}
