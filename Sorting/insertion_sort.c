#include <stdio.h>

int arr[] = {6, 3, 9, 10, 2, 1, 5, 7};
int n = 8;
int i, j, swap;

void ins_asc(int arr[], int n)
{
    for (i = 1; i < n; i++)
    {
        j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            swap = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = swap;

            j--;
        }
    }
}

void ins_desc(int arr[], int n)
{
    for (i = 0; i < n; i++)
    {
        j = i;
        while (j > 0 && arr[j - 1] < arr[j])
        {
            swap = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = swap;

            j--;
        }
    }
}

int main()
{
    printf("\nData sebelum disorting: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d, ", arr[i]);
    }

    ins_asc(arr, n);
    printf("\n\nData setelah disorting ascending: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d, ", arr[i]);
    }

    ins_desc(arr, n);
    printf("\n\nData setelah disorting descending: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d, ", arr[i]);
    }

    return 0;
}