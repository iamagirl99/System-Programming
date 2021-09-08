#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int compare(int a, int b){
    if(a>b)
        return 1;
    else
           return -1;
}

void bubble_sort(int array[], int n){
    int temp;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - 1 - i; j++){
            if(compare(array[j], array[j + 1]) == 1){
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}


int main(){
    int n_array[SIZE] = {2,-9, 10, 15, 1, 3, -12, 5, 4, 1};
    bubble_sort(n_array, SIZE);
    for(int i = 0; i < SIZE; i++){
        printf("%d\t", n_array[i]);
    }
    return 0;
}

