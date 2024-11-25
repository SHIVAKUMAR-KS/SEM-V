#include <stdio.h>
#include <stdlib.h>

#define MIN(x, y) ((x) > (y) ? (y) : (x))

int main() 
{ 
    int orate, drop = 0, cap, x, count = 0, inp[10] = {0}, i = 0, nsec, ch; 
    
    // Get Bucket Size (Capacity)
    printf("\nEnter Bucket Size: "); 
    scanf("%d", &cap); 
    
    // Get Output Rate
    printf("\nEnter Output Rate: "); 
    scanf("%d", &orate); 

    // Input packet arrivals over time
    do 
    { 
        printf("\nEnter number of packets coming at second %d: ", i + 1); 
        scanf("%d", &inp[i]); 
        i++; 
        printf("\nEnter 1 to continue or 0 to quit: "); 
        scanf("%d", &ch); 
    } 
    while(ch); 

    nsec = i;

    // Printing header for the output table
    printf("Second \t Received \t Sent \t Dropped \t Remained\n"); 
    
    // Process the packet arrival and output rate each second
    for(i = 0; count || i < nsec; i++) 
    { 
        printf("%d", i + 1); // Print the second number
        printf(" \t%d\t", inp[i]); // Print the packets received in that second
        printf(" \t%d\t", MIN((inp[i] + count), orate)); // Sent packets (min of received and output rate)

        // Calculate the remaining capacity and dropped packets
        if((x = inp[i] + count - orate) > 0) 
        { 
            if(x > cap) 
            { 
                count = cap; 
                drop = x - cap; // If overflow happens, set dropped packets
            } 
            else 
            { 
                count = x; 
                drop = 0; 
            } 
        } 
        else 
        { 
            drop = 0; 
            count = 0; 
        }

        // Print dropped and remaining packets
        printf("\t%d\t%d\n", drop, count); 
    }

    return 0; 
}
