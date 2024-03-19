#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *A, int *B) {
    int C = *A;
    *A = *B;
    *A = C;
}

int bubbleSort(int arr[], int n) {
    int steps = 0;
    for (int i = 0; i < n-1; i++) {
        int swapped = 0;
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
                steps++;
                swapped = 1;
                printf("Pertukaran %d: ", steps);
                for (int k = 0; k < n; k++) printf("%d ", arr[k]);
                printf("\n");
            }
        }
        if (!swapped) break;
    }
    return steps;
}

int main() {
    int n;
    scanf("%d", &n);

    int cards[n];
    for (int i = 0; i < n; i++) {
        char value[3];
        scanf("%s", value);
        cards[i] = (value[0] >= '2' && value[0] <= '9') ? atoi(value) : ((value[0] == 'J') ? 11 : ((value[0] == 'Q') ? 12 : ((value[0] == 'K') ? 13 : 10)));
    }

    int steps = bubbleSort(cards, n);
    printf("%d\n", steps);

    return 0;
}
