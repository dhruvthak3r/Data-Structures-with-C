#include <stdio.h>

void build_heap(int nums[], int key, int idx);
int parent(int index);
void swap(int *a, int *b);
void heapsort(int nums[], int n);
void heapify(int nums[], int start, int end);
int left(int index);
int right(int index);

int main() {
    int n, key;
    printf("Enter the length of the array:\n");
    scanf("%d", &n);
    int nums[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
        build_heap(nums, key, i);
    }

    heapsort(nums, n);

    printf("The sorted elements are:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\n", nums[i]);
    }

    return 0;
}

void build_heap(int nums[], int key, int idx) {
    nums[idx] = key;
    int p = parent(idx);
    if (idx > 0 && nums[p] < nums[idx]) {
        swap(&nums[p], &nums[idx]);
        build_heap(nums, nums[p], p);
    }
}

void heapsort(int nums[], int n) {
    for (int end = n - 1; end > 0; end--) {
        swap(&nums[0], &nums[end]);
        heapify(nums, 0, end);
    }
}

void heapify(int nums[], int start, int end) {
    int left_child = left(start);
    int right_child = right(start);
    int max = start;

    if (left_child < end && nums[left_child] > nums[max]) {
        max = left_child;
    }
    if (right_child < end && nums[right_child] > nums[max]) {
        max = right_child;
    }

    if (max != start) {
        swap(&nums[max], &nums[start]);
        heapify(nums, max, end);
    }
}

int left(int index) {
    return (2 * index) + 1;
}

int right(int index) {
    return (2 * index) + 2;
}

int parent(int index) {
    return (index - 1) / 2;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
