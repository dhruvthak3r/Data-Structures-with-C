#include <stdio.h>

#define max 100
int temp[max];

void insert_sort(int nums[], int low, int high);
void copy(int nums[], int high);

int main() {
    int n;
    printf("Enter the length of the array:\n");
    scanf("%d", &n);
    int nums[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        insert_sort(nums, 0, i + 1);
    }

    printf("The sorted elements are:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\n", nums[i]);
    }

    return 0;
}

void insert_sort(int nums[], int low, int high) {
    int idx = 0;
    while (nums[high] > nums[low]) {
        temp[idx++] = nums[low++];
    }
    temp[idx++] = nums[high];
    while (low < high) {
        temp[idx++] = nums[low++];
    }
    copy(nums, high + 1);
}

void copy(int nums[], int high) {
    for (int i = 0; i < high; i++) {
        nums[i] = temp[i];
    }
}
