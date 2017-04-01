#include <stdio.h>
/*Computer Programming 2016 week 14 hw 2, Coded by Leung Ho Kwan 104360098*/
void inputlist(int list[], int *method, int *elementcounter) {
    int input;
    while (scanf("%d", &input) && input != -999) {
        list[*elementcounter] = input;
        *elementcounter = *elementcounter + 1;
    }
    scanf("%d", method);
}
void array_copy(int process[], int list[], int elementcounter) {
    int i;
    for (i = 0; i < elementcounter; i++) {
        process[i] = list[i];
    }
}
void print_array(int array[], int elementcounter) {
    int i;
    for (i = 0; i < elementcounter; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
void bubblesort(int list[], int *bscounter, int elementcounter, int method) {
    int process[20] = { 0 }, i, j, temp;
    array_copy(process, list, elementcounter);
    if (method == 0) {
        for (i = 0; i < elementcounter; i++) {
            for (j = 0; j < elementcounter - i - 1; j++) {
                if (process[j] > process[j + 1]) {
                    *bscounter = *bscounter + 1;
                    temp = process[j];
                    process[j] = process[j + 1];
                    process[j + 1] = temp;
                }
            }
        }
    }else if (method == 1) {
        for (i = 0; i < elementcounter; i++) {
            for (j = 0; j < elementcounter - i; j++) {
                if (process[j] < process[j + 1]) {
                    *bscounter = *bscounter + 1;
                    temp = process[j];
                    process[j] = process[j + 1];
                    process[j + 1] = temp;
                }
            }
        }
    }
    print_array(process, elementcounter);
}
void insertionsort(int list[], int *iscounter, int elementcounter, int method) {
    int process[20], i, j, temp;
    array_copy(process, list, elementcounter);
    if (method == 0) {
        for (i = 1; i < elementcounter; i++) {
            temp = process[i];
            j = i - 1;
            for (; j >= 0 && process[j] > temp; j--) {
                *iscounter = *iscounter + 1;
                process[j + 1] = process[j];
            }
            process[j + 1] = temp;
        }
    }else if (method == 1) {
        for (i = 1; i < elementcounter; i++) {
            temp = process[i];
            j = i - 1;
            for (; j >= 0 && process[j] < temp; j--) {
                *iscounter = *iscounter + 1;
                process[j + 1] = process[j];
            }
            process[j + 1] = temp;
        }
    }
}
void selectionsort(int list[], int *sscounter, int elementcounter, int method) {
    int process[20], i, j, k, temp;
    array_copy(process, list, elementcounter);
    if (method == 0) {
        for (i = 0; i < elementcounter - 1; i++) {
            k = i;
            for (j = i + 1; j < elementcounter; j++) {
                if (process[j] < process[k]) {
                    k = j;
                }
            }
            if (process[k] < process[i]) {
                *sscounter = *sscounter + 1;
                temp = process[k];
                process[k] = process[i];
                process[i] = temp;
            }
        }
    }else if (method == 1) {
        for (i = 0; i < elementcounter - 1; i++) {
            k = i;
            for (j = i + 1; j < elementcounter; j++) {
                if (process[j] > process[k]) {
                    k = j;
                }
            }
            if (process[k] > process[i]) {
                *sscounter = *sscounter + 1;
                temp = process[k];
                process[k] = process[i];
                process[i] = temp;
            }
        }
    }
}
int main(int argc, char **argv) {
    int list[20] = { 0 }, method, bscounter = 0, iscounter = 0, sscounter = 0, elementcounter = 0;
    inputlist(list, &method, &elementcounter);
    bubblesort(list, &bscounter, elementcounter, method);
    insertionsort(list, &iscounter, elementcounter, method);
    selectionsort(list, &sscounter, elementcounter, method);
    printf("Bubble Sort change times = %d\n", bscounter);
    printf("Insertion Sort change times = %d\n", iscounter);
    printf("Selection Sort change times = %d\n", sscounter);
    return 0;
}
