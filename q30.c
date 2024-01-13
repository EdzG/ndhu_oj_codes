#include <stdio.h>

// Array to store the height at each position
int height[10000] = {0};

int main() {
    int l, h, r, max_right = 0;

    // Loop to read input values for building heights and update the height array
    while (scanf("%d %d %d", &l, &h, &r) == 3) {
        // Update the height array for the given building range [l, r) with height h
        for (int i = l; i < r; i++) {
            height[i] = (height[i] > h) ? height[i] : h; // Set the maximum height for each position
        }

        // Update the maximum right position encountered so far
        max_right = (max_right > r) ? max_right : r;
    }

    // Loop to print the skyline positions and heights
    for (int i = 1; i < max_right; i++) {
        if (height[i] != height[i - 1]) {
            // Print the position and height when there's a change in height
            printf("%d %d ", i, height[i]);
        }
    }

    // Print the final position with height 0 as the last point in the skyline
    printf("%d 0\n", max_right);

    return 0; 
}