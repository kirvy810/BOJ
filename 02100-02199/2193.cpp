#include <iostream>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    std::cin >> n;
    
    long long a = 0, b = 1;

    while (n--) {
        b += a;
        a = b - a;
    }

    std::cout << a;
    return 0;
}
