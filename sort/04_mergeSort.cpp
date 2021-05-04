#include <iostream>
#include <cstdlib>
#include <time.h>
#define SIZE 30000
// execution time �� 30000�� ����

using namespace std;

int arr[SIZE + 1];
int sorted [SIZE + 1];	// merge sort ���� ���ĵ� ���� ������ �迭�� �ϳ� �� �ʿ���
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

	// ���� �� ���� �� ���� �־��ֱ�
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

��Ҹ� �ɰ� ��, �ٽ� �պ���Ű�鼭 �����س����� �������, �ɰ��� ����� �����İ� ����
���� ����


*/