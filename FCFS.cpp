#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

struct st {
	int id, at, bt, ct = 0, fa = 1e9;
};

bool cmp (st a, st b) {
	return a.at < b.at;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  	
	int n; cin >> n;
	st data[n];
	for (int i = 0; i < n; i++) {
		cin >> data[i].id >> data[i].at >> data[i].bt;
	}
	sort (data, data + n, cmp);
	int cur = data[0].at + data[0].bt;

	data[0].ct = max(data[0].ct, cur);
	data[0].fa = min(data[0].fa, data[0].at);

	for (int i = 1; i < n; i++) {
		data[i].fa = min(data[i].fa, cur);
		cur += data[i].bt;
		data[i].ct = max(data[i].ct, cur);
	}
	cout << "PN\tAT\tBT\tCT\tTAT\tWT\tRT\n";
	
	for (int i = 0; i < n; i++) {
		int tat = data[i].ct - data[i].at;
		int wt = tat - data[i].bt;
		int rt = data[i].fa - data[i].at;
		cout << "P" << data[i].id << "\t" << data[i].at << "\t" << data[i].bt << "\t" << data[i].ct << "\t" << tat << "\t" << wt << "\t" << rt << "\n";
	}
}	