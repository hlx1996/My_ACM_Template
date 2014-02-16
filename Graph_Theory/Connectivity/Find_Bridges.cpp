//桥：{e∈E | G'=<V,E-e> 不连通}
//求桥：边w=<u,v>是桥的充要条件是w满足dfn[u]<low[v]
//其中dfn[u]表示深度优先搜索顶点u的访问次序；
//   low[u]表示从u或u的子孙出发通过回边可以到达的最小的访问次序。
#include<iostream>
#include<algorithm>
#include<cstring>
#define MAX_M 100000
#define MAX_N 10001
using namespace std;
typedef int v_array[MAX_N];
typedef int e_array[MAX_M];
typedef bool vb_array[MAX_N];
typedef bool eb_array[MAX_M];

e_array next,e;
v_array point,dfn,low;
int n,m,tot,ee;
eb_array v,d;
void build(int u,int v){
	e[ee]=v; next[ee]=point[u]; point[u]=ee; ee++;
	e[ee]=u; next[ee]=point[v]; point[v]=ee; ee++;
}
void dfs(int u){
	low[u]=dfn[u]=tot++;
	for (int i=point[u];i!=-1;i=next[i])
		if (!v[i]) {
			v[i]=v[i^1]=true;
			if (dfn[e[i]]==-1) {
				dfs(e[i]);
				low[u]=min(low[u],low[e[i]]);
			}
			if (dfn[u]<low[e[i]]) d[i]=d[i^1]=true;
			else low[u]=min(low[u],dfn[e[i]]);
		}
}
int main(){
	int x,y;
	cin>>n>>m; ee=0;
	memset(dfn,255,sizeof(dfn));
	memset(point,255,sizeof(point));
	memset(d,0,sizeof(d));
	memset(v,0,sizeof(v));
	for (int i=0;i<m;i++){
		cin>>x>>y;
		build(x,y);
	}
	for (int i=1;i<=n;i++)
		if (dfn[i]==-1)
			dfs(i);
	for (int i=0;i<m;i++)
		if (d[i<<1]){
			cout<<i<<' ';
		}
	cout<<endl;
}
