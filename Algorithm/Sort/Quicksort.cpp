#include<iostream>
#include<algorithm>
#define MAX_N 100000
using namespace std;
int main(){
	int n;
	int a[MAX_N];
	cin>>n;
	for (int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	for (int i=0;i<n;i++)
		cout<<a[i]<<(i==n-1?"\n":" ");
}
