#include <iostream>

using u64 = unsigned long long;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    
    u64 x, k;
    std::cin >> x >> k;

    u64 y = 0;
    for (u64 i = 0; k; ++i) {
        if (((x >> i) & 1) == 0) {
            y |= (k & 1) << i;
            k >>= 1;
        }
    }

    std::cout << y;
    return 0;
}
