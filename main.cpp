#include<bits/stdc++.h>
using namespace std;
int main() {
    int m,n;
    cin>>m;
    vector<int> v(m);
    for(int i=0;i<m;i++) {
        cin>>v[i];
    }
    cin>>n;
    vector<int> v1(n);
    for(int i=0;i<n;i++) {
        cin>>v1[i];
    }
    int count=0;
    sort(v1.begin(),v1.end());
    sort(v.begin(),v.end());
    int child=0,cookie=0;
    while (child<v.size()&&cookie<v1.size()) {
        if (v[child]<=v1[cookie]) {
            child++;
        }
        cookie++;
    }
    cout<<child<<endl;
}