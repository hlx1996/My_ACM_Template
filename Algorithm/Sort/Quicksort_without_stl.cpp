#include<iostream>
#include<cstdlib>
#include<vector>
#define MAX_N 100000
using namespace std;
inline int random(int x){
	return (int)((double)rand()/RAND_MAX*x);
}
inline void swap(int &x,int &y){
	int t=x; x=y; y=t;
}
void quicksort(vector<int> &a,int s,int t){
	int i=s,j=t,u=a[random(t-s+1)+s];
	while (i<=j){
		while (a[i]<u) i++;
		while (a[j]>u) j--;
		if (i<=j) swap(a[i],a[j]),i++,j--;
	}
	if (s<j) quicksort(a,s,j);
	if (i<t) quicksort(a,i,t);
}
int main(){
	int n,x;
	cin>>n;
	vector<int> a;
	for (int i=0;i<n;i++){
		cin>>x;
		a.push_back(x);
	}
	quicksort(a,0,a.size()-1);
	for (int i=0;i<n;i++)
		cout<<a[i]<<' ';
	cout<<endl;
}
