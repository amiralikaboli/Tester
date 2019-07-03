#include<bits/stdc++.h>

using namespace std;

const int MaxN=10*1000+10;
int ps[MaxN];

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    s=" "+s;
    for (int i=1;i<s.size();++i)
        if (s[i]=='1')
            ps[i]=ps[i-1]+1;
        else
            ps[i]=ps[i-1]-1;
    int mx=0;
    for (int i=1;i<s.size();++i)
        for (int j=i;j<s.size();++j)
            if (ps[j]==ps[i-1])
                mx=max(mx,j-i+1);
    cout << mx;
}