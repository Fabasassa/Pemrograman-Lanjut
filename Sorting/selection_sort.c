#include <stdio.h>

int arr[] = {32, 75, 69, 50, 21, 40};
int n = 6;
int i, j, pos, swap;

void sel_asc(int arr[], int n)
{
    for (i = 0; i < n - 1; i++)
    {
        pos = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[pos] > arr[j])
            {
                pos = j;
            }
        }
        if (pos != i)
        {
            swap = arr[i];
            arr[i] = arr[pos];
            arr[pos] = swap;
        }
    }
}

void sel_desc(int arr[], int n)
{
    for (i = 0; i < n - 1; i++)
    {
        pos = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[pos] < arr[j])
            {
                pos = j;
            }
        }
        if (pos != 0)
        {
            swap = arr[i];
            arr[i] = arr[pos];
            arr[pos] = swap;
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

    sel_asc(arr, n);
    printf("\n\nData setelah disorting dengan ascending: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d, ", arr[i]);
    }

    sel_desc(arr, n);
    printf("\n\nData setelah disorting dengan descending: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d, ", arr[i]);
    }
    return 0;
}