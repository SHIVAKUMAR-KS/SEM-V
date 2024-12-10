#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    int i, kl;
    char cipher[50], plain[50];
    char key[50];

    // Prompt for plain text input using gets
    printf("\nEnter plain text: ");
    gets(plain);  // Use gets(), although unsafe

    // Prompt for the encryption key using gets
    printf("Enter the encryption key: ");
    gets(key);  // Use gets(), although unsafe

    kl = strlen(key);

    // Encrypt the plain text using XOR with key length
    for (i = 0; plain[i] != '\0'; i++) {
        cipher[i] = plain[i] ^ kl;  // XOR each character with key length
    }
    cipher[i] = '\0';  // Null-terminate the cipher text

    // Print the encrypted text
    printf("Encrypted text is: ");
    puts(cipher);

    // Decrypt the cipher text using XOR with the same key length
    printf("Decrypted text is: ");
    for (i = 0; cipher[i] != '\0'; i++) {
        plain[i] = cipher[i] ^ kl;  // XOR each character again to decrypt
    }
    plain[i] = '\0';  // Null-terminate the decrypted text

    // Print the decrypted text
    puts(plain);
}


/*
Enter plain text: shiva'
Enter the encryption key: 10
Encrypted text is: qjktc%
Decrypted text is: shiva'
PS D:\Sem-V\LAB\CN_LAB\Week_5> 
*/