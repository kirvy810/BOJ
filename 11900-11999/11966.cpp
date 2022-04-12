#include <bit>
#include <iostream>

int main() {
    unsigned n;
    std::cin >> n;
    std::cout << std::has_single_bit(n);
    return 0;
}
