// https://www.acmicpc.net/problem/1316

#include <cstdio>
#include <cstring>

int main() {
    int N;
    scanf("%d", &N);

    int result = 0;
    while (N--) {
        char word[101];
        scanf("\n%s", word);
        bool alphabets[26] = { false };

        bool exist = false;
        for (int i = 0; i < strlen(word); i++) {
            int index = word[i] - 'a';
            if (alphabets[index]) {
                if (i > 0 && word[i - 1] != word[i]) {
                    exist = true;
                    break;
                }
            } else {
                alphabets[index] = true;
            }
        }

        if (!exist) {
            result++;
        }
    }

    printf("%d\n", result);
    return 0;
}
