#include <stdio.h>
/*Computer Programming 2016 week 5 hw 2, Coded by Leung Ho Kwan 104360098*/
int main(void)
{
    int totalround[21] = { 0 };
    int i = 0, j = 0;
    int sum = 0, set = 0, counter = 0;
    while (i < 21) {
        scanf("%d", &totalround[i]);
        i++;
    }
    //process from set1 to set8
    for (i = 0; i < 16; i++) {
        //strike
        if ((totalround[i] == 10) && (i % 2 == 0)) {
            sum += totalround[i];
            for (j = i + 2, counter = 0; j < 19, counter < 2; j++) {
                if ((totalround[j] == 10) && (j % 2 == 0)) {
                    sum += totalround[j];
                    counter++;
                }else if ((totalround[j] == 0) && (totalround[j - 1] == 10) && (j % 2 == 1)) {
                    continue;
                }else {
                    sum += totalround[j];
                    counter++;
                }
            }
        //second round score 0 because of first round strike
        }else if ((totalround[i] == 0) && (totalround[i - 1] == 10) && (i % 2 == 1)) {
            continue;
        //normal first round
        }else if (i % 2 == 0) {
            sum += totalround[i];
            set += totalround[i];
        //second round, check whether it is spare
        }else if (i % 2 == 1) {
            sum += totalround[i];
            set += totalround[i];
            if (set == 10){
                sum += totalround[i + 1];
            }
            set = 0;
        }
    }
    for (i = 16; i < 21; i++) {
        sum += totalround[i];
    }
    if (totalround[16] == 10) {
        sum += (totalround[18] + totalround[19]);   
    }else if ((totalround[16] + totalround[17]) == 10) {
        sum += totalround[18];
    }
    printf("%d\n", sum);
    return 0;
}
