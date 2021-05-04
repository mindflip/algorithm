#include <iostream>
#include <cstdlib>
#include <time.h>
#define SIZE 30000
// execution time 은 30000개 기준

using namespace std;

int arr[SIZE + 1];
int sorted [SIZE + 1];	// merge sort 에는 정렬된 값을 저장할 배열이 하나 더 필요함
bool visit[SIZE + 1];

// merge sort start

void merge(int* arr, int start, int mid, int end) {
	int i = start;
	int j = mid + 1;
	int k = start;

	while (i <= mid && j <= end) {
		if (arr[i] <= arr[j]) {
			sorted[k++] = arr[i++];
		}
		else {
			sorted[k++] = arr[j++];
		}
	}

	// 아직 안 넣은 값 마저 넣어주기
	if (i > mid) {
		for (int t = j; t <= end; ++t) {
			sorted[k++] = arr[t];
		}
	}
	else {
		for (int t = i; t <= mid; ++t) {
			sorted[k++] = arr[t];
		}
	}

	for (int t = start; t <= end; ++t) {
		arr[t] = sorted[t];
	}

	/*
	cout << "start : " << start << " / mid : " << mid << " / end : " << end << "  /  ";
	for (int i = 0; i < SIZE; ++i) {
		cout << arr[i] << " ";
	}
	cout << "\n";
	*/
}

void mergeSort(int* arr, int start, int end) {
	if (start >= end) return;
	int mid = (start + end) / 2;
	mergeSort(arr, start, mid);
	mergeSort(arr, mid + 1, end);
	merge(arr, start, mid, end);
}

// merge sort end

int main() {
	srand((unsigned)time(0));

	for (int i = 0; i < SIZE; ++i) {
		while (true) {
			int randNum = rand() % SIZE + 1;
			if (!visit[randNum]) {
				visit[randNum] = true;
				arr[i] = randNum;
				break;
			}
		}
	}
	cout << "### Merge Sort ###\n";

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


	mergeSort(arr, 0, SIZE - 1);


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

// Time Complexity : O(nlogn)
// Space Complexity : O(2n)
// Execution Time (sec) : 0.00700


/*

요소를 쪼갠 후, 다시 합병시키면서 정렬해나가는 방식으로, 쪼개는 방식은 퀵정렬과 유사
안정 정렬


*/