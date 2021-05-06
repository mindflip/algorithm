#include <iostream>
#include <cstdlib>
#include <time.h>
#define SIZE 30000
// execution time 은 30000개 기준

using namespace std;

int arr[SIZE + 1];
int countingArr[SIZE + 1];

int main() {
	srand((unsigned)time(0));

	for (int i = 0; i < SIZE; ++i) {
		int randNum = rand() % SIZE + 1;
		arr[i] = randNum;
	}

	cout << "### Counting Sort ###\n";

	/*
	cout << "*** Unsorted Array ***\n";
	for (int i = 0; i < SIZE; ++i) {
		cout << arr[i] << " ";
	}
	cout << "\n";
	*/

	// Start measuring time
	clock_t start = (double)clock();

	// sort algorithm start

	for (int i = 0; i < SIZE; ++i) {
		countingArr[arr[i]]++;
	}

	int arrSize = 0;
	for (int i = 1; i < SIZE + 1; ++i) {
		if (countingArr[i] == 0) continue;
		int cnt = countingArr[i];
		while (cnt--) {
			arr[arrSize++] = i;
		}
	}

	// sort algorithm end

	clock_t end = (double)clock();
	double elapsed = double(end - start) / CLOCKS_PER_SEC;

	/*
	cout << "*** Sorted Array *** \n";
	for (int i = 0; i < SIZE; ++i) {
		cout << arr[i] << " ";
	}
	cout << "\n";
	*/

	printf("Time measured: %.5f seconds.\n", elapsed);
}

// Time Complexity : O(n)
