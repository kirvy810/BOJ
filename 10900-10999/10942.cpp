#include <iostream>

int v[2000];
bool dp[2000][2000];

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
        dp[i][i] = true;
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j + i < n; ++j) {
            dp[j][j + i] = v[j] == v[j + i] && (i == 1 || dp[j + 1][j + i - 1]);
        }
    }

    std::cin >> m;
    while (m--) {
        int s, e;
        std::cin >> s >> e;
        std::cout << dp[s - 1][e - 1] << '\n';
    }
    
    return 0;
}
