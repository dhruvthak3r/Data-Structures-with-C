#include <stdio.h>

void insert(int nums[], int key, int idx);
int parent(int index);
void swap(int *a, int *b);

int main() {
    int n, key;
    printf("Enter the length of the array:\n");
    scanf("%d", &n);
    int nums[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
        insert(nums, key, i);
    }
    printf("The elements of the heap are (level-order):\n");
    for (int i = 0; i < n; i++) {
        printf("%d\n", nums[i]);
    }
    return 0;
}

void insert(int nums[], int key, int idx) {
    nums[idx] = key; // Place the key at the current index
    int p = parent(idx);
    if (idx > 0 && nums[p] < nums[idx]) {
        swap(&nums[p], &nums[idx]); // Swap if the parent is smaller
        insert(nums, nums[p], p);  // Recursively check the parent
    }
}

int parent(int index) {
    return (index - 1) / 2;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
