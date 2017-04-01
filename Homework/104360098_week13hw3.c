#include <stdio.h>
#include <string.h>
#include <stdbool.h>
/*Computer Programming 2016 week 13 hw 3, Coded by Leung Ho Kwan 104360098*/
bool validation(char *input, int *leftpos) {
    int i, leftcounter = 0, rightcounter = 0;
    for (i = 0; i < strlen(input); i++) {
        if (input[i] == '(') {
            leftcounter++;
            *leftpos = i;
        }else if (input[i] == ')') {
            rightcounter++;
        }
    }
    if (leftcounter == rightcounter) {
        return true;
    }else {
        return false;
    }
}
void print_inner(char *input, int leftpos) {
    int i;
    for (i = leftpos + 1; i < strlen(input); i++) {
        if (input[i] == ')') {
            break;
        }else {
            printf("%c", input[i]);
        }
    }
    printf("\n");
}
int arith(int sum, int adder, char sign) {
    if (sign == '+') {
        return sum + adder;
    }else if (sign == '-') {
        return sum - adder;
    }else if (sign == '*') {
        return sum * adder;
    }
}
int compute_inner(char *input, int leftpos) {
    int i = 0, sum = 0, adder = 0;
    char sign;
    bool insign = false;
    for (i = leftpos + 1; i < strlen(input); i++) {
        if (input[i] <= '9' && input[i] >= '0') {
            sum *= 10;
            sum += input[i] - 48;
        }else {
            break;
        }
    }
    for (; i < strlen(input); i++) {
        if (!(input[i] >= '0' && input[i] <= '9') && input[i] != ')' && insign == false) {
            insign = true;
            sign = input[i];
        }else if ((input[i] >= '0' && input[i] <= '9') && insign == true) {
            adder *= 10;
            adder = input[i] - 48;
        }else if (!(input[i] >= '0' && input[i] <= '9') && input[i] != ')' && insign == true) {
            sum = arith(sum, adder, sign);
            adder = 0;
            adder += input[i] - 48;
        }else if (input[i] == ')' && insign == true) {
            sum = arith(sum, adder, sign);
            break;
        }
    }
    return sum;
}
int main(int argc, char **argv) {
    char input[101];
    int leftpos = 0;
    bool valid = false;
    fgets(input, sizeof(input), stdin);
    input[strlen(input) - 1] = '\0';
    valid = validation(input, &leftpos);
    if (!valid) {
        printf("ERROR INPUT\n");
    }else {
        print_inner(input, leftpos);
        printf("%d\n", compute_inner(input, leftpos));
    }
    return 0;
}
