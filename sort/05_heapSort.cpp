#include <iostream>
#include <cstdlib>
#include <time.h>
#define SIZE 30000
// execution time �� 30000�� ����

using namespace std;

int arr[SIZE + 1];
bool visit[SIZE + 1];

// heap sort start

void heapify(int* arr, int n, int i) {
	int p = i;
	int l = i * 2 + 1;
	int r = i * 2 + 2;

	if (l < n && arr[p] < arr[l]) {
		p = l;
	}

	if (r < n && arr[p] < arr[r]) {
		p = r;
	}

	if (i != p) {
		int temp = arr[p];
		arr[p] = arr[i];
		arr[i] = temp;
		heapify(arr, n, p);
	}

}

void heapSort(int* arr) {
	int n = SIZE;

	// max heap �ʱ�ȭ
	for (int i = n / 2 - 1; i >= 0; --i) {
		heapify(arr, n, i);
	}

	// �ִ밪 ����, root���� �� �ڿ� �ְ� �ٽ� heap ����
	for (int i = n - 1; i > 0; --i) {
		int temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		heapify(arr, i, 0);
	}
}

// heap sort end

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
	cout << "### Heap Sort ###\n";

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


	heapSort(arr);	// ó�� ���� ����


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
// Space Complexity : O(n)
// Execution Time (sec) : 0.01400


/*

�ִ� ���� ����
���� �� ��Ʈ�� ���� ū ���� ������. ��Ʈ�� ���� ������ ��ҿ� �ٲ� ��, ���� ������ �ϳ� ����
���� ����� 1���� ũ�� �� ���� �ݺ�

�Ҿ��� ����

*/