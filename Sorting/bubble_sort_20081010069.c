#include <stdio.h>

int bubble[] = {22, 10, 15, 3, 8, 2};
int n = 6;
int i, j, tmp;

void bubble_asc()
{

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (bubble[j] > bubble[j + 1])
            {
                tmp = bubble[j];
                bubble[j] = bubble[j + 1];
                bubble[j + 1] = tmp;
            }
        }
    }
}
void bubble_des()
{

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (bubble[j] < bubble[j + 1])
            {
                tmp = bubble[j];
                bubble[j] = bubble[j + 1];
                bubble[j + 1] = tmp;
            }
        }
    }
}

int main()
{
    printf("\nData sebelum sorting: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d, ", bubble[i]);
    }

    bubble_asc();
    printf("\n\nData setelah sorting ascending: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d, ", bubble[i]);
    }

    bubble_des();
    printf("\n\nData setelah sorting descending: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d, ", bubble[i]);
    }

    printf("\n\n");

    return 0;
}