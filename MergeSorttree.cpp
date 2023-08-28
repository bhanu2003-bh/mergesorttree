#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
 #define int long long


template<class T> using ordered_set = tree<T , null_type, less<T> , rb_tree_tag , tree_order_statistics_node_update>;
 
class segtree{
int n;
vector<int>tree[1001];
vector<int>arr;

public:

segtree(vector<int>&brr){
n = brr.size();
arr = brr;
}




void build(int node,int strt,int end){
if(strt==end){
   tree[node].push_back(arr[strt]);
    return;
}

int mid = (strt+end)/2;

build(2*node,strt,mid);
build(2*node+1,mid+1,end);

//operation
int i = 0;
int j = 0;
while (i<tree[2*node].size() && j<tree[2*node+1].size())
{
    if(tree[2*node][i]>tree[2*node+1][j]){
        tree[node].push_back(tree[2*node+1][j]);
        j++;
    }
    else{
      tree[node].push_back(tree[2*node][i]);
      i++;
    }

}

while (i<tree[2*node].size())
{
     tree[node].push_back(tree[2*node][i]);
      i++;
}

while (j<tree[2*node+1].size())
{
        tree[node].push_back(tree[2*node+1][j]);
        j++;
}


return;
}


int query(int node,int strt,int end,int l,int r,int k){
    if(strt>r || end<l) return 0;
    else if(strt>=l && r>=end) {
    int ans = upper_bound(tree[node].begin(),tree[node].end(),k-1)-tree[node].begin();
    return ans;
    }
    else{
        int mid = (strt+end)/2;
        int left = query(2*node,strt,mid,l,r,k);
        int right = query(2*node+1,mid+1,end,l,r,k);
        return left+right;
    }
}

};


void solve(){






}
 
signed main(){
solve();
}