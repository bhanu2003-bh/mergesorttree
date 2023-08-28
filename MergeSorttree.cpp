#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
 #define int long long


template<class T> using ordered_set = tree<T , null_type, less<T> , rb_tree_tag , tree_order_statistics_node_update>;
 

struct seg
{

  vector<ll>mp;
seg(){}
seg(ll data){
   mp.push_back(data);
}
};

class segtree{
int n;
vector<seg>tree;
vector<ll>arr;

public:

segtree(vector<ll>brr){
n = brr.size();
tree.resize(4*n+1);
arr = brr;
}


seg op(seg&a,seg&b){
 seg ans;
int i = 0;
int j = 0;
while (i<a.mp.size() && j<b.mp.size())
{
   if(a.mp[i]<b.mp[j]){
      ans.mp.push_back(a.mp[i]);
      i++;
   }
   else{
      ans.mp.push_back(b.mp[j]);
      j++;
   }
}
while (i<a.mp.size())
{
   ans.mp.push_back(a.mp[i]);
   i++;
}
while (j<b.mp.size())
{
   ans.mp.push_back(b.mp[j]);
   j++;
}

return ans;
}



void build(int node,int strt,int end){
if(strt==end){
    tree[node] = seg(arr[strt]);
    return;
}

int mid = (strt+end)/2;

build(2*node,strt,mid);
build(2*node+1,mid+1,end);

//operation
tree[node] = op(tree[2*node] , tree[2*node+1]);
}

ll query(int node,int strt,int end,int l,int r,ll tar){
    if(strt>r || end<l) return 0LL;
    else if(strt>=l && r>=end) {
      ll val = (lower_bound(tree[node].mp.begin(),tree[node].mp.end(),tar)-tree[node].mp.begin());
     return val;
    }
    else{
        int mid = (strt+end)/2;
        ll left = query(2*node,strt,mid,l,r,tar);
        ll right = query(2*node+1,mid+1,end,l,r,tar);
       
        return (left+right)*1LL;
       
    }
}

};


signed main(){
solve();
}
