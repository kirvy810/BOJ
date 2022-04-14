#include <iostream>
#include <queue>
#include <vector>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> indegree(n + 1);
    std::vector<std::vector<int>> g(n + 1);

    while (m--) {
        int a, b;
        std::cin >> a >> b;

        indegree[b] += 1;
        g[a].push_back(b);
    }

    std::priority_queue<
        int, 
        std::vector<int>, 
        std::greater<int>
    > q;
    for (int i = 1; i <= n; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    std::vector<int> result(n);
    for (int& x : result) {
        x = q.top();
        q.pop();

        for (int nx : g[x]) {
            if (indegree[nx] -= 1; 
                indegree[nx] == 0) {
                q.push(nx);
            }
        }
    }

    for (int x : result) {
        std::cout << x << ' ';
    }
    
    return 0;
}
