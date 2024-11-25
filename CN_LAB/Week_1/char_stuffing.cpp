#include<stdio.h>
#include<string.h>

int main()
{
    char c[50], d[50];
    int i, j, n;

    printf("\nEnter input frame:\n");
    gets(c);  // Use fgets for safety in modern applications

    n = strlen(c);
    d[0] = 's';
    d[1] = 't';
    d[2] = 'x';  // Initialize 'd' with the prefix "stx"

    // Loop through the input frame 'c' to check for sequences and perform character stuffing
    for(i = 0, j = 3; i < n; i++, j++)
    {
        // Check for the sequence "dle"
        if(c[i] == 'd' && c[i+1] == 'l' && c[i+2] == 'e')
        {
            d[j] = 'd';
            j++;
            d[j] = 'l';
            j++;
            d[j] = 'e';
            j++;
            n = n + 3;  // Increase the length of the frame due to stuffing
        }
        // Check for the sequence "stx"
        else if(c[i] == 's' && c[i+1] == 't' && c[i+2] == 'x')
        {
            d[j] = 's';
            j++;
            d[j] = 't';
            j++;
            d[j] = 'x';
            j++;
            n += 3;  // Increase the length of the frame due to stuffing
        }
        // Check for the sequence "etx"
        else if(c[i] == 'e' && c[i+1] == 't' && c[i+2] == 'x')
        {
            d[j] = 'e';
            j++;
            d[j] = 't';
            j++;
            d[j] = 'x';
            j++;
            n += 3;  // Increase the length of the frame due to stuffing
        }

        // Copy the current character to the new frame
        d[j] = c[i];
    }

    // Append the suffix "etx" at the end of the frame
    n = n + 2;
    n++;
    d[n] = 'e';
    n++;
    d[n] = 't';
    n++;
    d[n] = 'x';
    n++;
    d[n] = '\0';  // Null-terminate the stuffed frame

    printf("\nAfter character stuffing, the frame is:\n");
    puts(d);  // Output the resulting stuffed frame
}
