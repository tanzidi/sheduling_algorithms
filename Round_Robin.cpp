#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

struct st {
	int id, at, bt, cbt, first_time = 0, ct = 0, fa = 1e9;
};

bool cmp (st a, st b) {
	return a.at < b.at;
}


int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n, quantum; cin >> n >> quantum;
	st data[n];
	int t_bt = 0;
	for (int i = 0; i < n; i++) {
		cin >> data[i].id >> data[i].at >> data[i].bt;
		data[i].cbt = data[i].bt;
		t_bt += data[i].bt;
	}
	sort (data, data + n, cmp);
	int cur = 0;
	cout << data[0].at << " ";
	queue<int> q;
	q.push(0);
	data[0].first_time = 1;
	while (cur != t_bt) {
		int sz = q.size();
		while (sz--) {
			int pos = q.front();
			q.pop();
			data[pos].fa = min(data[pos].fa, cur);
			cur += min(data[pos].cbt, quantum);
			data[pos].ct = max(data[pos].ct, cur);
			data[pos].cbt -= min(data[pos].cbt, quantum);
			cout << "P" << data[pos].id << " " << cur << " ";
			for (int i = 0; i < n; i++) {
				if (data[i].first_time == 0 && data[i].cbt != 0 && data[i].at <= cur) {
					data[i].first_time = 1;
					q.push(i);
				}
			}
			if (data[pos].cbt > 0) q.push(pos);
		}
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