#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Function to determine the initial person for the survivor to start with
int shift(int n, int survivor) {
    int epsilon = survivor - 1;
    return (((n) - epsilon) % n) + 1;
}

// Function to simulate Romano-Jewish Roulette and find the survivor
int Romano_Jewish_Roulette(int n_persons, int k_count) {
    int persons_order[n_persons];  // Array to represent the order of persons
    int eliminated = 0;            // Counter for the number of eliminated persons
    int count = 0;                  // Counter for the k_count

    // Initializing the persons_order array with the original order of persons
    for (int i = 0; i < n_persons; i++) {
        persons_order[i] = i;
    }

    // Simulation loop until only one person remains
    for (int i = 0; eliminated != n_persons - 1; i++) {
        if (persons_order[i % n_persons] != -1)  // Check if the person is still alive
            count++;

        if (count == k_count) {
            persons_order[i % n_persons] = -1;  // Eliminate the kth person immediately

            int dig = 0;    // Number of persons skipped after the eliminated person to dig
            int k = i + 1;  // Start searching for the next person to eliminate

            // Find the next person to eliminate after skipping k_count persons
            while (dig != k_count) {
                if (persons_order[k % n_persons] != -1) {
                    dig++;
                }
                k++;
            }

            // Replace the eliminated person with the next person to be eliminated
            persons_order[i % n_persons] = persons_order[(k - 1) % n_persons];
            persons_order[(k - 1) % n_persons] = -1;

            count = 0;       // Reset the count for the next round
            eliminated++;    // Increment the eliminated count
        }
    }

    // Find the survivor's position and return the shifted position
    int i = 0;
    for (; i < n_persons; i++) {
        if (persons_order[i] != -1) {
            break;
        }
    }
    return shift(n_persons, persons_order[i] + 1);
}


int main() {
    int p = -1, k = 1;  // Initialize variables for the number of persons and k_count


    while (scanf("%d%d", &p, &k) && (p > 0 && k > 0)) {
        printf("%d\n", Romano_Jewish_Roulette(p, k));  // Print the position of the survivor
    }

    return 0;  

}
