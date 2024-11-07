#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUCKET_CAPACITY 10 // Maximum capacity of the bucket
#define LEAK_RATE 1 // Rate at which the bucket leaks (packets per second)

// Function to simulate the Leaky Bucket algorithm
void leakyBucket(int packetArrivalRate, int simulationTime) {
    int bucket = 0; // Initial bucket level
    int time = 0;

    while (time < simulationTime) {
        sleep(1); // Simulate time passing (1 second)
        bucket = bucket > LEAK_RATE ? bucket - LEAK_RATE : 0; // Leak packets

        int packetsArriving = rand() % (packetArrivalRate + 1); // Random packet arrival rate
        printf("Time: %d seconds | Packets Arriving: %d | Bucket Level: %d\n", time, packetsArriving, bucket);

        bucket += packetsArriving;
        if (bucket > BUCKET_CAPACITY) {
            printf("Bucket Overflow! Dropping %d packets.\n", bucket - BUCKET_CAPACITY);
            bucket = BUCKET_CAPACITY; // Set bucket to maximum capacity
        }

        time++;
    }
}

int main() {
    int packetArrivalRate, simulationTime;
    printf("Enter the maximum packet arrival rate (packets per second): ");
    scanf("%d", &packetArrivalRate);
    printf("Enter the simulation time (seconds): ");
    scanf("%d", &simulationTime);

    leakyBucket(packetArrivalRate, simulationTime);

    return 0;
}


/*Enter the maximum packet arrival rate (packets per second): 2
Enter the simulation time (seconds): 4
Time: 0 seconds | Packets Arriving: 1 | Bucket Level: 0
Time: 1 seconds | Packets Arriving: 1 | Bucket Level: 0
Time: 2 seconds | Packets Arriving: 0 | Bucket Level: 0
Time: 3 seconds | Packets Arriving: 1 | Bucket Level: 0
*/