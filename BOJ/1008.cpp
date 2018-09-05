//https://www.acmicpc.net/problem/1008

#include <iostream>
using namespace std;

int main(void) {
    string ans;
    int d, s, q, r;

    scanf("%d %d", &d, &s);

    q = d / s;
    r = d % s;

    ans = to_string(q);
    if(r == 0) {
        cout << ans << endl;
        return 0;
    }

    ans += ".";

    for(int i = 1; i <= 32; i++) {
        d = r * 10;
        q = d / s;
        r = d % s;
        ans += to_string(q);

        if(r == 0)
            break;
    }

    cout << ans << endl;
    return 0;
}
