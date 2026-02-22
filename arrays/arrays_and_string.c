#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

/* Problem: Check if two strings are anagrams (case-insensitive, letters only) */
bool is_anagram(char *str1, char* str2)
{
    int freq[256] = {0};

    // Count letters in str1
    for (; *str1; str1++)
    {
        char ch = *str1;
        if (ch >= 'A' && ch <= 'Z') ch += 32;
        if (ch >= 'a' && ch <= 'z') freq[(unsigned char)ch]++;
    }

    // Subtract letters in str2
    for (; *str2; str2++)
    {
        char ch = *str2;
        if (ch >= 'A' && ch <= 'Z') ch += 32;
        if (ch >= 'a' && ch <= 'z') freq[(unsigned char)ch]--;
    }

    // Check if all counts are zero
    for(int i = 0; i< 256; i++)
        if(freq[i] != 0) return false;

    return true;
}

/* Problem: Check if a string is a palindrome */
bool is_palindrome(char* str)
{
    int n = strlen(str);
    int s = 0;
    int e = n - 1;

    while(s < e)
    {
        if(tolower(str[s]) != tolower(str[e]))
            return false;
        s++;
        e--;
    }
    return true;
}

/* Problem: Find the first duplicate element in an array */
int find_duplicate_element_in_array(int arr[], int n)
{
    int freq[n];
    for(int i = 0; i<n; i++) freq[i] = 0;

    for(int i = 0; i< n; i++)
    {
        if(freq[arr[i]] == 0) freq[arr[i]] = 1;
        else return arr[i];
    }
    return -1;
}

/* Problem: Find the second first element in an array */
int find_second(int arr[], int n)
{
    int first = -1;
    int second = -1;

    for(int i = 0; i< n; i++)
    {
        if(arr[i] > first)
        {
            second = first;
            first = arr[i];
        }
        else if(arr[i] > second && arr[i] < first)
        {
            second = arr[i];
        }
    }
    return second;
}

/* Problem: Reverse a string in place using XOR swap */
void reverse_string(char* str)
{
    int s = 0;
    int e = strlen(str) - 1;
    while(s < e)
    {
        str[s] = str[s] ^ str[e];
        str[e] = str[s] ^ str[e];
        str[s] = str[s] ^ str[e];
        s++;
        e--;
    }
    printf("Reverse = %s\n", str);
}

char* my_strrev(char* str)
{
    char *start = str;
    char *end = str + strlen(str) - 1;
    while (start < end) {
        char temp = *start;
        *start++ = *end;
        *end-- = temp;
    }
    return str;
}

/* Problem: Check if a string has more vowels than consonants and sum of digits */
void good_string(char *str)
{
    int vowels = 0, consonants = 0, sum = 0;
    for(; *str; str++)
    {
        char ch = *str;
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        {
            if(ch >= 'A' && ch <= 'Z')
                ch += 32;
            if(ch == 'a' || ch == 'e' || ch =='i' || ch == 'o' || ch == 'u')
                vowels++;
            else
                consonants++;
        }
        else if(ch >= '0' && ch <= '9')
        {
            sum += ch - '0';
        }
    }
    printf("Good String? %s\nSum = %d\n", (vowels > consonants ? "TRUE" : "FALSE"), sum);
}

/* Problem: Count vowels in a string */
void count_vowels_and_num(char* str)
{
    int vowels = 0;
    for(; *str; str++)
    {
        char ch  = *str;
        if(ch >= 'A' && ch<= 'Z') ch += 32;
        if(ch >= 'a' && ch<='z')
        {
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                vowels++;
        }
    }
    printf("Vowels: %d\n", vowels);
}

/* Problem: Reverse a sentence */
void rev_sentence(char* str) {
    char *words[100];
    int count = 0;
    
    // Tokenize the string into words
    char *token = strtok(str, " ");
    while(token != NULL) {
        words[count++] = token;
        token = strtok(NULL, " ");
    }
    
    // Print words in reverse order
    for(int i = count - 1; i >= 0; i--) {
        printf("%s", words[i]);
        if (i > 0) {
            printf(" ");  // Add space between words, but not after the last word
        }
    }
    printf("\n");
}

int main()
{
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    // Count vowels
    count_vowels_and_num(str);

    // Check vowels vs consonants and sum digits
    good_string(str);

    // Reverse string
    char* str1 = (char*) malloc(100 * sizeof(char));
    printf("Enter a string to reverse: ");
    scanf("%s", str1);
    reverse_string(str1);
    free(str1);

    // Test anagram
    char str2[100], str3[100];
    printf("Enter first string for anagram check: ");
    scanf("%s", str2);
    printf("Enter second string for anagram check: ");
    scanf("%s", str3);
    printf("Anagram? %s\n", is_anagram(str2, str3) ? "TRUE" : "FALSE");

    // Test palindrome
    printf("Enter string to check palindrome: ");
    scanf("%s", str2);
    printf("Palindrome? %s\n", is_palindrome(str2) ? "TRUE" : "FALSE");

    // Array operations
    int arr[] = {12, 35, 1, 10, 34, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    int second = find_second(arr, n);
    if (second != -1) {
        printf("The second first element is: %d\n", second);
    } else {
        printf("No second first element found.\n");
    }

    int duplicate = find_duplicate_element_in_array(arr, n);
    if (duplicate != -1) {
        printf("First duplicate element is: %d\n", duplicate);
    } else {
        printf("No duplicate element found.\n");
    }

    return 0;
}
