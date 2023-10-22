#include <iostream>
#include <vector>

int nthSpecialNumber(int n) {
    if (n == 1) {
        return 1;
    }

    std::vector<int> specialNumbers(n, 0);
    specialNumbers[0] = 1;
    int idx2 = 0, idx3 = 0, idx5 = 0;

    for (int i = 1; i < n; ++i) {
        int next2 = specialNumbers[idx2] * 2;
        int next3 = specialNumbers[idx3] * 3;
        int next5 = specialNumbers[idx5] * 5;

        specialNumbers[i] = std::min(next2, std::min(next3, next5));

        if (specialNumbers[i] == next2) {
            idx2++;
        }
        if (specialNumbers[i] == next3) {
            idx3++;
        }
        if (specialNumbers[i] == next5) {
            idx5++;
        }
    }

    return specialNumbers[n - 1];
}

int main() {
    int n;
    std::cin >> n;

    int result = nthSpecialNumber(n);
    std::cout << result << '\n';

    return 0;
}
