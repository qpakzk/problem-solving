//https://www.acmicpc.net/problem/11758

#include <iostream>
using namespace std;

struct Point {
    int x, y;
};

int ccw(Point A, Point B, Point C) {
    long long ret = (A.x * B.y + B.x * C.y + C.x * A.y)
                    - (A.y * B.x + B.y * C.x + C.y * A.x);

    if(ret > 0)
        return 1;
    else if(ret == 0)
        return 0;
    else
        return -1;
}
int main(void) {
    Point pt[3];

    for(int i = 0; i < 3; i++)
        cin >> pt[i].x >> pt[i].y;

    cout << ccw(pt[0], pt[1], pt[2]) << endl;
    return 0;
}
