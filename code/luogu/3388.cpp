#include <bits/stdc++.h>
using namespace std;
#pragma optimize(2)
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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
#define MP make_pair
#define pb push_back
#define pt putchar
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
const ll llinf = 4223372036854775807;
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const int m1 = 998244353;
const int m2 = 1000001011;
const int pr=233;
const double eps = 1e-7;
const int maxm= 2100000;
const int maxn = 210000;
int dfn[maxn],low[maxn];
bool isge[maxn];
int cnt=0;
struct edge{
   int to,nxt;
}eg[maxm];+int head[maxn];
int ecnt=0;
inline void add(int u,int v){
   eg[++ecnt].nxt=head[u];
   eg[ecnt].to=v;
   head[u]=ecnt;
}
inline void cl(int n){
    for(int i=0;i<=n;i++)
        head[i]=-1;
    ecnt=-1;
}
int n,m;
int crd;
void tarjan(int now,int fa){
    int crd=0;
    dfn[now]=low[now]=++cnt;
    for(int i=head[now];i!=-1;i=eg[i].nxt){
        int to=eg[i].to;
        if(!dfn[to]){
            tarjan(to,i^1);
            if(low[to]>dfn[now]&&fa!=-1)
                isge[now]=1;
            else if(fa==-1){
                crd++;
            }
            MIN(low[now],low[to]);
        }else if(i!=fa){
            MIN(low[now],dfn[to]);
        }
    }
    if(crd>=2&&fa==-1)
        isge[now]=1;
}
void work()
{
    rd(n),rd(m);
    int u,v;
    cl(n);
    for(int i=0;i<m;i++){
        rd(u),rd(v);
        add(u,v),add(v,u);
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i]){
            tarjan(i,-1);
        }
    }
    vector<int> ans;
    for(int i=1;i<=n;i++){
        if(isge[i])
            ans.push_back(i);
    }
    wt(ans.size()),pt('\n');
    for(int i=0;i<ans.size();i++){
        wt(ans[i]),pt(' ');
    }
    pt('\n');
}
signed main()
{
   #ifndef ONLINE_JUDGE
   freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
#endif
//std::ios::sync_with_stdio(false);
//cin.tie(NULL);
int t = 1;
//cin>>t;
while (t--)
{
work();
}
return 0;
}