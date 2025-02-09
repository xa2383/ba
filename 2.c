#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100
void generateKeyTable(char key[], int ks, char keyT[5][5]) {
int dicty[26] = {0}, i = 0, j = 0;
dicty['j' - 'a'] = 1;
for (int k = 0; k < ks; k++) {
if (dicty[key[k] - 'a'] == 0 && key[k] != 'j') {
dicty[key[k] - 'a'] = 1;
keyT[i][j++] = key[k];
if (j == 5) i++, j = 0;
}
}
for (int k = 0; k < 26; k++) {
if (dicty[k] == 0) {
keyT[i][j++] = (char)(k + 'a');
if (j == 5) i++, j = 0;
}
}
for(i=0;i<5;i++)
{
for(j=0;j<5;j++)
{
printf("%c ",keyT[i][j]);
}
printf("\n");
}
}
int prepare(char str[], int len) {
for (int i = 0; i < len; i += 2) {
if (str[i] == str[i+1]) {
for (int j = len; j > i + 1; j--)
str[j] = str[j - 1];
str[i + 1] = 'x';
len++;
}
}
if (len % 2 != 0) str[len++] = 'x';
str[len] = '\0';
return len;
}
void search(char keyT[5][5], char a, char b, int arr[]) {
if (a == 'j') a = 'i';
if (b == 'j') b = 'i';
for (int i = 0; i < 5; i++)
for (int j = 0; j < 5; j++) {
if (keyT[i][j] == a) arr[0] = i, arr[1] = j;
if (keyT[i][j] == b) arr[2] = i, arr[3] = j;
}
}
void encrypt(char str[], char keyT[5][5], int len) {
int pos[4];
for (int i = 0; i < len; i += 2) {
search(keyT, str[i], str[i + 1], pos);
if (pos[0] == pos[2]) {
str[i] = keyT[pos[0]][(pos[1] + 1) % 5];
str[i + 1] = keyT[pos[0]][(pos[3] + 1) % 5];
}
else if (pos[1] == pos[3]) {
str[i] = keyT[(pos[0] + 1) % 5][pos[1]];
str[i + 1] = keyT[(pos[2] + 1) % 5][pos[1]];
}
else {
str[i] = keyT[pos[0]][pos[3]];
str[i + 1] = keyT[pos[2]][pos[1]];
}
}
}
void PlayfairCrypt(char str[], char key[]) {
char keyT[5][5];
int ks = strlen(key);
int ps = strlen(str);
ps = prepare(str, ps);
generateKeyTable(key, ks, keyT);
encrypt(str, keyT, ps);
printf("\nCipher text: %s\n", str);
}
void main() {
char str[SIZE], key[SIZE];
printf("Enter the key: ");
scanf("%s", key);
printf("Enter the plaintext: ");
scanf("%s", str);
PlayfairCrypt(str, key);
}