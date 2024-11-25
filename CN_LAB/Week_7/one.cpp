#include <stdio.h>

int main()
{
    int w, i, f, frames[50];

    // Ask user for window size
    printf("Enter window size: ");
    scanf("%d", &w);

    // Ask user for number of frames to transmit
    printf("\nEnter number of frames to transmit: ");
    scanf("%d", &f);

    // Ask user to input the frames
    printf("\nEnter %d frames: ", f);
    for (i = 1; i <= f; i++)
    {
        scanf("%d", &frames[i]);
    }

    // Output the transmission sequence using sliding window protocol
    printf("\nWith sliding window protocol the frames will be sent in the following manner (assuming no corruption of frames)\n\n");
    printf("After sending %d frames at each stage, the sender waits for the acknowledgement sent by the receiver\n\n", w);

    for (i = 1; i <= f; i++)
    {
        if (i % w == 0)
        {
            // Print the frame number and acknowledgement
            printf("%d\n", frames[i]);
            printf("Acknowledgement of above frames sent is received by sender\n\n");
        }
        else
        {
            // Print frames with no acknowledgement yet
            printf("%d ", frames[i]);
        }
    }

    // If the total number of frames is not a multiple of the window size
    if (f % w != 0)
    {
        printf("\nAcknowledgement of above frames sent is received by sender\n");
    }

    return 0;
}
