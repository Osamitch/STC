#include "floatfinder.h"
#include "stdio.h"
#include <stdlib.h>
int main()
{
    floatfinderstruct_t test_struct;
    unsigned int K;
    unsigned int N;

    float array2[] = {3.0, 4.0, 3.58};
    K = 10;
    N = 3;
    test_struct = maxfloatfinder(array2, N, K);
    printf("Test case 1. indexes: [ ");
    for (int i = 0; i < test_struct.indexes_length ;i++)
    {
        printf("%d ", test_struct.indexes[i]);
    }
    printf("], length = %d \n", test_struct.indexes_length);
    free(test_struct.indexes);

    float array3[] = {3.0, 4.0, 4.05};
    K = 10;
    N = 3;
    test_struct = maxfloatfinder(array3, N, K);
    printf("Test case 2. indexes: [ ");
    for (int i = 0; i < test_struct.indexes_length ;i++)
    {
        printf("%d ", test_struct.indexes[i]);
    }
    printf("], length = %d \n", test_struct.indexes_length);
    free(test_struct.indexes);

    float array4[] = {3.5, 3.1, 3.9, 4.0, 4.1};
    K = 10;
    N = 5;
    test_struct = maxfloatfinder(array4, N, K);
    printf("Test case 3. indexes: [ ");
    for (int i = 0; i < test_struct.indexes_length ;i++)
    {
        printf("%d ", test_struct.indexes[i]);
    }
    printf("], length = %d \n", test_struct.indexes_length);
    free(test_struct.indexes);

    float array5[] = {3.5, 3.1, 4.2, 4.5, 4.12, 2.0, 2.7, 3.9, 4.0, 4.1};
    K = 10;
    N = 10;
    test_struct = maxfloatfinder(array5, N, K);
    printf("Test case 4. indexes: [ ");
    for (int i = 0; i < test_struct.indexes_length ;i++)
    {
        printf("%d ", test_struct.indexes[i]);
    }
    printf("], length = %d \n", test_struct.indexes_length);
    free(test_struct.indexes);


    return 0;
}