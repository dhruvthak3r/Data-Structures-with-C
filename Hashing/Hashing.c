#include <stdio.h>
#define max 10
int hashtable[max];
int hash(int key);
void insert(int key);
int get(int key);
void display();

int main() {
    int choice, key;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Retrieve\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(key);
                break;
            case 2:
                printf("Enter key to retrieve: ");
                scanf("%d", &key);
                int value = get(key);
                if (value != -1)
                    printf("Key %d found at index %d\n", key, value);
                else
                    printf("Key %d not found\n", key);
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

int hash(int key) {
    return key % max;
}

void insert(int key) {
    int index = hash(key);
    int i = 0;
    while (hashtable[(index + i) % max] != 0 && i < max) {
        i++;
    }
    if (i < max) {
        index = (index + i) % max;
        hashtable[index] = key;
        printf("Key %d inserted at index %d\n", key, index);
    } else {
        printf("Hash table is full, cannot insert %d\n", key);
    }
}

int get(int key) {
    int index = hash(key);
    int i = 0;
    while (hashtable[(index + i) % max] != key && hashtable[(index + i) % max] != 0 && i < max) {
        i++;
    }
    index = (index + i) % max;
    if (hashtable[index] == key) {
        return index;
    } else {
        return -1;
    }
}

void display() {
    printf("Current state of hash table:\n");
    for (int i = 0; i < max; i++) {
        if (hashtable[i] != -1)
            printf("Index %d: %d\n", i, hashtable[i]);
        else
            printf("Index %d: empty\n", i);
    }
}
