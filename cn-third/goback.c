#include <stdio.h>

int main() {
    int windowSize, sent = 0, ack, i;
    
    // Input the window size
    printf("Enter window size: ");
    scanf("%d", &windowSize);
    
    // Simulating the Go-Back-N protocol
    while (1) {
        // Send frames within the window size
        for (i = 0; i < windowSize; i++) {
            printf("Frame %d has been transmitted.\n", sent);
            sent++;
            if (sent == windowSize) {
                break;
            }
        }
        
        // Ask for the last acknowledgment received
        printf("\nPlease enter the last acknowledgment received: ");
        scanf("%d", &ack);
        
        // If all frames in the window have been acknowledged, break the loop
        if (ack == windowSize) {
            break;
        }
        
        // In Go-Back-N, resend all frames starting from the unacknowledged frame
        sent = ack;  // Reset sent to the last acknowledged frame and retransmit frames
    }

    return 0;
}



/*Enter window size: 8
Please enter the last acknowledgment received: 8

Frame 0 has been transmitted.
Frame 1 has been transmitted.
Frame 2 has been transmitted.
Frame 3 has been transmitted.
Frame 4 has been transmitted.
Frame 5 has been transmitted.
Frame 6 has been transmitted.
Frame 7 has been transmitted.

Please enter the last acknowledgment received: 2
Frame 2 has been transmitted.
Frame 3 has been transmitted.
Frame 4 has been transmitted.
Frame 5 has been transmitted.
Frame 6 has been transmitted.
Frame 7 has been transmitted.

Please enter the last acknowledgment received: 8
*/

