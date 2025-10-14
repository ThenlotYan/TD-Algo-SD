#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "search.h"
#include "utils.h"

int main(void)
{
    int* arr = malloc(1000000 * sizeof(int));
    for (int i = 0; i < 1000000; i++) {
        arr[i] = i + 1;
    }
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 702939;
    bool tri = is_sorted_nondecreasing(arr, n);




    clock_t begin1 = clock();
    int result1 = linear_search(arr, n, target);
    clock_t end1 = clock();
    double time_spent1 = (double)(end1 - begin1) / CLOCKS_PER_SEC;
    if (result1 != -1)
        printf("Linear Search: Element found at index %d\n", result1);
    else
        printf("Linear Search: Element not found\n");
    printf("Time taken by Linear Search: %f seconds\n", time_spent1);


    clock_t begin2 = clock();
    int result2 = jump_search(arr, n, target);
    clock_t end2 = clock();
    double time_spent2 = (double)(end2 - begin2) / CLOCKS_PER_SEC;
    if (result2 != -1 | tri==true)
        printf("Jump Search: Element found at index %d\n", result2);
    else
        printf("Jump Search: Element not found\n");
    printf("Time taken by Jump Search: %f seconds\n", time_spent2);


    clock_t begin3 = clock();
    int result3 = binary_search(arr, n, target);
    clock_t end3 = clock();
    double time_spent3 = (double)(end3 - begin3) / CLOCKS_PER_SEC;
    if (result3 != -1 | tri==true)
        printf("Binary Search: Element found at index %d\n", result3);
    else
        printf("Binary Search: Element not found\n");
    printf("Time taken by Binary Search: %f seconds\n", time_spent3);
    return 0;
}
