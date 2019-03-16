#include <stdio.h>
#include <math.h>

typedef struct Point {
    double x;
    double y;
} P;

double dist_pure(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

double dist_struct(P p1, P p2) {
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

int main() {
    printf("struct!\n");

    double x1;
    double y1;
    double x2;
    double y2;
    scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);

    printf("result_pure: %.2lf\n", dist_pure(x1, y1, x2, y2));

    Point p1 = {x1, y1};
    Point p2 = {x2, y2};
    printf("result_struct: %.2lf\n", dist_struct(p1, p2));

    return 0;
}
