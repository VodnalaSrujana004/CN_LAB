#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_LENGTH 100
// Function to encrypt text using Caesar Cipher
void encrypt(char *text, int shift) {
for (int i = 0; text[i] != '\0'; i++) {
if (isalpha(text[i])) {
char base = islower(text[i]) ? 'a' : 'A';
text[i] = (text[i] - base + shift) % 26 + base;
}
}
}
// Function to decrypt text using Caesar Cipher
void decrypt(char *text, int shift) {
for (int i = 0; text[i] != '\0'; i++) {
if (isalpha(text[i])) {
char base = islower(text[i]) ? 'a' : 'A';
text[i] = (text[i] - base - shift + 26) % 26 + base;
}
}
}
int main() {
char text[MAX_LENGTH];
int shift;printf("Enter the text to encrypt: ");
fgets(text, MAX_LENGTH, stdin);
text[strcspn(text, "\n")] = '\0'; // Remove newline character
printf("Enter shift value: ");
scanf("%d", &shift);
// Encryption
char encrypted[MAX_LENGTH];
strcpy(encrypted, text);
encrypt(encrypted, shift);
printf("Encrypted text: %s\n", encrypted);
// Decryption
char decrypted[MAX_LENGTH];
strcpy(decrypted, encrypted);
decrypt(decrypted, shift);
printf("Decrypted text: %s\n", decrypted);
return 0;
}

/*Enter the text to encrypt: economics
Enter shift value: 3
Encrypted text: hfrqrplfv
Decrypted text: economics
*/