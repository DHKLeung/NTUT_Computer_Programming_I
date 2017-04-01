#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Computer Programming 2016 week 15 hw 2, Coded by Leung Ho Kwan 104360098*/
void inimatrix(int matrix[10][10], int n) { //initialize the matrix with 1 to n * n
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            matrix[i][j] = i * n + j + 1;
        }
    }
}
void printmatrix(int matrix[10][10], int n) {   //print matrix
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
void copymatrix(int destin[10][10], int matrix[10][10], int n) {    //copy matrix
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            destin[i][j] = matrix[i][j];
        }
    }
}
void rightturn(int matrix[10][10], int n) { //perform one right turn
    int destin[10][10], i, j;
    copymatrix(destin, matrix, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            matrix[i][j] = destin[n - 1 - j][i]/**((*destin) + (n - 1 - j) * n + i)*/;
        }
    }
}
void rightturn_times(int matrix[10][10], int firmturn, int n) { //calling several times of rightturn
    int i = 0;
    for (i = 0; i < firmturn; i++) {
        rightturn(matrix, n);
    }
}
void turningsettle(int matrix[10][10], int turn, int n) {   //settle the turning command
    int firmturn;
    if (turn == 0) {    //no need to turn
        return;
    }else if (turn > 0) {   //righ turn
        firmturn = turn % 4;
        rightturn_times(matrix, firmturn, n);
    }else if (turn < 0) {   //left turn
        firmturn = turn % 4;
        firmturn = 4 + firmturn;    //using the right turn to perform the left turn, REMIND : firmturn in this line is negative!!
        rightturn_times(matrix, firmturn, n);
    }
}
void foldingsettle(int matrix[10][10], int n) { //settle the folding command
    int destin[10][10], i, j;
    copymatrix(destin, matrix, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            matrix[i][j] = destin[n - 1 - i][j];
        }
    }
}
void process(int matrix[10][10], char input[], int n) { //process the command
    int i, turn = 0;
    for (i = 0; i < strlen(input); i++) {
        if (input[i] == 'F') {  //comes to 'F'
            if (turn == 0){ //if no turning, break
                break;
            }else { //need to turn, settle it
                turningsettle(matrix, turn, n);
            }
        }else if (input[i] == ' ') {    //space, continue
            continue;
        }else if (input[i] == 'L') {    //left turn, turn - 1
            turn -= 1;
        }else if (input[i] == 'R') {    //right turn, turn + 1
            turn += 1;
        }else if (input[i] == 'N') {    //folding the matrix, settle it, reset turn, fold the matrix
            turningsettle(matrix, turn, n); //settle the turn
            turn = 0;   //reset turn
            foldingsettle(matrix, n);   //fold matrix
        }
    }
}
int main(int argc, char **argv) {
    int n, matrix[10][10];
    char input[101];
    scanf("%d", &n);    //get n
    getchar();  //receive the '\n' from buffer
    inimatrix(matrix, n);   //initialize the matrix
    fgets(input, sizeof(input), stdin); //get the command
    input[strlen(input) - 1] = '\0';    //cancel the received '\n' at the end of string
    process(matrix, input, n);  //process the command on matrix
    printmatrix(matrix, n); //print matrix
    return 0;
}
