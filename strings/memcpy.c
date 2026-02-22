#include <stdio.h>
#include <stddef.h>

void *my_memcpy(void *dest, const void *src, size_t n) {
    // Typecast to char pointers for byte-wise copying
    unsigned char *d = (unsigned char *)dest;
    const unsigned char *s = (const unsigned char *)src;

    for (size_t i = 0; i < n; i++) {
        d[i] = s[i];
    }

    return dest;
}

void *my_memmove(void *dest, const void *src, size_t n) {
    unsigned char *d = (unsigned char *)dest;
    const unsigned char *s = (const unsigned char *)src;

    // If destination is before source, copy forward like memcpy
    if (d < s || d >= s + n) {
        for (size_t i = 0; i < n; i++) {
            d[i] = s[i];
        }
    }
    // If destination overlaps with source, copy backward
    else {
        for (size_t i = n; i > 0; i--) {
            d[i - 1] = s[i - 1];
        }
    }

    return dest;
}

int main() {
    char source[] = "Hello, World!";
    // char destination[20];

    // my_memcpy(destination, source, sizeof(source));
    my_memmove(source + 7, source, 6);

    printf("Copied string: %s\n", source);
    return 0;
}
