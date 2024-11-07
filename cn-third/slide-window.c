//SLIDING WINDOW PROTOCOL,
#include <stdio.h>

int main() {
    int windowSize, numFrames, ack, i, sent = 0;

    // Input the window size and the number of frames to transmit
    printf("Enter window size: ");
    scanf("%d", &windowSize);

    printf("Enter number of frames to transmit: ");
    scanf("%d", &numFrames);

    int frames[numFrames];
    printf("Enter %d frames: ", numFrames);
    for (i = 0; i < numFrames; i++) {
        scanf("%d", &frames[i]);
    }

    // Sliding window protocol simulation
    while (sent < numFrames) {
        // Send frames in batches according to the window size
        printf("\nWith sliding window protocol, the frames will be sent in the following manner (assuming no corruption of frames):\n");

        // Send frames in the window
        for (i = 0; i < windowSize && sent < numFrames; i++) {
            printf("Frame %d: %d has been transmitted.\n", sent + 1, frames[sent]);
            sent++;
        }

        // After sending a batch of frames, wait for acknowledgment
        printf("\nAcknowledgment of above frames sent is received by sender.\n");
        printf("Please enter the last Acknowledgment received: ");
        scanf("%d", &ack);

        // Adjust window position based on the acknowledgment
        // In a real protocol, sent frames would be acknowledged one by one
        if (ack == windowSize) {
            printf("Acknowledgment of frames 1 to %d received.\n", ack);
            // Slide the window by the acknowledged frames
        } else {
            printf("Acknowledgment of frames up to %d received.\n", ack);
            sent = ack;  // Adjust the sent pointer to resend from the acknowledged frame
        }
    }

    return 0;
}




/*output

Enter window size: 3
Enter number of frames to transmit: 5
Enter 5 frames: 12 5 89 4 6

With sliding window protocol, the frames will be sent in the following manner (assuming no corruption of frames):
Frame 1: 12 has been transmitted.
Frame 2: 5 has been transmitted.
Frame 3: 89 has been transmitted.

Acknowledgment of above frames sent is received by sender.
Please enter the last Acknowledgment received: 3
Acknowledgment of frames 1 to 3 received.

Frame 4: 4 has been transmitted.
Frame 5: 6 has been transmitted.

Acknowledgment of above frames sent is received by sender.
Please enter the last Acknowledgment received: 5
Acknowledgment of frames 1 to 5 received.*/

