// Написать модуль.
// Входные параметры:
// массив из N-чисел float.
// N = 2..8.
// K - пороговое значение в %, задается пользователем.

// Задание:
// 1.Найти максимальное число.
// 2.Определить отличаются ли оставшиеся числа от максимального больше, чем на K%.
// 3.Оформить код в виде модуля. (*.c, *.h)

// Выходные данные функции:
//  1.Список индексов входного массива чисел, которые не отличаются больше, чем на K% от наибольшего.(включая наибольшое)
//  2.Длина этого списка.
#include "floatfinder.h"
#include <stddef.h>
#include <stdlib.h>
#include <float.h>

floatfinderstruct_t maxfloatfinder(const float *const array, const unsigned int N, const unsigned int K)
{
    floatfinderstruct_t returnstruct;
    returnstruct.indexes_length = 1;
    returnstruct.indexes = NULL;

    //step 1: create new array of structs index-value pair, sort it.
    typedef struct
    {
        unsigned int index;
        float value;
    } pair;

    float border_value = 0;

    pair *p_pairs = (pair *)calloc(sizeof(pair), N);
    for (int i = 0; i < N; ++i)
    {
        (p_pairs[i]).index = i;
        (p_pairs[i]).value = array[i];
    }
    for (int y = 0; y < N; ++y)
    {
        float temp_max = FLT_MIN;
        int temp_index = 0;
        for (int i = y; i < N; ++i)
        {

            if (p_pairs[i].value > temp_max)
            {
                temp_max = p_pairs[i].value;
                temp_index = i;
            }
        }
        pair temp_pair;
        temp_pair.index = p_pairs[y].index;
        temp_pair.value = p_pairs[y].value;
        p_pairs[y].index = p_pairs[temp_index].index;
        p_pairs[y].value = p_pairs[temp_index].value;
        p_pairs[temp_index].index = temp_pair.index;
        p_pairs[temp_index].value = temp_pair.value;

        //step 2: find border value max- max*K
        if (y == 0)
        {
            border_value = p_pairs[0].value - ((p_pairs[0].value / 100) * K);
        }
        else if (p_pairs[y].value >= border_value)
        {
            returnstruct.indexes_length++;
        }
    }

    //step 3: fill return struct with indexes to array and length of this array
    returnstruct.indexes = calloc(sizeof(int), returnstruct.indexes_length);
    for (int i = 0; i < returnstruct.indexes_length; ++i)
    {
        returnstruct.indexes[i] = p_pairs[i].index;
    }
    free(p_pairs);
    return returnstruct;
}
