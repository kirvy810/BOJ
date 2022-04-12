#include <iostream>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int s, t, d;
    std::cin >> s >> t >> d;
    std::cout << d / 2 / s * t;
    return 0;
}
