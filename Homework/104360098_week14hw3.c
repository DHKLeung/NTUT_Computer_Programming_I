#include <stdio.h>
#include <stdbool.h>
#define MAX 5
#define DAMN_MAX 4
/*Computer Programming 2016 week 14 hw 3, Coded by Leung Ho Kwan 104360098*/
void push(int stack[], int num, int *counter) {
    stack[*counter] = num;
    *counter = *counter + 1;
}
void demolish(int *counter) {
    *counter = *counter - 1;
}
void printstack(int stack[], int counter) {
    int i;
    for (i = 0; i < counter; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}
void stack_function() {
    int stack[MAX], counter = 0, func, num;
    while (scanf("%d", &func) != EOF) {
        if (func == 2 && counter == 0) {
            printf("EMPTY\n");
            break;
        }else if (func == 1 && counter == MAX) {
            printf("FULL\n");
            break;
        }else {
            switch (func) {
                case 1 :
                    scanf("%d", &num);
                    push(stack, num, &counter);
                    break;
                case 2 :
                    demolish(&counter);
                    break;
                case 3 :
                    printstack(stack, counter);
                    break;
            }
            if (func == 3) {
                break;
            }
        }
    }
}
void enqueue(int cqueue[], int num, int *rear, bool *over) {
    cqueue[*rear] = num;
    *rear = *rear + 1;
    if (*rear == DAMN_MAX) {
        *over = true;
        *rear = 0;
    }
}
void dequeue(int *front, bool *over) {
    *front = *front + 1;
    if (*front == DAMN_MAX) {
        *front = 0;
        *over = false;
    }
}
void printcqueue(int cqueue[], int front, int rear, bool over) {
    int i;
    if (!over) {
        for (i = front; i < rear; i++) {
            printf("%d ", cqueue[i]);
        }
    }else {
        for (i = front; i < DAMN_MAX; i++) {
            printf("%d ", cqueue[i]);
        }
        for (i = 0; i < rear; i++) {
            printf("%d ", cqueue[i]);
        }
    }
    printf("\n");
}
void circular_queue_function() {
    int cqueue[DAMN_MAX], func, front = 0, rear = 0, num;
    bool over = false;
    while (scanf("%d", &func) != EOF) {
        if (func == 2 && front == rear && over == false) {
            printf("EMPTY\n");
            break;
        }else if (func == 1 && front == rear && over == true) {
            printf("FULL\n");
            break;
        }else {
            switch (func) {
                case 1 :
                    scanf("%d", &num);
                    enqueue(cqueue, num, &rear, &over);
                    break;
                case 2 :
                    dequeue(&front, &over);
                    break;
                case 3 :
                    printcqueue(cqueue, front, rear, over);
                    break;
            }
            if (func == 3) {
                break;
            }
        }
    }
}
int main(int argc, char **argv) {
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1 :
            stack_function();
            break;
        case 2 :
            circular_queue_function();
            break;
    }
    return 0;
}
