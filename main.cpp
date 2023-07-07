#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<iomanip>
#include <algorithm>
#include "modul-test.h"
using namespace std;
void svg_rect(double x, double y, double width, double height, string stroke = "blue", string fill = "blue");

void svg_begin(double width, double height) {
	cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
	cout << "<svg ";
	cout << "width='" << width << "' ";
	cout << "height='" << height << "' ";
	cout << "viewBox='0 0 " << width << " " << height << "' ";
	cout << "xmlns='http://www.w3.org/2000/svg'>\n";
}

void svg_end() {
	cout << "</svg>\n";
}

void svg_text(double left, double baseline, string text) {
	cout << "<text x='20' y='35'>anything you want</text>";
}

void show_histogram_svg(const vector<size_t>& bins) {

	const auto IMAGE_WIDTH = 400;
	const auto IMAGE_HEIGHT = 300;
	const auto TEXT_LEFT = 20;
	const auto TEXT_BASELINE = 20;
	const auto TEXT_WIDTH = 50;
	const auto BIN_HEIGHT = 30;
	const auto BLOCK_WIDTH = 10;

	// начало документа
	svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);

	// гистограмма
	double top = 0;
	size_t cnt = 0;
	for (size_t bin = 0; bin < bins.size() - 1; bin++) {
		cnt += bins[bin];

		double bin_width;
		if (bins[bins.size() - 1] > 76) {
			bin_width = BLOCK_WIDTH * (76 * (static_cast<double>(cnt) / bins[bins.size() - 1]));
		}
		else {
			bin_width = BLOCK_WIDTH * cnt;
		}

		svg_text(TEXT_LEFT, top + TEXT_BASELINE, to_string(bin));
		svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT, "red", "#ffeeee");
		top += BIN_HEIGHT;
	}

	// конец документа
	svg_end();
}

void svg_rect(double x, double y, double width, double height, string stroke, string fill) {
	cout << "<rect x='" << x << "' y='" << y << "' width='" << width << "' height='" << height << "' stroke='" << stroke << "' fill='" << fill << "'/>\n";
}

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
