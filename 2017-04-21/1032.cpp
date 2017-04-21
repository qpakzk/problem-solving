#include <cstdio>
#include <cstring>

#define MAXLEN 51

char res[MAXLEN];
char cmd[MAXLEN];

int main(void) {
    int N;
    scanf("%d%s", &N, res);

    while(--N) {
        scanf("%s", cmd);
        for(int i = 0; i < strlen(res); i++)
            if(res[i] != '?' && res[i] != cmd[i])
                res[i] = '?';
    }
    puts(res);
    return 0;
}
