#include <algorithm>
#include <iostream>
#include <ranges>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int n = 0;
    std::pair<long long, bool> v[26]{};
    std::cin >> n;

    while (n--) {
        std::string s;
        std::cin >> s;

        long long r = 1;
        for (char c : s | std::views::reverse) {
            v[c - 'A'].first += r;
            r *= 10;
        }

        v[s[0] - 'A'].second = true;
    }

    std::ranges::sort(v | std::views::reverse);

    if (v[9].second) {
        int k = 0;
        for (int i = 8; 0 <= i; --i) {
            if (!v[i].second && 0 < v[i].first) {
                k = i;
                break;
            }
        }

        for (int i = k; i < 9; ++i) {
            std::swap(v[i], v[i + 1]);
        }
    }
    
    long long sum = 0;
    for (int i = 0; i < 10; ++i) {
        sum += v[i].first * (9 - i);
    }
    
    std::cout << sum;
    return 0;
}
