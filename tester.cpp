#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define F first
#define S second
#define pii pair<int,int>
#define pi acos(-1)
#define X real()
#define Y imag()
#define point complex<ld>

const int MaxTime=1;
vector <int> wr,tl;

string int_to_string(int n){
	int x=n;
	string s;
	while (x!=0){
		s+='0'+x%10;
		x/=10;
	}
	reverse(s.begin(),s.end());
	return s;
}

double time(int n){
	return 1.0*n/CLOCKS_PER_SEC;
}

main(){
	int n;
	cin >> n;
	system("g++ -std=c++11 gen.cpp -o gen.exe");
	system("g++ -std=c++11 sol.cpp -o sol.exe");
	system("g++ -std=c++11 code.cpp -o code.exe");
	for (int i=0;i<n;++i){
		string num=int_to_string(i+1);
		string g="gen.exe > in#"+num+".txt";
		system(g.c_str());
		string s="sol.exe < in#"+num+".txt > out_sol#"+num+".txt";
		system(s.c_str());
		int t=clock();
		string c="code.exe < in#"+num+".txt>out_code#"+num+".txt";
		t=clock()-t;
		system(c.c_str());
		if (time(t)>MaxTime){
			tl.pb(i+1);
			cout << "Test #" << i+1 << " : Time Limit" << endl;
			continue;
		}
		string a="out_sol#"+num+".txt";
		string b="out_code#"+num+".txt";
		ifstream solin(a.c_str());
		ifstream codin(b.c_str());
		bool h=true;
		string in_s="",in_c="";
		cout << "Test #" << i+1 << " : ";
		while (solin >> in_s){
			codin >> in_c;
			if (in_s=="" || in_c==""){
				h=false;
				cout << "Wrong" << endl;
				cout << "Code:" << in_c << "\nSolution:" << in_s << endl << endl;
				wr.pb(i+1);
				break;
			}
			if (in_s!=in_c){
				h=false;
				cout << "Wrong" << endl;
				cout << "Code:" << in_c << "\nSolution:" << in_s << endl << endl;
				wr.pb(i+1);
				break;
			}
			in_s=in_c="";
		}
		if (h==true)
			cout << "OK\n";
	}
	if (wr.size() || tl.size()){
		if (wr.size()){
			cout << "Wrong Answer :";
			for (int i=0;i<wr.size();++i)
				cout << " #" << wr[i];
		}
		if (tl.size()){
			cout << "Time Limit :";
			for (int i=0;i<tl.size();++i)
				cout << " #" << tl[i];	
		}
		cout << endl << ":(";
	}
	else
		cout << "Accepted :D";
}