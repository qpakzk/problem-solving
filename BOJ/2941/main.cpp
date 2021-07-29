// https://www.acmicpc.net/problem/2941

#include <cstdio>
#include <cstring>

int main() {
    char alphabet[101];
    scanf("%s", alphabet);

    int count = 0;
    for (int i = 0; i < strlen(alphabet); ++i) {
        switch (alphabet[i]) {
            case '\0':
                break;
            case 'c':
                if (alphabet[i + 1] == '=' || alphabet[i + 1] == '-')
                    i++;
                break;
            case 'd':
                if (alphabet[i + 1] == '-')
                    i++;
                else if (alphabet[i + 1] == 'z' && alphabet[i + 2] == '=')
                    i += 2;
                break;
            case 'l':
            case 'n':
                if (alphabet[i + 1] == 'j')
                    i++;
                break;
            case 's':
            case 'z':
                if (alphabet[i + 1] == '=')
                    i++;
                break;
        }

        count++;
    }

    printf("%d\n", count);
    return 0;
}
