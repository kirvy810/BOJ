#include <algorithm>
#include <iostream>

constexpr std::pair<int, int> offsets[8] {
    {1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}
};

int w, h;

bool v[50][50];

void dfs(int x, int y) {
    v[x][y] = false;

    for (auto [dx, dy] : offsets) {
        int nx = x + dx;
        int ny = y + dy;

        if (0 <= nx && nx < h &&
            0 <= ny && ny < w &&
            v[nx][ny])
        {
            dfs(nx, ny);
        }
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    while (true) {
        std::cin >> w >> h;

        if (w == 0 && h == 0) {
            break;
        }

        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                std::cin >> v[i][j];
            }
        }

        int count = 0;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (v[i][j]) {
                    count += 1;
                    dfs(i, j);
                }
            }
        }

        std::cout << count << '\n';
    }
    
    return 0;
}
