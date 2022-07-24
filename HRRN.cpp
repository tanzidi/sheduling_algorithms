#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

struct st {
	int id, at, bt, cbt, ct = 0, fa = 1e9;
};

bool cmp (st a, st b) {
	return a.at < b.at;
}

double res_ratio (int cur, int at, int bt) {
	return (double) ((cur - at) + bt) / (double) bt;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n; cin >> n;
	st data[n];
	int t_bt = 0;
	for (int i = 0; i < n; i++) {
		cin >> data[i].id >> data[i].at >> data[i].bt;
		data[i].cbt = data[i].bt;
		t_bt += data[i].bt;
	}
	sort (data, data + n, cmp);
	int cur = data[0].at + data[0].bt;
	cout << data[0].at << " " << "P" << data[0].id << " " << cur << " ";
	data[0].ct = max(data[0].ct, cur);
	data[0].fa = min(data[0].fa, data[0].at);
	while (cur != t_bt) {
		double mx_rr = 0.0;
		int pos = -1;
		for (int i = 1; i < n; i++) {
			double cur_rr = res_ratio (cur, data[i].at, data[i].bt);
			if (data[i].cbt != 0 && data[i].at <= cur && cur_rr > mx_rr) {
				mx_rr = cur_rr;
				pos = i;
			}
		}
		if (pos == -1) break;
		data[pos].cbt = 0;
		data[pos].fa = min(data[pos].fa, cur);
		cur += data[pos].bt;
		data[pos].ct = max(data[pos].ct, cur);
		cout << "P" << data[pos].id << " " << cur << " ";
	}
	cout << "\n\n";
	cout << "PN\tAT\tBT\tCT\tTAT\tWT\tRT\n";
	int t_wt = 0, t_rt = 0;
	for (int i = 0; i < n; i++) {
		int tat = data[i].ct - data[i].at;
		int wt = tat - data[i].bt;
		t_wt += wt;
		int rt = data[i].fa - data[i].at;
		t_rt += rt;
		cout << "P" << data[i].id << "\t" << data[i].at << "\t" << data[i].bt << "\t" << data[i].ct << "\t" << tat << "\t" << wt << "\t" << rt << "\n";
	}
	cout << "\n";
	cout << "Avg. WT : " << (double) t_wt / (double) n << "\n";
	cout << "Avt. RT : " << (double) t_rt / (double) n << "\n";
}	