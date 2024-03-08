#include <stdio.h>

//creating element to track swaps
struct Element {
    int value;
    int numSwaps;
};
//making bubble sort
void bubbleSort(struct Element arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j].value > arr[j + 1].value) {
                temp = arr[j].value;
                arr[j].value = arr[j + 1].value;
                arr[j + 1].value = temp;

                arr[j].numSwaps++;
                arr[j + 1].numSwaps++;
            }
        }
    }
}
//making selections sort
void selectionSort(struct Element arr[], int n) {
    int i, j, minIndex, temp;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j].value < arr[minIndex].value) {
                minIndex = j;
            }
        }
        temp = arr[i].value;
        arr[i].numSwaps++;
        arr[minIndex].numSwaps++;

        arr[i].value = arr[minIndex].value;
        arr[minIndex].value = temp;
    }
}
//printing struct 
void printOutput(struct Element arr[], int n) {
    int sumSwaps = 0;


    for (int i = 0; i < n; i++) {
        printf("%d: %d\n", arr[i].value, arr[i].numSwaps);
        sumSwaps += arr[i].numSwaps;
    }

    printf("%d\n\n", sumSwaps / 2);
}

int main() {
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n1 = sizeof(array1) / sizeof(array1[0]);
    int n2 = sizeof(array2) / sizeof(array2[0]);

    struct Element elements1_bubble[n1];
    struct Element elements1_selection[n1];
    struct Element elements2_bubble[n2];
    struct Element elements2_selection[n2];
//initialize arrays
    for (int i = 0; i < n1; i++) {
        elements1_bubble[i].value = array1[i];
        elements1_bubble[i].numSwaps = 0;

        elements1_selection[i].value = array1[i];
        elements1_selection[i].numSwaps = 0;
    }

    for (int i = 0; i < n2; i++) {
        elements2_bubble[i].value = array2[i];
        elements2_bubble[i].numSwaps = 0;

        elements2_selection[i].value = array2[i];
        elements2_selection[i].numSwaps = 0;
    }
//printing output
    bubbleSort(elements1_bubble, n1);
    printf("Bubble Sort for array1:\n");
    printOutput(elements1_bubble, n1);

    bubbleSort(elements2_bubble, n2);
    printf("Bubble Sort for array2:\n");
    printOutput(elements2_bubble, n2);


    selectionSort(elements1_selection, n1);
    printf("Selection Sort for array1:\n");
    printOutput(elements1_selection, n1);


    selectionSort(elements2_selection, n2);
    printf("Selection Sort for array2:\n");
    printOutput(elements2_selection, n2);

    return 0;
}
