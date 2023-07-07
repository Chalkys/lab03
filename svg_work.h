#ifndef SVG_WORK_H_INCLUDED
#define SVG_WORK_H_INCLUDED
#include<iostream>
#include<string>
#include<vector>
#include <algorithm>

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

#endif // SVG_WORK_H_INCLUDED
