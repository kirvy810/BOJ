#include <iostream>

constexpr int R = 1'000'000;

int v[2 * R + 1];

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    std::cin >> n;

    while (n--) {
        int x;
        std::cin >> x;
        v[x + R] += 1;
    }

    for (int i = -R; i <= R; ++i) {
        while (v[i + R]--) {
            std::cout << i << '\n';
        }
    }

    return 0;
}
