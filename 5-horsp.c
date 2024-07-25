#include <stdio.h>
#include <string.h>

int horspool(char t[], char p[], int n, int m) {
    int table[126];
    int i, j;

    // Initialize the table with default values
    for (i = 0; i < 126; i++)
        table[i] = m;

    // Fill the table with the appropriate shift values
    for (j = 0; j < m - 1; j++)
        table[(int)p[j]] = m - 1 - j;

    i = m - 1;
    while (i < n) {
        j = 0;
        while (j < m && t[i - j] == p[m - 1 - j])
            j++;
        if (j == m)
            return i - m + 1;
        else
            i += table[(int)t[i]];
    }
    return -1;
}

int main() {
    char t[100], p[100];
    int flag;

    printf("Enter the text: ");
    gets(t);

    printf("Enter the pattern: ");
    gets(p);

    flag = horspool(t, p, strlen(t), strlen(p));
    if (flag == -1)
        printf("Pattern not found\n");
    else
        printf("Pattern found at position %d\n", flag + 1);

    return 0;
}
