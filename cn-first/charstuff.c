#include <stdio.h>
#include <string.h>

void main() {
    int i = 0, j = 0, n, pos;
    char a[50], b[100], ch;
    
    printf("Enter string: ");
    scanf("%s", a);  // Reads the string
    n = strlen(a);  // Length of the string
    
    printf("Enter position: ");
    scanf("%d", &pos);
    
    if (pos > n) {
        printf("Invalid position, Enter again: ");
        scanf("%d", &pos);
    }
    
    printf("Enter the character: ");
    scanf(" %c", &ch);  // Use " %c" to avoid any newline or extra space input issues
    
    // Initialize the frame with 'dle' marker sequences
    b[0] = 'd';
    b[1] = 'l';
    b[2] = 'e';
    b[3] = 's';
    b[4] = 't';
    b[5] = 'x';
    j = 6;  // Start index after 'dle' + 'stx'
    
    // Loop through the original string
    while (i < n) {
        // If the current position matches the user-defined position, insert the stuffing sequence
        if (i == pos - 1) {
            b[j] = 'd'; b[j + 1] = 'l'; b[j + 2] = 'e'; b[j + 3] = ch;
            b[j + 4] = 'd'; b[j + 5] = 'l'; b[j + 6] = 'e'; b[j + 7] = 'e';
            b[j + 8] = 't'; b[j + 9] = 'x';
            j += 10;  // Move the pointer ahead
        }

        // Stuff 'dle' sequence if it is encountered in the original string
        if (a[i] == 'd' && a[i + 1] == 'l' && a[i + 2] == 'e') {
            b[j] = 'd'; b[j + 1] = 'l'; b[j + 2] = 'e';  // Copy 'dle'
            j += 3;  // Move the pointer ahead
        }

        // Copy the current character of the original string to the new string
        b[j] = a[i];
        i++; j++;  // Move to the next position
    }
    
    // Add the end 'dle' sequence
    b[j] = 'd'; b[j + 1] = 'l'; b[j + 2] = 'e'; b[j + 3] = 'e'; b[j + 4] = 't';
    b[j + 5] = 'x'; b[j + 6] = '\0';  // Null-terminate the string
    
    // Output the final stuffed frame
    printf("\nFrame after stuffing:\n");
    printf("%s", b);
}

