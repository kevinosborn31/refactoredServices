#include <iostream>

bool isBadVersion(int version);

int firstBadVersion(int n) {
    int high = n;
    int low = 1;

    while (low < high) {
        int middle = low + (high - low) / 2;
        if (isBadVersion(middle)) {
            high = middle;
        } else {
            low = middle + 1;
        }
    }

    return low;
}

int main() {
    int n = 100; 
    int result = firstBadVersion(n);
    std::cout << "The first bad version is at index " << result << std::endl;

    return 0;
}
