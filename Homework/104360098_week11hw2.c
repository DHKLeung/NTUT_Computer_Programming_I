#include <stdio.h>
#include <stdbool.h>
/*Computer Programming 2016 week 11 hw 2, Coded by Leung Ho Kwan 104360098*/
bool check_contin(int data[]) {
    int i, j, temp[10];
    bool cont = true;
    for (i = 0; i < 5; i++) {
        *(temp + i) = *(data + i);
    }
    for (i = 5; i < 10; i++) {
        *(temp + i) = *(data + i - 5) + 13;
    }
    for (j = 0; j < 6; j++) {
        for (i = 1; i < 5; i++) {
            if (*(temp + j) != *(temp + j + i) - i) {
                cont = false;
            }
        }
        if (cont == true) {
            return true;
        }else {
            cont = true;
        }
    }
    return false;
}
bool check_foak(int data[]) {
    int counter = 0, i, j;
    for (j = 0; j < 5; j++) {
        for (i = 0; i < 5; i++) {
            if (*(data + j) == *(data + i)) {
                counter++;
            }
        }
        if (counter == 4) {
            return true;
        }else {
            counter = 0;
        }
    }
    return false;
}
bool check_samesign(int sign[]) {
    int i;
    for (i = 0; i < 4; i++) {
        if (*(sign + i) != *(sign + i + 1)) {
            return false;
        }
    }
    return true;
}
bool check_fullhouse(int data[]) {
    bool triexist = false;
    int i, j, counter = 0, trinumber;
    for (j = 0; j < 5; j++) {
        for (i = 0; i < 5; i++) {
            if (*(data + j) == *(data + i)) {
                counter++;
            }
        }
        if (counter == 3) {
            triexist = true;
            trinumber = *(data + j);
            break;
        }else {
            counter = 0;
        }
    }
    counter = 0;
    if (triexist == true) {
        for (j = 0; j < 5; j++) {
            for (i = 0; i < 5; i++) {
                if (*(data + j) != trinumber && *(data + i) != trinumber && *(data + j) == *(data + i)) {
                    counter++;
                }
            }
            if (counter == 2) {
                return true;
            }else {
                counter = 0;
            }
        }
    }
    return false;
}
bool check_toak(int data[]) {
    int i, j, counter = 0;
    for (j = 0; j < 5; j++) {
        for (i = 0; i < 5; i++) {
            if (*(data + j) == *(data + i)) {
                counter++;
            }
        }
        if (counter == 3) {
            return true;
        }else {
            counter = 0;
        }
    }
    return false;
}
bool check_twopair(int data[]) {
    int i, j, counter = 0, num;
    bool exist = false;
    for (j = 0; j < 5; j++) {
        for (i = 0; i < 5; i++) {
            if (*(data + j) == *(data + i)) {
                counter++;
            }
        }
        if (counter == 2) {
            exist = true;
            num = *(data + j);
            break;
        }else {
            counter = 0;
        }
    }
    counter = 0;
    if (exist == true) {
        for (j = 0; j < 5; j++) {
            for (i = 0; i < 5; i++) {
                if (*(data + j) != num && *(data + i) != num && *(data + j) == *(data + i)) {
                    counter++;
                }
            }
            if (counter == 2) {
                return true;
            }else {
                counter = 0;
            }
        }
    }
    return false;
}
bool check_pair(int data[]) {
    int i, j, counter;
    for (j = 0; j < 5; j++) {
        for (i = 0; i < 5; i++) {
            if (*(data + j) == *(data + i)) {
                counter++;
            }
        }
        if (counter == 2) {
            return true;
        }else {
            counter = 0;
        }
    }
    return false;
}
void judge(int data[], int *r) {
    int i, j, sign[5], counter = 0;
    for (i = 0; i < 5; i++) {   //seperate sign and data
        *(sign + i) = *(data + i) - (*(data + i) / 10) * 10;
        *(data + i) = *(data + i) / 10;
    }
    if (check_contin(data) == true) {
        if (check_samesign(sign) == true) {
            *r = 7;
        }else {
            *r = 6;
        }
        return;
    }else if (check_foak(data) == true) {
        *r = 5;
    }else if (check_fullhouse(data) == true) {
        *r = 4;
    }else if (check_toak(data) == true) {
        *r = 3;
    }else if (check_twopair(data) == true) {
        *r = 2;
    }else if (check_pair(data) == true) {
        *r = 1;
    }else {
        *r = 0;
    }
}
int main(void) {
    int input[5], i, j, temp, r;
    for (i = 0; i < 5; i++) {   //input
        scanf("%d", input + i);
    }
    for (i = 0; i < 5; i++) {   //sort
        for (j = 0; j < 5 - i; j++) {
            if (*(input + j) > *(input + j + 1)) {
                temp = *(input + j);
                *(input + j) = *(input + j + 1);
                *(input + j + 1) = temp;
            }
        }
    }
    judge(input, &r);
    printf("%d\n", r);
    return 0;
}
