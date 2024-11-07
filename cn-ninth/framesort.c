#include <stdio.h>
#define MAX_FRAMES 10

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int frames[MAX_FRAMES];
    int n, i;

    printf("Enter the number of frames (up to %d): ", MAX_FRAMES);
    scanf("%d", &n);

    if (n > MAX_FRAMES) {
        printf("Number of frames exceeds the limit of %d.\n", MAX_FRAMES);
        return 1;
    }

    printf("Enter the frame numbers:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &frames[i]);
    }

    bubbleSort(frames, n);

    printf("Sorted Frames:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", frames[i]);
    }
    printf("\n");

    return 0;
}

/*Enter the number of frames (up to 10): 7
Enter the frame numbers:
3
4
5
6
7
2
4
Sorted Frames:
2 3 4 4 5 6 7 
*/