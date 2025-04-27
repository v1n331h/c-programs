#include <stdio.h>
#define SIZE 10
int table[SIZE];

void initialize(int table[]){
    for(int i=0; i<SIZE; i++){
        table[i]=-1;
    }
}

int hashFunction(int key){
    return key % SIZE;
}

void insert( int key){
    int idx = hashFunction(key);
    int oidx = idx;
        while(table[idx] != -1){
            idx = (idx+1) % SIZE;
            if( idx == oidx){
                printf("Hash Table is full\n");
                return;
            }
        }
        table[idx] = key;
        printf("%d is inserted at index %d\n", key, idx);
    
}


void search( int key){
    int idx = hashFunction(key);
    int oidx = idx;
    while(table[idx] != -1){
        if(table[idx] == key){
            printf("%d is found at index %d\n", key, idx);
        }
        idx = (idx+1)%SIZE;
        if(idx == oidx){
            break;
        }
    }
}


void display(){
    printf("----HASH TABLE----\n\n");
    for(int i=0; i<SIZE; i++){
        if(table[i] != -1){
            printf("Index %d: %d\n", i, table[i]);
        }
        else{
            printf("Index %d: empty\n", i);
        }
    }
    printf("\n");
}

int main() {

initialize(table);

insert(113);
insert(123);
insert(133);
insert(143);
insert(153);


search(113);
search(123);
search(133);
search(143);
search(153);

display();

    return 0;
}