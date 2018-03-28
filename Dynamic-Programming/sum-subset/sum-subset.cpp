#include <iostream>
#include <cstdlib>
#include <cmath>

const int A_SIZE = 4;

int min_difference(int const & a, int const & b, int const & c, int const & total) {

    int a1 = abs(total - a);
    int b1 = abs(total - b);
    int c1 = abs(total - c);

    if (a1 <= b1) {
        if (a1 <= c1) return a1;
        return c1;
    }
    if (b1 <= c1) return b1;
    return c1;
}

int min_difference(int const & a, int const & b, int const & total) {
    int a1 = abs(total - a);
    int b1 = abs(total - b);
    if (a1 <= b1) return a1;
    return b1;
}

int main() {

    int a[A_SIZE];
    a[0] = 1;
    a[1] = 7;
    a[2] = 4;
    a[3] = 12;

    for (int m = 0; m <= 24; ++m) {
        // Sum all of @a together and check if less than @m
        int a_total = 0;
        for (int i = 0; i < A_SIZE; ++i) {
            a_total += a[i];
        }
        if (a_total <= m) {
            std::cout << "Sum of subset is " << a_total << std::endl;
            return EXIT_SUCCESS;
        }

        int table[A_SIZE + 1][m + 1];

        for (int i = 0; i < A_SIZE + 1; ++i) {
            table[i][0] = 0;
        }
        for (int j = 0; j < m + 1; ++j) {
            table[0][j] = 0;
        }

        for (int i = 1; i < A_SIZE + 1; ++i) {
            for (int j = 1; j < m + 1; ++j) {
                if (a[i - 1] <= j) {
                    if (abs(j - a[i - 1])
                            == min_difference(a[i - 1], a[i - 1] + table[i - 1][j - a[i - 1]], table[i - 1][j], j)) {
                        table[i][j] = a[i - 1];
                    }
                    else if (abs(j - table[i-1][j])
                             == min_difference(a[i-1], a[i-1] + table[i - 1][j - a[i-1]], table[i - 1][j], j)) {
                        table[i][j] = table[i-1][j];
                    }
                    else table[i][j] = a[i-1] + table[i-1][j-a[i-1]];
                }
                else {
                    if (abs(j - a[i-1]) == min_difference(a[i-1], table[i - 1][j], j)) {
                        table[i][j] = a[i-1];
                    }
                    else table[i][j] = table[i - 1][j];
                }
            }
        }

        std::cout << "Sum of subset is " << table[A_SIZE][m] << std::endl;
    }
    return EXIT_SUCCESS;
}
