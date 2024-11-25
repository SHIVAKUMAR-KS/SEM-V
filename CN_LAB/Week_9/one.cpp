#include <stdio.h>

// Maximum number of frames
#define MAX_FRAMES 100

// Frame structure
struct frame {
    int frame_number;
    char data[100]; // assuming data size is 100 bytes
};

// Sorting function for frames based on frame_number
void sortFrames(struct frame frames[], int n) {
    int i, j;
    struct frame temp;

    // Bubble sort algorithm
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (frames[j].frame_number > frames[j + 1].frame_number) {
                // Swap frames
                temp = frames[j];
                frames[j] = frames[j + 1];
                frames[j + 1] = temp;
            }
        }
    }
}

int main() {
    int num_frames, i;

    // Input number of frames
    printf("Enter the number of frames: ");
    scanf("%d", &num_frames);

    // Validate input for frame count
    if (num_frames <= 0 || num_frames > MAX_FRAMES) {
        printf("Invalid number of frames.\n");
        return 1;  // Exit with error code
    }

    struct frame frames[num_frames];

    // Input frame details
    printf("Enter details for each frame:\n");
    for (i = 0; i < num_frames; i++) {
        printf("Frame %d:\n", i + 1);
        printf("Frame number: ");
        scanf("%d", &frames[i].frame_number);
        printf("Data: ");
        scanf(" %99[^\n]", frames[i].data); // Read a string with spaces, limit to 99 characters
    }

    // Sort frames by frame number
    sortFrames(frames, num_frames);

    // Display sorted frames
    printf("\nSorted frames:\n");
    for (i = 0; i < num_frames; i++) {
        printf("Frame %d:\n", frames[i].frame_number);
        printf("Data: %s\n", frames[i].data);
    }

    return 0;
}
