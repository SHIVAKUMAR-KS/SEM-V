#include<stdio.h>
#include<string.h>

int main()
{
    int n, i, j, k, c;
    char a[50], b[50];
    
    printf("Enter input frame (0's & 1's):\n");
    gets(a);  // It's better to use fgets to avoid buffer overflow, but for now we leave it as it is
    
    n = strlen(a);
    strcpy(b, "01111110");  // Start with the frame delimiter
    
    i = 0;
    j = 8;  // Start after the initial "01111110"
    
    while(i < n)
    {
        c = 1;
        
        if(a[i] == '1')
        {
            b[j] = a[i];
            
            // Check for consecutive '1's
            for(k = i + 1; a[k] == '1' && k < n && c < 5; k++)
            {
                j++;
                b[j] = a[k];
                c++;
                
                // Add a '0' after 5 consecutive '1's (stuffing)
                if(c == 5)
                {
                    j++;
                    b[j] = '0';
                }
                
                i = k;
            }
        }
        else
        {
            b[j] = a[i];
        }
        
        i++;
        j++;
    }
    
    b[j] = '\0';  // Null-terminate the string
    
    // Append the frame delimiter at the end
    strcat(b, "01111110");
    
    printf("After stuffing, the frame is:\n");
    puts(b);
}
