#include <stdio.h>
#include <stdlib.h>

typedef struct indice {
    int data;
    int times_swapped;

} indice;

void swap(indice* array, int i, int j) {
    
    indice helper = array[i];
    array[i] = array[j];
    array[j] = helper;

    if (i != j) {
        array[i].times_swapped++;
        array[j].times_swapped++;
    }

    return;
}

int bubble_sort(indice* array, int n) {
    //set unsorted = to "true"
    int i, unsorted = 1;
    int num_swaps = 0;
    //while unsorted is "true"...
    while (unsorted) {
        //set unsorted to false,
        unsorted = 0;
        //enter for loop, which is one iteration through the array
        for (i = 0; i < n - 1; i++)
            //the if statement will set unsorted back to true if we need to 
            //call the swap function
            if (array[i].data > array[i + 1].data) {
                //swap numbers if the current indice is larger than the next
                swap(array, i, i + 1);
                //set unsorted back to true, since we had to
                //call swap in order to perform sorting
                unsorted = 1;
                //increment the total number of swaps in the program
                num_swaps++;
            }
    }
    //return the total number of swaps performed by bubble sort
    return num_swaps;
}

int selection_sort(indice* array, int n) {
    int i; 
    int cur_loop = 0;
    int num_swaps = 0;

    //current loop is how we will lock in our smallest sorted element
    //so while current loop is less than (1 less than the length) (because
    //we dont need to sort an unsorted array of length 1)...
    while (cur_loop < (n-1)) {

        //x will hold our current smallest value, which is the leftmost
        //unlocked element
        int x = array[cur_loop].data;
        //smallest will hold the indice of the current smallest value, which is the leftmost
        //unlocked element
        int smallest = cur_loop;

        //we start iterating on the leftmost unlocked element of the CURRENT LOOP
        //which starts at 0 and grows by one through each iteration
        //it will loop through the entire array of length n
        for (i = cur_loop; i < n; i++) {
            //if our leftmost value is larger than the current element we inspect...
            if (x > array[i].data) {
                //our current smallest value is updated
                x = array[i].data;
                //and it's indice is recorded
                smallest = i;
            }
        }

        //once we find the current smalled unlocked value, we swap it with the current leftmost
        //unlocked element
        swap(array, cur_loop, smallest);
        //increment the number of swaps if the smallest element is different from the leftmost element
        if (cur_loop != smallest) {
            num_swaps++;
        }
        //current loop is updated, which is the "element locking" mechanism, as the 
        //current loop is where the for loop will start each time
        cur_loop++;

    }
    //return the number of swaps
    return num_swaps;
}

void initialize_indice_array(int* input, indice* array, int n) {
    
    for (int i = 0; i < n; i++) {
        array[i].data = input[i];
    }

    return;
}

void empty_swaps_from_indice_array(indice* array, int n) {

    for (int i = 0; i < n; i++) {
        array[i].times_swapped = 0;
    }

}

void print_indice_swaps(indice* array, int n) {
    
    for (int i = 0; i < n; i++) {
        printf("%d: # of times %d is swapped\n", array[i].times_swapped, array[i].data);
    }
}

int main(void) {

    int input_1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int n_1 = 9;

    int input_2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n_2 = 9;

    int bubble_swaps_1;
    int bubble_swaps_2;
    int select_swaps_1;
    int select_swaps_2;

    indice* array_1 = calloc(n_1, sizeof(indice));

    indice* array_2 = calloc(n_2, sizeof(indice));

    initialize_indice_array(input_1, array_1, n_1);

    initialize_indice_array(input_2, array_2, n_2);

    bubble_swaps_1 = bubble_sort(array_1, n_1);
    bubble_swaps_2 = bubble_sort(array_2, n_2);

    printf("Bubble Sort swaps on Array 1: \n");
    print_indice_swaps(array_1, n_1);
    printf("%d is the total swaps on array 1\n", bubble_swaps_1);

    printf("\n");

    printf("Bubble Sort swaps on Array 2: \n");
    print_indice_swaps(array_2, n_2);
    printf("%d is the total swaps on array 2\n", bubble_swaps_2);

    printf("\n");

    empty_swaps_from_indice_array(array_1, n_1);
    empty_swaps_from_indice_array(array_2, n_2);

    initialize_indice_array(input_1, array_1, n_1);
    initialize_indice_array(input_2, array_2, n_2);

    select_swaps_1 = selection_sort(array_1, n_1);
    select_swaps_2 = selection_sort(array_2, n_2);

    printf("Selection Sort swaps on Array 1: \n");
    print_indice_swaps(array_1, n_1);
    printf("%d is the total swaps on array 1\n", select_swaps_1);

    printf("\n");

    printf("Selection Sort swaps on Array 2: \n");
    print_indice_swaps(array_2, n_2);
    printf("%d is the total swaps on array 2\n", select_swaps_2);

    return 0;
}