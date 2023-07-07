#ifndef MODUL-TEST_H_INCLUDED
#define MODUL-TEST_H_INCLUDED

#include <vector>

using namespace std;

size_t max_min(vector<size_t> v1, int m) {
    if (v1.size() == 0) {
        return 0;
    }

	size_t min = v1[0], max = v1[0];

	for (int i = 1; i < v1.size(); i++) {
		if (v1[i] < min) {
			min = v1[i];
		}
		if (v1[i] > max) {
			max = v1[i];
		}
	}

	if (m == 0) {
		return min;
	}
	else if (m == 1)
		return max;
}

#endif // MODUL-TEST_H_INCLUDED
