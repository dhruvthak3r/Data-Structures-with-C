#include <stdio.h>
void quicksort(int low, int high, int nums[]);
int partition(int low, int high, int nums[]);
void swap(int *a, int *b);
int main() {
    int n;
    printf("Enter the length of the array: ");
    scanf("%d", &n);
    int nums[n]; 
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    quicksort(0, n - 1, nums);
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\n", nums[i]);
    }
    return 0;
}
void quicksort(int low,int high,int nums[]){
    if(low < high){
        int part = partition(low,high,nums);
        quicksort(low,part-1,nums);
        quicksort(part+1,high,nums);
    }
}
int partition(int low,int high,int nums[]){
    int pivot = nums[low];
    int prevlow = low;
    low++;
    while(low <=high){
        while(low <=high && nums[low] <= pivot){
        low++;
        }
        while(low <= high && nums[high] >= pivot){
        high--;
        }
        if(low < high){
        swap(&nums[low],&nums[high]);
        }
   }
   swap(&nums[prevlow],&nums[high]);
   return high;
}
void swap(int *a ,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
