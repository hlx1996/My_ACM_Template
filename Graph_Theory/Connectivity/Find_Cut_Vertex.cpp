//割点：{v∈V | G'=<V-v,E-(v,*)> 不连通}
//求割点：顶点u是割点的充要条件是u满足下面两个条件之一：
//u是至少有两个子女的深度优先生成树的根;
//u不是根，但它有一个子女v，使得dfn[u]<=low[v]。
//其中dfn[u]表示深度优先搜索顶点u的访问次序；
//   low[u]表示从u或u的子孙出发通过回边可以到达的最小的访问次序.
//练习：POJ1144<裸题>
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
int n,m,tot,ee,degree,ii;
vb_array d;
eb_array v;
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
				if (u==ii) degree++;
				dfs(e[i]);
				low[u]=min(low[u],low[e[i]]);
			}
			if (dfn[u]<=low[e[i]]) d[u]=true;
			else low[u]=min(low[u],dfn[e[i]]);
		}
}
int main(){
	int x,y;
	cin>>n>>m; ee=degree=0;
	memset(dfn,255,sizeof(dfn));
	memset(point,255,sizeof(point));
	memset(d,0,sizeof(d));
	memset(v,0,sizeof(v));
	for (int i=0;i<m;i++){
		cin>>x>>y;
		build(x,y);
	}
	for (ii=1;ii<=n;ii++)
		if (dfn[ii]==-1){
			degree=0; dfs(ii);
			d[ii]=(degree>1);
		}
	for (int i=1;i<=n;i++)
		if (d[i]){
			cout<<i<<' ';
		}
	cout<<endl;
}
