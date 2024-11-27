#include <stdio.h>
#include <stdlib.h>

#define max 100

void mergesort(int low, int high, int nums[]);
void merge(int nums[], int low, int mid, int high);
void copy(int temp[], int nums[], int low, int high);

int temp[max];

int main() {
    int n;
    printf("Enter the length of the array\n");
    scanf("%d", &n);
    int nums[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    mergesort(0, n - 1, nums);
    printf("The sorted array is:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\n", nums[i]); 
    }
    return 0;
}

void mergesort(int low, int high, int nums[]) {
    if (low == high) return;
    int mid = (low + high) / 2;
    mergesort(low, mid, nums);
    mergesort(mid + 1, high, nums);
    merge(nums, low, mid, high);
}

void merge(int nums[], int low, int mid, int high) {
    int left = low;
    int right = mid + 1;
    int idx = low;
    while (left <= mid && right <= high) {
        if (nums[left] <= nums[right]) {
            temp[idx++] = nums[left++];
        } else {
            temp[idx++] = nums[right++];
        }
    }
    while (left <= mid) {
        temp[idx++] = nums[left++];
    }
    while (right <= high) {
        temp[idx++] = nums[right++];
    }
    copy(temp, nums, low, high);
}

void copy(int temp[], int nums[], int low, int high) {
    for (int i = low; i <= high; i++) {  
        nums[i] = temp[i];
    }
}
