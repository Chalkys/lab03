#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<iomanip>
#include <algorithm>
#include "modul-test.h"
#include "svg_work.h"
using namespace std;

vector<size_t> input1(int n) {
	vector<size_t> bins(n);
	for (int i = 0; i < n; i++) {
		cin >> bins[i];
	}
	return bins;
}


vector<size_t> gist(vector<size_t> v, double bin_count) {

	double diff = (max_min(v, 1) - max_min(v, 0)) / bin_count;


	vector<size_t> fin;
	vector<size_t> check_fin(v.size(), 0);

	bool newF = true;
	size_t new_max = 0;
	bool flag = true;
	for (int i = 0; i < bin_count; i++) {
		int cnt = 0;

		if (flag) {
			for (int j = 0; j < v.size(); j++) {
				if (v[j] >= (max_min(v, 0) + diff * i) && v[j] <= (max_min(v, 0) + diff * (i + 1)) && check_fin[j] == 0) {
					cnt++;
					check_fin[j] = 1;
				}
			}
			if (diff == 0)
				flag = false;
		}
		fin.push_back(cnt);

		if (newF) {
			new_max = cnt;
		}

		if (cnt > new_max)
			new_max = cnt;


	}

	sort(fin.begin(), fin.end());
	vector<size_t> new_fin;
	for (int i = 0; i < fin.size(); i++) {
		if (i == 0) {
			new_fin.push_back(fin[i]);
			//cout << new_fin[i];
		}
		else {
			new_fin.push_back(fin[i] - fin[i - 1]);
			//cout << '-' << new_fin[i];
		}
	}
	//cout << endl;

	new_fin.push_back(new_max);

	return new_fin;
}

int main() {
	setlocale(LC_ALL, "Rus");
	int n;
	double bin_count;

	cin >> n;
	vector<size_t> bins(n);

	bins = input1(n);
	cin >> bin_count;

	vector<size_t> new_fin = gist(bins, bin_count);

	show_histogram_svg(new_fin);
	return 0;
}
