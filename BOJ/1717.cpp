//https://www.acmicpc.net/problem/1717

#include <cstdio>
#define MAX 1000001

int sets[MAX];

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a > b ? b : a;
}
int find(int n) {
    int j = n;
    while(j != sets[j])
        j = sets[j];
    return j;
}

void merge(int i, int j) {
    int a = min(i, j);
    int b = max(i, j);

    int p = find(a);
    int q = find(b);

    if(p != a) {
        sets[p] = q;
        sets[a] = q;
    }
    else
        sets[a] = q;
}

bool equal(int i, int j) {
    int p = find(i);
    int q = find(j);

    return p == q;
}

int main(void) {
    int N, M, op, A, B;
    scanf("%d %d", &N, &M);

    for(int i = 0; i <= N; i++)
        sets[i] = i;

    for(int i = 1; i <= M; i++) {
        scanf("%d %d %d", &op, &A, &B);
        if(op == 0) {
            if(equal(A, B))
                continue;
            merge(A, B);
        }
        else {
            if(equal(A, B))
                puts("YES");
            else
                puts("NO");
        }
    }

    return 0;
}
