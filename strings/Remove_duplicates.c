#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Problem: Remove duplicates from arrays and strings using different methods.

#define MAX_INT_VALUE 100000   // max allowed value for freq-based int dedup

/* ---------- Utility ---------- */

static int compare_ints(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    return (x > y) - (x < y);
}

static void print_int_array(const int *arr, size_t n) {
    for (size_t i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/* ---------- Integer array: frequency array ---------- */
/* Assumes all values are in range [0, MAX_INT_VALUE) */
size_t remove_duplicates_freq(int arr[], size_t n) {
    if (!arr || n == 0) return 0;

    bool *seen = calloc(MAX_INT_VALUE, sizeof *seen);
    if (!seen) return n;

    size_t idx = 0;
    for (size_t i = 0; i < n; i++) {
        if (arr[i] >= 0 && arr[i] < MAX_INT_VALUE && !seen[arr[i]]) {
            seen[arr[i]] = true;
            arr[idx++] = arr[i];
        }
    }

    free(seen);
    return idx;
}

/* ---------- Integer array: sort + dedup ---------- */
void remove_duplicates_sort(int *arr, size_t *n) {
    if (!arr || !n || *n < 2) return;

    qsort(arr, *n, sizeof *arr, compare_ints);
    // sizeof *arr means same as sizeof(arr[0])

    size_t idx = 1;
    for (size_t i = 1; i < *n; i++) {
        if (arr[i] != arr[idx - 1]) {
            arr[idx++] = arr[i];
        }
    }

    *n = idx;
}

/* ---------- String: frequency array ---------- */
char *remove_duplicates_string(char *str) {
    if (!str) return NULL;

    bool seen[256] = { false };

    char *src = str;
    char *dst = str;

    while (*src) {
        unsigned char c = (unsigned char)*src;
        if (!seen[c]) {
            seen[c] = true;
            *dst++ = *src;
        }
        src++;
    }

    *dst = '\0';
    return str;
}

/* ---------- main ---------- */

int main(void) {
    /* Sorting example */
    int arr[] = {1, 9, 3, 10, 4, 20, 2};
    size_t n = sizeof arr / sizeof arr[0];

    qsort(arr, n, sizeof *arr, compare_ints);
    printf("Sorted array: ");
    print_int_array(arr, n);

    /* Sort + dedup example */
    int int_arr[] = {4, 2, 2, 8, 3, 3, 1};
    size_t m = sizeof int_arr / sizeof int_arr[0];

    int *copy = malloc(m * sizeof *copy);
    if (!copy) return 1;

    memcpy(copy, int_arr, m * sizeof *copy);
    remove_duplicates_sort(copy, &m);

    printf("Array after removing duplicates (sort): ");
    print_int_array(copy, m);
    free(copy);

    /* Frequency-array dedup */
    int arr2[] = {4, 2, 2, 8, 3, 3, 1};
    size_t len2 = sizeof arr2 / sizeof arr2[0];

    size_t new_len = remove_duplicates_freq(arr2, len2);
    printf("Array after removing duplicates (freq): ");
    print_int_array(arr2, new_len);

    /* String dedup */
    char str[] = "programming";
    remove_duplicates_string(str);
    printf("String after removing duplicates: %s\n", str);

    return 0;
}
