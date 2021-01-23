typedef struct
{
    unsigned int *indexes;
    unsigned int indexes_length;
} floatfinderstruct_t;
// floatfinderstruct_t.indexes is dynamically allocated array, must be freed after use;
floatfinderstruct_t maxfloatfinder(const float * const array, const unsigned int N, const unsigned int K);