#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int L, P, V;
    int iter = 0;

    while(1) {
        cin >> L >> P >> V;
        if(!L && !P && !V)
            break;
        int q = V / P;
        int r = V % P;

        cout << "Case " << ++iter << ": " << L * q + min(r, L) << endl;

    }
    return 0;
}
