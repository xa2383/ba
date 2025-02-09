#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
char plaintext[100];
printf("Enter the word to be encrypted: ");
scanf("%s", plaintext);
int len = strlen(plaintext), matrix[len][len], result[len];
printf("Enter %d x %d encryption matrix:\n", len, len);
for (int i = 0; i < len; i++)
for (int j = 0; j < len; j++)
scanf("%d", &matrix[i][j]);
for (int i = 0; i < len; i++) {
result[i] = 0;
for (int j = 0; j < len; j++)
result[i] += matrix[i][j] * (plaintext[j] - 'a');
result[i] = (result[i] % 26) + 'a';
}
printf("The cipher text is: ");
for (int i = 0; i < len; i++)
printf("%c", result[i]);
printf("\n");
return 0;
}