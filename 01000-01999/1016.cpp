#include <iostream>
#include <vector>

struct Bit {
    bool bit;

    constexpr Bit(bool bit = false) : bit(bit) { }

    constexpr operator bool&() {
        return bit;
    }
};

using i64 = long long;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    i64 min, max;
    std::cin >> min >> max;

    int count = max - min + 1;
    std::vector<Bit> sieve(count, true);

    for (i64 i = 2; i * i <= max; ++i) {
        i64 const k = i * i;
        
        for (i64 j = min / k; j * k <= max; ++j) {
            if (auto n = j * k - min; 0 <= n && sieve[n]) {
                sieve[n] = false;
                count -= 1;
            }
        }
    }

    std::cout << count;
    return 0;
}
