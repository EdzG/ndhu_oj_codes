#include <algorithm>
#include <iostream>
#include <vector>


class TrainManager {
private:
    std::vector<int> carWeights; 

public:
    void inputCarWeights(int nCars) {
        carWeights.resize(nCars); 
        for (int i = 0; i < nCars; ++i) {
            std::cin >> carWeights[i]; 
        }
    }

    // Method to calculate and return the length of the longest train that can be formed.
    int getLongestTrain() {
        int n = carWeights.size();
        if (n == 0) return 0; 

        std::vector<int> LIS, LDS; // Vectors to store the lengths of LIS and LDS.
        int maxLen = 0; 

        // Iterate over the cars from the last to the first.
        for (int i = n - 1; i >= 0; i--) {
            int len1, len2;

            // Calculate LDS (Longest Decreasing Subsequence)
            auto it = std::lower_bound(LDS.begin(), LDS.end(), carWeights[i]);
            if (it == LDS.end()) {
                LDS.push_back(carWeights[i]); // Append to LDS if not found.
                len2 = LDS.size(); // Length of LDS.
            } else {
                *it = carWeights[i]; // Replace the found element.
                len2 = it - LDS.begin() + 1; // Calculate length of LDS.
            }

            // Calculate LIS (Longest Increasing Subsequence) by considering -carWeights[i] for decreasing order.
            it = std::lower_bound(LIS.begin(), LIS.end(), -carWeights[i]);
            if (it == LIS.end()) {
                LIS.push_back(-carWeights[i]); // Append to LIS if not found.
                len1 = LIS.size(); // Length of LIS.
            } else {
                *it = -carWeights[i]; // Replace the found element.
                len1 = it - LIS.begin() + 1; // Calculate length of LIS.
            }

            // Update the maximum length considering both LIS and LDS.
            maxLen = std::max(maxLen, len1 + len2 - 1);
        }

        return maxLen; 
    }

    
    void cleanStation() {
        carWeights.clear(); 
    }
};

int main() {
    int testCases = 0; 
    TrainManager manager; 

    std::cin >> testCases; 
    while (testCases > 0) {
        int nCars;
        std::cin >> nCars; 
        manager.inputCarWeights(nCars); 
        std::cout << manager.getLongestTrain() << std::endl; 
        manager.cleanStation(); 
        testCases--; 
    }

    return 0;
}
