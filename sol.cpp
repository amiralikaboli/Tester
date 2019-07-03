#include<bits/stdc++.h>

using namespace std;

const int MaxN=10*1000+10;
int ps[MaxN];

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i=0;i<n;++i){
        if (s[i]=='1')
            ps[i+1]=ps[i]+1;
        else
            ps[i+1]=ps[i]-1;
    }
    int mxlen=0;
    for (int i=0;i<n;++i)
        for (int j=i;j<=n;++j)
            if (ps[i]==ps[j])
                mxlen=max(mxlen,j-i);
    cout << mxlen << endl;
}