#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> p;

int find(int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool uni(int u, int v) {
    u = find(u);
    v = find(v);

    if (u == v) return false;
    
    p[v] = u;
    return true;
}

struct Edge {
    int u, v, w;

    constexpr Edge() : Edge(0, 0, 0) { }
    constexpr Edge(int u, int v, int w) 
        : u(u), v(v), w(w) { }
};

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int v, e;
    std::cin >> v >> e;

    p.assign(v + 1, -1);
    
    std::vector<Edge> edges(e);
    for (auto& [a, b, c] : edges) {
        std::cin >> a >> b >> c;
    }

    std::ranges::sort(edges, {}, &Edge::w);

    int weight = 0, count = 0;

    for (auto const& [a, b, c] : edges) {
        if (uni(a, b)) {
            weight += c;
            count += 1;
            
            if (count == v - 1) {
                break;
            }
        }
    }

    std::cout << weight;
    return 0;
}
