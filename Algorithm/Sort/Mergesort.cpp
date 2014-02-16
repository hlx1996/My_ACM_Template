#include<iostream>
#include<vector>
using namespace std;
void mergesort(vector<int> &a,int s,int t){
	if (s==t) return;
	mergesort(a,s,(s+t)/2);
	mergesort(a,(s+t)/2+1,t);
	int i=s,j=(s+t)/2+1;
	vector<int> b;
	for (int k=s;k<=t;k++)
		if (j>t || a[i]<a[j]) 
			b.push_back(a[i++]);
		else b.push_back(a[j++]);
	for (int k=s;k<=t;k++)
		a[k]=b[k-s];
}
int main(){
	int n,x;
	vector<int> a;
	cin>>n;
	for (int i=0;i<n;i++)
		cin>>x,a.push_back(x);
	mergesort(a,0,n-1);
	for (int i=0;i<n;i++)
		cout<<a[i]<<' ';
	cout<<endl;
}
