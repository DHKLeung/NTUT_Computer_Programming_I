#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
/*Computer Programming 2016 week 14 hw 1, Coded by Leung Ho Kwan 104360098*/
typedef struct _triangle triangle;
struct _triangle {
    int pt[3][2];
};
void input_data(triangle *data, int amount) {   //input data
    int i, j, k;
    for (i = 0; i < amount; i++) {  //each triangle's
        for (j = 0; j < 3; j++) {   //each pair of coordinate
            for (k = 0; k < 2; k++) {   //each coordinate's x and y
                scanf("%d", &((data + i)->pt[j][k]));
            }
        }
    }
}
void compute_equation(int x1, int y1, int x2, int y2, double *m, double *c) {   //compute the slope and y-intercept using two coordinate
    *m = ((y1 - y2) * 1.0) / ((x1 - x2) * 1.0); //slope
    if (isinf(*m)) {    //if slope do not exist
        *c = x1 * 1.0;    //set c as x as a sign of slope not exist
    }else {
        *c = y1 - *m * x1;  //as usual y-intercept
    }
}
void compute_intersection(double m1, double m2, double c1, double c2, double *y, double *x) {   //compute the intersection point of two lines
    if (isinf(m1)) {    //if line 1 is vertical, compute the intersection using the x
        *x = c1;
        *y = m2 * *x + c2;
    }else if (isinf(m2)) {  //if line 2 is vertical, compute the intersection using the x
        *x = c2;
        *y = m1 * *x + c1;
    }else { //both two lines are not vertical, compute the intersection point
        *x = (c2 - c1) / (m1 - m2);
        *y = m1 * *x + c1;
    }
}
double max_double(double a, double b) { //return the max
    if (a > b) {
        return a;
    }else {
        return b;
    }
}
double min_double(double a, double b) { //return the min
    if (a < b) {
        return a;
    }else {
        return b;
    }
}
int absmin_int(int a, int b) {  //return the absoluted min integer
    if (abs(a) < abs(b)) {
        return abs(a);
    }else {
        return abs(b);
    }
}
bool isinrange(int x11, int y11, int x12, int y12, int x21, int y21, int x22, int y22, double x, double y) {   //check whether it is in range
    if (x <= max_double(x11, x12) && x >= min_double(x11, x12) && x <= max_double(x21, x22) && x >= min_double(x21, x22)) {
        if (y <= max_double(y11, y12) && y >= min_double(y11, y12) && y <= max_double(y21, y22) && y >= min_double(y21, y22)) {
            return true;
        }else {
            return false;
        }
    }else {
        return false;
    }
}
bool isnotoverlap(double interx[], double intery[], int intersect_counter, double x, double y) {    //check overlap
    int i, newx, newy, newinterx, newintery;
    newx = (int)(x * 1000);
    newy = (int)(y * 1000);
    for (i = 0; i < intersect_counter; i++) {
        newinterx = (int)(interx[i] * 1000);
        newintery = (int)(intery[i] * 1000);
        if (newx == newinterx && newy == newintery) {
            return false;
        }
    }
    return true;
}
void sortintersection(double interx[], double intery[], double intersect_counter) { //sort the intersection
    int i, j;
    double temp;
    for (i = 0; i < intersect_counter; i++) {   //bouble sort from small to big
        for (j = 0; j < intersect_counter - i - 1; j++) {
            if (interx[j] > interx[j + 1]) {    //judge x-coordinate, swap
                temp = interx[j];
                interx[j] = interx[j + 1];
                interx[j + 1] = temp;
                temp = intery[j];
                intery[j] = intery[j + 1];
                intery[j + 1] = temp;
            }else if (fabs(interx[j] - interx[j + 1]) < 0.000000001) { //x-coordinate are the same, judge y-coordinate, swap
                if (intery[j] > intery[j + 1]) {
                    temp = interx[j];
                    interx[j] = interx[j + 1];
                    interx[j + 1] = temp;
                    temp = intery[j];
                    intery[j] = intery[j + 1];
                    intery[j + 1] = temp;
                }
            }
        }
    }
}
int gethcfvalid(int son, int mom) { //return hcf, return -1 means trouble occurs
    int i;
    i = absmin_int(son, mom);
    while (i > 0) {
        if (son % i == 0 && mom % i == 0) {
            return i;
        }
        i--;
    }
    return -1;
}
void fractionize(double interx[], double intery[], int intersect_counter, int xson[], int xmom[], int yson[], int ymom[]) {
    int i, hcf;
    for (i = 0; i < intersect_counter; i++) {
        xson[i] = round(interx[i] * 1000000);    //extract the interx and intery into fraction, cut the double for 5 decimal point
        xmom[i] = 1000000;
        yson[i] = round(intery[i] * 1000000);
        ymom[i] = 1000000;
        hcf = gethcfvalid(xson[i], xmom[i]);    //get the hcf from xson and xmom
        if (hcf != -1) {    //simplify the xson and xmom
            xson[i] /= hcf;
            xmom[i] /= hcf;
        }
        hcf = gethcfvalid(yson[i], ymom[i]);    //get the hcf from yson and ymom
        if (hcf != -1) {    //simplify the yson and ymom
            yson[i] /= hcf;
            ymom[i] /= hcf;
        }
    }
}
void printintersection_fraction(int xson[], int xmom[], int yson[], int ymom[], int intersect_counter) {    //print fraction
    int i;
    for (i = 0; i < intersect_counter; i++) {
        printf("(");
        if (xmom[i] == 1) { //xmom = 1, then print the xson only
            printf("%d,", xson[i]);
        }else if (xson[i] == 0) {   //the value of xson/xmom is 0, print the xson of 0 only
            printf("%d,", xson[i]);
        }else { //print fraction
            printf("%d/%d,", xson[i], xmom[i]);
        }
        if (ymom[i] == 1) { //ymom = 1, then print the yson only
            printf("%d", yson[i]);
        }else if (yson[i] == 0) {   //the value of yson/ymom is 0, print the yson of 0 only
            printf("%d", yson[i]);
        }else { //print fraction
            printf("%d/%d", yson[i], ymom[i]);
        }
        printf(")\n");
    }
}
int main(int argc, char **argv) {
    int amount, i, j, intersect_counter = 0, xson[50], xmom[50], yson[50], ymom[50];
    double m_cur, c_cur, m_com, c_com, y, x, interx[50], intery[50];
    triangle *data;
    scanf("%d", &amount); //input amount of triangle
    data = (triangle*)malloc(sizeof(triangle) * amount);  //allocate space for data
    input_data(data, amount); //input triangle data
    for (i = 0; i < amount - 1; i++) {
        for (j = i + 1; j < amount; j++) {
            compute_equation(data[i].pt[0][0], data[i].pt[0][1], data[i].pt[1][0], data[i].pt[1][1], &m_cur, &c_cur);
            compute_equation(data[j].pt[0][0], data[j].pt[0][1], data[j].pt[1][0], data[j].pt[1][1], &m_com, &c_com);
            compute_intersection(m_cur, m_com, c_cur, c_com, &y, &x);
            if (isinrange(data[i].pt[0][0], data[i].pt[0][1], data[i].pt[1][0], data[i].pt[1][1], data[j].pt[0][0], data[j].pt[0][1], data[j].pt[1][0], data[j].pt[1][1], x, y)) {
                if (isnotoverlap(interx, intery, intersect_counter, x, y)) {
                    interx[intersect_counter] = x;
                    intery[intersect_counter] = y;
                    intersect_counter++;
                }
            }
            compute_equation(data[i].pt[0][0], data[i].pt[0][1], data[i].pt[2][0], data[i].pt[2][1], &m_cur, &c_cur);
            compute_equation(data[j].pt[0][0], data[j].pt[0][1], data[j].pt[1][0], data[j].pt[1][1], &m_com, &c_com);
            compute_intersection(m_cur, m_com, c_cur, c_com, &y, &x);
            if (isinrange(data[i].pt[0][0], data[i].pt[0][1], data[i].pt[2][0], data[i].pt[2][1], data[j].pt[0][0], data[j].pt[0][1], data[j].pt[1][0], data[j].pt[1][1], x, y)) {
                if (isnotoverlap(interx, intery, intersect_counter, x, y)) {
                    interx[intersect_counter] = x;
                    intery[intersect_counter] = y;
                    intersect_counter++;
                }
            }
            compute_equation(data[i].pt[1][0], data[i].pt[1][1], data[i].pt[2][0], data[i].pt[2][1], &m_cur, &c_cur);
            compute_equation(data[j].pt[0][0], data[j].pt[0][1], data[j].pt[1][0], data[j].pt[1][1], &m_com, &c_com);
            compute_intersection(m_cur, m_com, c_cur, c_com, &y, &x);
            if (isinrange(data[i].pt[1][0], data[i].pt[1][1], data[i].pt[2][0], data[i].pt[2][1], data[j].pt[0][0], data[j].pt[0][1], data[j].pt[1][0], data[j].pt[1][1], x, y)) {
                if (isnotoverlap(interx, intery, intersect_counter, x, y)) {
                    interx[intersect_counter] = x;
                    intery[intersect_counter] = y;
                    intersect_counter++;
                }
            }
            compute_equation(data[i].pt[0][0], data[i].pt[0][1], data[i].pt[1][0], data[i].pt[1][1], &m_cur, &c_cur);
            compute_equation(data[j].pt[0][0], data[j].pt[0][1], data[j].pt[2][0], data[j].pt[2][1], &m_com, &c_com);
            compute_intersection(m_cur, m_com, c_cur, c_com, &y, &x);
            if (isinrange(data[i].pt[0][0], data[i].pt[0][1], data[i].pt[1][0], data[i].pt[1][1], data[j].pt[0][0], data[j].pt[0][1], data[j].pt[2][0], data[j].pt[2][1], x, y)) {
                if (isnotoverlap(interx, intery, intersect_counter, x, y)) {
                    interx[intersect_counter] = x;
                    intery[intersect_counter] = y;
                    intersect_counter++;
                }
            }
            compute_equation(data[i].pt[0][0], data[i].pt[0][1], data[i].pt[2][0], data[i].pt[2][1], &m_cur, &c_cur);
            compute_equation(data[j].pt[0][0], data[j].pt[0][1], data[j].pt[2][0], data[j].pt[2][1], &m_com, &c_com);
            compute_intersection(m_cur, m_com, c_cur, c_com, &y, &x);
            if (isinrange(data[i].pt[0][0], data[i].pt[0][1], data[i].pt[2][0], data[i].pt[2][1], data[j].pt[0][0], data[j].pt[0][1], data[j].pt[2][0], data[j].pt[2][1], x, y)) {
                if (isnotoverlap(interx, intery, intersect_counter, x, y)) {
                    interx[intersect_counter] = x;
                    intery[intersect_counter] = y;
                    intersect_counter++;
                }
            }
            compute_equation(data[i].pt[1][0], data[i].pt[1][1], data[i].pt[2][0], data[i].pt[2][1], &m_cur, &c_cur);
            compute_equation(data[j].pt[0][0], data[j].pt[0][1], data[j].pt[2][0], data[j].pt[2][1], &m_com, &c_com);
            compute_intersection(m_cur, m_com, c_cur, c_com, &y, &x);
            if (isinrange(data[i].pt[1][0], data[i].pt[1][1], data[i].pt[2][0], data[i].pt[2][1], data[j].pt[0][0], data[j].pt[0][1], data[j].pt[2][0], data[j].pt[2][1], x, y)) {
                if (isnotoverlap(interx, intery, intersect_counter, x, y)) {
                    interx[intersect_counter] = x;
                    intery[intersect_counter] = y;
                    intersect_counter++;
                }
            }
            compute_equation(data[i].pt[0][0], data[i].pt[0][1], data[i].pt[1][0], data[i].pt[1][1], &m_cur, &c_cur);
            compute_equation(data[j].pt[1][0], data[j].pt[1][1], data[j].pt[2][0], data[j].pt[2][1], &m_com, &c_com);
            compute_intersection(m_cur, m_com, c_cur, c_com, &y, &x);
            if (isinrange(data[i].pt[0][0], data[i].pt[0][1], data[i].pt[1][0], data[i].pt[1][1], data[j].pt[1][0], data[j].pt[1][1], data[j].pt[2][0], data[j].pt[2][1], x, y)) {
                if (isnotoverlap(interx, intery, intersect_counter, x, y)) {
                    interx[intersect_counter] = x;
                    intery[intersect_counter] = y;
                    intersect_counter++;
                }
            }
            compute_equation(data[i].pt[0][0], data[i].pt[0][1], data[i].pt[2][0], data[i].pt[2][1], &m_cur, &c_cur);
            compute_equation(data[j].pt[1][0], data[j].pt[1][1], data[j].pt[2][0], data[j].pt[2][1], &m_com, &c_com);
            compute_intersection(m_cur, m_com, c_cur, c_com, &y, &x);
            if (isinrange(data[i].pt[0][0], data[i].pt[0][1], data[i].pt[2][0], data[i].pt[2][1], data[j].pt[1][0], data[j].pt[1][1], data[j].pt[2][0], data[j].pt[2][1], x, y)) {
                if (isnotoverlap(interx, intery, intersect_counter, x, y)) {
                    interx[intersect_counter] = x;
                    intery[intersect_counter] = y;
                    intersect_counter++;
                }
            }
            compute_equation(data[i].pt[1][0], data[i].pt[1][1], data[i].pt[2][0], data[i].pt[2][1], &m_cur, &c_cur);
            compute_equation(data[j].pt[1][0], data[j].pt[1][1], data[j].pt[2][0], data[j].pt[2][1], &m_com, &c_com);
            compute_intersection(m_cur, m_com, c_cur, c_com, &y, &x);
            if (isinrange(data[i].pt[1][0], data[i].pt[1][1], data[i].pt[2][0], data[i].pt[2][1], data[j].pt[1][0], data[j].pt[1][1], data[j].pt[2][0], data[j].pt[2][1], x, y)) {
                if (isnotoverlap(interx, intery, intersect_counter, x, y)) {
                    interx[intersect_counter] = x;
                    intery[intersect_counter] = y;
                    intersect_counter++;
                }
            }
        }
    }
    sortintersection(interx, intery, intersect_counter);
    fractionize(interx, intery, intersect_counter, xson, xmom, yson, ymom);
    printintersection_fraction(xson, xmom, yson, ymom, intersect_counter);
    return 0;
}
