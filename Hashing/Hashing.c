#include <stdio.h>
#define max 10

int hashtable[max];

int hash(int key);
void insert(int key);
int get(int key);

int main() {
    insert(50);
    insert(700);
    insert(76);
    insert(85);
    insert(92);
    insert(73);
    insert(101);
    printf("Value at key 50: %d\n", get(50));
    printf("Value at key 700: %d\n", get(700));
    printf("Value at key 76: %d\n", get(76));
    printf("Value at key 85: %d\n", get(85));
    printf("Value at key 92: %d\n", get(92));
    printf("Value at key 73: %d\n", get(73));
    printf("Value at key 101: %d\n", get(101));

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
        return hashtable[index];
    } else {
        return -1;
    }
}
