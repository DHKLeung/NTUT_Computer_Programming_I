#include <stdio.h>
/*Computer Programming 2016 week 5 hw 1, Coded by Leung Ho Kwan 104360098*/
int main(void) {
    int num = 0, sum = 0, overlap = 0;
    int x[10], y[10];
    int i = 0, j = 0;
    scanf("%d", &num);
    for (i = 0; i < num; i++) {
        scanf("%d %d", &x[i], &y[i]);
    }
    for (i = 0; i < num; i++ ){
        for (j = i; j < num; j++) {
            if (i == j) {
                continue;
            }else if (y[i] > x[j] && y[i] < y[j] && x[i] < x[j]) {
                overlap += y[i] - x[j];
            }else if (y[j] > x[i] && y[j] < y[i] && x[j] < x[i]) {
                overlap += y[j] - x[i];
            }else if (x[j] <= x[i] && y[j] >= y[i]) {
                x[i] = 0;
                y[i] = 0;
            }else if (x[i] <= x[j] && y[i] >= y[j]) {
                x[j] = 0;
                y[j] = 0;
            }
        }
    }
    for (i = 0; i < num; i++){
        sum += y[i] - x[i];
    }
    sum = sum - overlap;
    printf("%d\n", sum);
    return 0;
}