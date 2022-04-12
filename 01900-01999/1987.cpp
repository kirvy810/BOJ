#include <iostream>

constexpr int dx[4] = {1, -1, 0, 0};
constexpr int dy[4] = {0, 0, 1, -1};

int r, c, result = 0;

char board[20][20];
bool visited[20][20];
bool used[26];

void go(int x, int y, int k) {
    visited[x][y] = true;
    used[board[x][y] - 'A'] = true;

    result = std::max(result, k);
    
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (0 <= nx && nx < r &&
            0 <= ny && ny < c &&
            !visited[nx][ny] &&
            !used[board[nx][ny] - 'A']) 
        {
            go(nx, ny, k + 1);    
        }
    }
    
    visited[x][y] = false;
    used[board[x][y] - 'A'] = false;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::cin >> r >> c;

    for (int i = 0; i < r; ++i) {
        std::cin >> std::ws;
        for (int j = 0; j < c; ++j) {
            board[i][j] = std::cin.get();
        }
    }

    go(0, 0, 1);

    std::cout << result;
    return 0;
}
