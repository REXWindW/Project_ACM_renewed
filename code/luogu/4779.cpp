#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
typedef double db;
typedef long double ld;
template<class T>inline void MAX(T &x,T y){if(y>x)x=y;}
template<class T>inline void MIN(T &x,T y){if(y<x)x=y;}
template<class T>inline void rd(T &x){
   x=0;char o,f=1;
   while(o=getchar(),o<48)if(o==45)f=-f;
   do x=(x<<3)+(x<<1)+(o^48);
   while(o=getchar(),o>47);
   x*=f;
}
template<class T>
void wt(T x){
   if(x < 0) putchar('-'), x = -x;
   if(x >= 10) wt(x / 10);
   putchar('0' + x % 10);
}
#define yx_queue priority_queue
#define lson(pos) (pos<<1)
#define rson(pos) (pos<<1|1)
#define y1 code_by_Rand0w
#define yn A_muban_for_ACM
#define j1 it_is just_an_eastegg
#define lr hope_you_will_be_happy_to_see_this
#define int long long
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const int m1 = 998244353;
const int m2 = 1000001011;
const int pr=233;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
const int maxm= 210000;
const int maxn = 110000;
struct edge{
    int w,to,nxt;
}eg[maxm];
int head[maxn];
int ecnt=0;
inline void add(int u,int v,int w){
    eg[++ecnt].nxt=head[u];
    eg[ecnt].w=w;
    eg[ecnt].to=v;
    head[u]=ecnt;
}
int n;
inline void cl(int n){
    for(int i=0;i<=n;i++)
        head[i]=0;
    ecnt=0;
}
int dis[maxn];
void dij(int a){
    for(int i=1;i<=n;i++)  
        dis[i]=llinf;
    dis[a]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>q;//小根pair堆
    //queue<pair<int,int>>q; 
    q.push(pair<int,int>(0,a));
    while(!q.empty()){
        pair<int,int> t=q.top();
        q.pop();
        if(dis[t.second]<t.first)
            continue;//如果已经松弛过了就没必要继续扩展
        for(int i=head[t.second];i;i = eg[i].nxt){
            int& to=eg[i].to;
            if(eg[i].w+dis[t.second]<dis[to]){
                dis[to]=eg[i].w+dis[t.second];//如果可以松弛就进行松弛
                q.push(make_pair(dis[to],to));//将修改入队
            }
        }
    }
}
void work()
{
    int m,s;
    rd(n),rd(m),rd(s);
    cl(n);
    int u,v,w;
    for(int i=1;i<=m;i++){
        rd(u),rd(v),rd(w);
        add(u,v,w);
      //  add(v,u,w);
    }
    dij(s);
    for(int i=1;i<=n;i++){
        wt(dis[i]),putchar(' ');
    }
    putchar('\n');
}
signed main()
{
   #ifndef ONLINE_JUDGE
   freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
#endif
int t = 1;
rd(t);
//cin>>t;
while (t--)
{
work();
}
return 0;
}