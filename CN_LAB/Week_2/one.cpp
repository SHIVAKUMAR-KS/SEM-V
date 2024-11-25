#include<stdio.h>
#include<string.h>

int main() {
    int i, j, divlen, datalen;
    char data[100], div[30], temp[30], quot[100], rem[30], div1[30];

    printf("Enter data: ");
    gets(data);
    printf("Enter divisor: ");
    gets(div);

    divlen = strlen(div);
    datalen = strlen(data);

    strcpy(div1, div);

    // Append zeros to the data
    for(i = 0; i < divlen - 1; i++) {
        data[datalen + i] = '0';
    }

    // Initialize temp with the first portion of data
    for(i = 0; i < divlen; i++) {
        temp[i] = data[i];
    }

    // Division process
    for(i = 0; i < datalen; i++) {
        quot[i] = temp[0];

        // If the quotient bit is '0', set the divisor to '0'
        if(quot[i] == '0') {
            for(j = 0; j < divlen; j++) {
                div[j] = '0';
            }
        } else {
            // Otherwise, set the divisor to the original divisor
            for(j = 0; j < divlen; j++) {
                div[j] = div1[j];
            }
        }

        // Perform XOR operation between temp and divisor
        for(j = divlen - 1; j > 0; j--) {
            if(temp[j] == div[j]) {
                rem[j - 1] = '0';
            } else {
                rem[j - 1] = '1';
            }
        }

        // Set the last bit of the remainder
        rem[divlen - 1] = data[i + divlen];

        // Copy the remainder to temp for next iteration
        strcpy(temp, rem);
    }

    // Final remainder
    strcpy(rem, temp);

    // Display the quotient
    printf("\nQuotient is: ");
    for(i = 0; i < datalen; i++) {
        printf("%c", quot[i]);
    }

    // Display the remainder
    printf("\nRemainder is: ");
    for(i = 0; i < divlen - 1; i++) {
        printf("%c", rem[i]);
    }

    // Display the final data
    printf("\nFinal data is: ");
    for(i = 0; i < datalen; i++) {
        printf("%c", data[i]);
    }

    for(i = 0; i < divlen - 1; i++) {
        printf("%c", rem[i]);
    }
}
