/*Problem: Write a program to find the maximum and minimum values present in a given array of integers.

Input:
- First line: integer n
- Second line: n integers

Output:
- Print the maximum and minimum elements

Example:
Input:
6
3 5 1 9 2 8

Output:
Max: 9
Min: */

#include <stdio.h>

int main() {
    int n;

    // read size
    scanf("%d", &n);

    int arr[n];

    // read elements
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // assume first element is max and min
    int max = arr[0];
    int min = arr[0];

    // find max and min
    for(int i = 1; i < n; i++) {
        if(arr[i] > max)
            max = arr[i];

        if(arr[i] < min)
            min = arr[i];
    }

    // output
    printf("Max: %d\n", max);
    printf("Min: %d", min);

    return 0;
}
