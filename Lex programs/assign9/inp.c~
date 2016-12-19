#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000+5;
int A[maxn], tree[4 * maxn];

// build the tree 
void buildTree(int node, int l, int r){
   /* if node is leaf node */
	if(l == r){
		tree[node] = A[l];
		return;
	}
	int mid = (l+r)>>1;
	/* recursively build left and right subtrees */
	buildTree(2*node,l,mid);
	buildTree(2*node+1,mid+1,r);
	tree[node] = tree[2*node]+tree[2*node+1];
}

// function for queries in the range [ql,qr] inclusive
int query(int node,int l,int r,int ql,int qr){
   /* no overlap */
	if(ql>r || qr<l) return INT_MAX;
	/* total overlap */
	if(ql<=l && r<=qr) return tree[node];
	/* partial overlap */
	int mid=(l+r)>>1;
	int q1=query(2*node,l,mid,ql,qr);
	int q2=query(2*node+1,mid+1,r,ql,qr);
	return q1+q2;
}
// Driver program 
int main(){
	ios::sync_with_stdio(0);

	int n,a,b,k=0;
	cout<<"Enter the no of elements :";
	cin>>n;
	cout<<"\nEnter the elements :\n";
	for(int i=0;i<n;i++) cin>>A[i];
	int l= (int)(2*pow(2.0,floor(log((double)n)/log(2.0) +1)));

	buildTree(1,0,n-1);
	
	do{
		cout<<"\nEnter the range :";
		cin>>a>>b;
		int ans = query(1,0,n-1,a+1,b+1);
		cout<<ans<<endl;
		k++;
	}while(k!=5);
	
	return 0;
}


