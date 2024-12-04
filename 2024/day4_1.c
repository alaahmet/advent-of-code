#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 1000

int main() {
    FILE *file = fopen("a.in", "r");
    if (!file) {
        perror("Failed to open file");
        return EXIT_FAILURE;
    }

    char **s = NULL;
    char buffer[MAX_BUFFER];
    int n = 0;

    while (fgets(buffer, sizeof(buffer), file)) {
        s = realloc(s, (n + 1) * sizeof(char *));
        s[n] = strdup(buffer);
        n++;
    }
    fclose(file);

    int ans = 0;
    int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
    int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 8; k++) {
                int resx = i + 3 * dx[k];
                int resy = j + 3 * dy[k];
                if (resx < 0 || resy < 0) continue;
                if (resx >= n || resy >= n) continue;
                char t[5] = {s[i][j], s[i + dx[k]][j + dy[k]], s[i + 2 * dx[k]][j + 2 * dy[k]], s[i + 3 * dx[k]][j + 3 * dy[k]], '\0'};
                if (strcmp(t, "XMAS") == 0) ans++;
            }
        }
    }

    printf("%d\n", ans);

    for (int i = 0; i < n; i++) {
        free(s[i]);
    }
    free(s);

    return 0;
}
