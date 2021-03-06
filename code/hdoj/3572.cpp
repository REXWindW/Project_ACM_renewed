#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug cout << "here\n"
typedef long long ll;
#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
class DC
{
public:
    struct Edge
    {
        int from;
        int to;
        int flow;
        int cap;
        Edge(int fr, int t, int f, int c) : from(fr), to(t), flow(f), cap(c) {}
    };
    int book[1010];
    int cur[1010];
    int depth[1010];
    int n, m, t, s;
    int cnt = 0;
    vector<Edge> edge;
    vector<int> mp[1010];
    int bfs(int s, int t)
    {
        memset(book, 0, sizeof(book));
        queue<int> q;
        q.push(s);
        book[s] = 1;
        depth[s] = 0;
        while (!q.empty())
        {
            int now = q.front();
            q.pop();
            for (int i = 0; i < mp[now].size(); i++)
            {
                Edge &e = edge[mp[now][i]];
                if (!book[e.to] && e.cap > e.flow)
                {
                    depth[e.to] = depth[e.from] + 1;
                    book[e.to] = 1;
                    q.push(e.to);
                }
            }
        }
        return book[t];
    }
    int dfs(int now, int a)
    {
        if (now == t || a == 0)
            return a;
        int flow = 0;
        int f;
        for (int &i = cur[now]; i < mp[now].size(); i++)
        {
            Edge &e = edge[mp[now][i]];
            if (depth[now] + 1 == depth[e.to] && (f = dfs(e.to, min(a, e.cap - e.flow))) > 0)
            {
                e.flow += f;
                flow += f;
                edge[mp[now][i] ^ 1].flow -= f;
                a -= f;
                if (a == 0)
                    break;
            }
        }
        return flow;
    }
    int Dinic()
    {
        int ans = 0;
        while (bfs(s, t))
        {
            memset(cur, 0, sizeof(cur));
            ans += dfs(s, 0x7FFFFFFF);
        }
        return ans;
    }
    void add_edge(int from, int to, int cap)
    {
        edge.push_back(Edge(from, to, 0, cap));
        edge.push_back(Edge(to, from, 0, 0));
        mp[from].push_back(edge.size() - 2);
        mp[to].push_back(edge.size() - 1);
    }
} fl;
int dates[1010];
int cnt = 0;
void work()
{
    cnt++;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < 500 + n; i++)
    {
        fl.mp[i].clear();
    }
    int sum = 0;
    fl.edge.clear();
    fl.s = 0;
    fl.t = 1009;
    int p, s, e;
    memset(dates, 0, sizeof(dates));
    for (int i = 1; i <= n; i++)
    {
        cin >> p >> s >> e;
        sum += p;
        fl.add_edge(fl.s, i + 500, p);
        for (int j = s; j <= e; j++)
        {
            dates[j] = 1;
            fl.add_edge(500 + i, j, 1);
        }
    }
    for (int i = 0; i <= 500; i++)
    {
        if (dates[i])
            fl.add_edge(i, fl.t, m);
    }
    int ans = fl.Dinic();
    if (ans == sum)
        cout << "Case " << cnt << ": Yes" << endl;
    else
        cout << "Case " << cnt << ": No" << endl;
    cout << endl;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}