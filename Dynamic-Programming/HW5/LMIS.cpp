#include <iostream>
#include <cstdlib>
#include <algorithm>

const int A_SIZE = 12;

int max(int const & a, int const & b) {
    if (a > b) return a;
    return b;
}

// Calculates the longest monetonically increasing subsequence of A 
// in O(n^2) time using dynamic programming techniques.
// TODO: Document this project better
// TODO: make this project work with command line inputs
//
// See https://www.youtube.com/watch?v=E6us4nmXTHs
// See problem 4 in homework-5.pdf
int main() {
    int A[A_SIZE] = {0, 4, 12, 2, 10, 6, 9, 13, 3, 11, 7, 15};
    int L[A_SIZE];
    int S[A_SIZE];
    S[0] = -1;

    for (int k = 0; k < A_SIZE; ++k) {
        L[k] = 1;
    }

    for (int i = 1; i < A_SIZE; ++i) {
        for (int j = 0; j < i; ++j) {
            if (A[i] > A[j]) {
                L[i] = max(L[i], L[j] + 1);
                if (L[j] + 1 == max(L[i], L[j] + 1)) {
                    S[i] = j;
                }
            }
        }
    }

    auto max_length = std::max_element(L, L + A_SIZE);
    auto max_length_index = std::distance(L, max_length);
    std::cout << "Max length is " << *max_length << std::endl;

    int R[*max_length];
    R[*max_length - 1] = max_length_index;
    for (int i = *max_length - 1; i > 0; --i) {
        R[i - 1] = S[R[i]];
    }

    std::cout << "Subsequence is: ";
    for (int i = 0; i < *max_length; ++i) {
        std::cout << A[R[i]] << ", ";
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}
