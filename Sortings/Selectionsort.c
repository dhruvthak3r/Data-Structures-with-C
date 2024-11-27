#include <stdio.h>
#include <stdlib.h>

void select(int low, int high, int nums[], int n);
int findmin(int low, int high, int nums[], int n);
void swap(int *a, int *b);

int main() {
    int n;
    printf("Enter the length of the array\n");
    scanf("%d", &n);

    int nums[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    select(0, n - 1, nums, n);

    printf("The sorted array is:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\n", nums[i]);
    }

    return 0;
}

void select(int low, int high, int nums[], int n) {
    if (low >= high) return;
    int min = findmin(low, high, nums, n);
    if (nums[low] != nums[min]) {
        swap(&nums[min], &nums[low]);
    }
    select(low + 1, high, nums, n);
}

int findmin(int low, int high, int nums[], int n) {
    int minidx = low;
    for (int i = low + 1; i <= high; i++) {
        if (nums[i] < nums[minidx]) {
            minidx = i;
        }
    }
    return minidx;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
