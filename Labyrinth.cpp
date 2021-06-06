#include <bits/stdc++.h>
using namespace std;

#define     mod             1000000007
#define     MOD             998244353
#define     ll              long long
#define     mp              make_pair
#define     pb              emplace_back
#define     pf              emplace_front
#define     all(p)          p.begin(), p.end()
#define     rep(i,a,b)      for(int i=a;i<b;++i)
#define     repr(i,a,b)     for(int i=a;i>=b;i--)
#define     up              upper_bound
#define     lb              lower_bound
#define     t()             int test;cin>>test;while(test--)
#define     setbits(x)      __builtin_popcountll(x)
#define     si              set<int>
#define     pi              pair<int,int>
#define     vi              vector<ll> 
#define     msi             map<string,int>
#define     que_max         priority_queue <int>
#define     que_min         priority_queue <int, vi, greater<int> >
#define     ithBit(S, j)    (S & (1 << j))
#define     setBit(S, j)    (S |= (1 << j))
#define     clearBit(S, j)  (S &= ~(1 << j))
#define     toggleBit(S, j) (S ^= (1 << j))
#define     lowBit(S)       (S & (-S))
#define     setAll(S, n)    (S = (1 << n) - 1)
#define     isPowerOfTwo(S) (!(S & (S - 1)))
#define     nearestPowerOfTwo(S) ((int)pow(2.0, (int)((log((double)S) / log(2.0)) + 0.5)))
#define     turnOffLastBit(S) ((S) & (S - 1))
#define     turnOnLastZero(S) ((S) | (S + 1))
#define     turnOffLastConsecutiveBits(S) ((S) & (S + 1))
#define     turnOnLastConsecutiveZeroes(S) ((S) | (S - 1))
#define     IOS             ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define     getarray(n)     vector<int> arr(n); for (ll i = 0; i < n; i++) cin >> arr[i];
#define     endl            "\n"
#define     INF 2000000000 // 2 billion 

// If you need to recall how to use memset: 
#define    MEMSET_INF 127 // about 2B 
#define    MEMSET_HALF_INF 63 // about 1B 

// priority_queue<int>pq;   ---> max heap
// priority_queue<int,vector<int>,greater<int>> ---> min heap
/* Disjoint set Data structure
int find(int parent[], int i)
{    if (parent[i] == -1) return i;return find(parent, parent[i]); }
 void Union(int parent[], int x, int y)  parent[x] = y;
*/
// memset(dist, MEMSET_INF, sizeof dist); // useful to initialize shortest path distances 
// memset(dp_memo, -1, sizeof dp_memo); // useful to initialize DP memoization table 
// memset(arr, 0, sizeof arr); // useful to clear array of integers 
#define trav(a,x) for(auto &a:x)
#define TRvi(c, it) for(vi::iterator it = (c).begin(); it != (c).end(); it++) 
 
#define TRvii(c, it) for(vii::iterator it = (c).begin(); it != (c).end(); it++) 
 
#define TRmsi(c, it) for(msi::iterator it = (c).begin(); it != (c).end(); it++)


#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cout << name << " : " << arg1 << endl;
        //use cerr if u want to display at the bottom
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ','); cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
    }
#else
#define trace(...)
#endif

const int N = 2e5 + 5;
vector<vector<bool>>vis;
vector<vector<pi>>path;
int n,m;
int sx,sy,ex,ey;
vector<pi>moves={{-1,0},{1,0},{0,-1},{0,1}};
bool isValid(int x,int y)
{
	if(x<0 || x>=n || y<0 || y>=m)
	{
		return false;
	}
	if(vis[x][y]) return false;
	return true;
}
void bfs()
{
	queue<pi>q;
	q.push(mp(sx,sy));
	while (!q.empty())
	{
		/* code */
		int cx=q.front().first;
		int cy=q.front().second;
		q.pop();
		for(auto x:moves)
		{
			int mvx=x.first;
			int mvy=x.second;
			if(isValid(cx+mvx,cy+mvy))
			{
				vis[cx+mvx][cy+mvy]=true;
				path[cx+mvx][cy+mvy]={mvx,mvy};
				q.push(mp(cx+mvx,cy+mvy));
			}
		}
	}
	
}
void solve()
{
    // code begins
	cin >> n >>m;
	char c;
	path.resize(n);
	vis.resize(n);
	for(int i = 0; i < n; ++i)
	{
		path[i].resize(m);
		vis[i].resize(m);
	}
	rep(i,0,n)
	{
		rep(j,0,m)
		{
			path[i][j] = {-1,-1};
			cin >> c;
			if(c=='#') 
			{
				vis[i][j]=true;
			}
			if(c=='A')
			{
				sx=i;sy=j;
			}
			if(c=='B')
			{
				ex=i;ey=j;
			}
		}
	}
	bfs();
	//cout << "aple" << endl;
	if(!vis[ex][ey])
	{
		cout << "NO" << endl;return;
	}
	cout << "YES" << endl;
	vector<pi>ans;
	pi end={ex,ey};
	/*
	while(end.first!=sx && end.second!=sy)
	{
		ans.push_back(path[end.first][end.second]);
		end.first-=ans.back().first;
		end.second-=ans.back().second;
		
	}
	*/
    while(end.first != sx || end.second != sy)
	{
		ans.push_back(path[end.first][end.second]);
		end.first -= ans.back().first;
		end.second -= ans.back().second;	
	}
	cout << ans.size() << endl;
	reverse(all(ans));
	trav(x,ans)
	{
		if(x.first==1 && x.second==0)
		{
			cout << "D" ;
		}
		if(x.first==-1 && x.second==0)
		{
			cout << "U" ;
		}
		if(x.first==0 && x.second==1)
		{
			cout << "R" ;
		}
		if(x.first==0 && x.second==-1)
		{
			cout << "L" ;
		}
	}
    return;
}
signed main(){
	IOS;
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#ifdef SIEVE
		sieve();
	#endif
	#ifdef NCR
		init();
	#endif
    // Add test case
	solve();
	return 0;
}
