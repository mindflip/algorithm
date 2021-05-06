#include <iostream>
#include <cstdlib>
#include <time.h>
#define SIZE 30000
// execution time �� 30000�� ����

using namespace std;

int arr[SIZE + 1];
bool visit[SIZE + 1];

// quick sort start

void quickSort(int* arr, int start, int end) {
	if (start >= end) return;

	int pivot = start;
	int i = pivot + 1;
	int j = end;
	int temp;

	while (i <= j) {
		while (i <= end && arr[i] <= arr[pivot]) {
			i++;
		}

		while (j > start && arr[j] >= arr[pivot]) {
			j--;
		}

		if (i > j) {
			temp = arr[j];
			arr[j] = arr[pivot];
			arr[pivot] = temp;
		}
		else {
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}

	/*
	cout << "pivot : " << pivot << " : ";
	for (int i = 0; i < SIZE; ++i) {
		cout << arr[i] << " ";
	}
	cout << " / j : " << j << "\n";
	*/
	quickSort(arr, start, j - 1);
	quickSort(arr, j + 1, end);
}

// quick sort end

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
	cout << "### Quick Sort ###\n";

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


	quickSort(arr, 0, SIZE - 1);


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

// Time Complexity
// �־��� ���(Worst cases) : T(n) = O(n^2)		 �����ϰ��� �ϴ� �迭�� �������� ���ĵǾ��ְų� �������� ���ĵǾ��ִ� ���
// ����� ���(Average cases) : T(n) = O(nlog��n)

// Space Complexity : O(n)
// Execution Time (sec) : 0.00500


/*

Quick Sort�� ���� ����(divide and conquer) ��� �� ���� �־��� �迭�� �����Ѵ�.
* [���� ����(divide and conquer) ���]
������ ���� 2���� ������ �и��ϰ� ������ �ذ��� ����, ����� ��Ƽ� ������ ������ �ذ��ϴ� �����̴�.
Quick Sort�� �Ҿ��� ���Ŀ� ���ϸ�, �ٸ� ���ҿ��� �񱳸����� ������ �����ϴ� �� ���Ŀ� ���Ѵ�. ���� Merge Sort�� �޸� Quick Sort�� �迭�� ��յ��ϰ� �����Ѵ�.



#����
���ʿ��� �������� �̵��� ���̰� �� �Ÿ��� �����͸� ��ȯ�� �Ӹ� �ƴ϶�, �� �� ������ �ǹ����� ���� ���꿡�� ���ܵǴ� Ư�� ������, �ð� ���⵵�� O(nlog��n)�� ������ �ٸ� ���� �˰���� ������ ���� ���� ������.
�����ϰ��� �ϴ� �迭 �ȿ��� ��ȯ�ϴ� ����̹Ƿ�, �ٸ� �޸� ������ �ʿ�� ���� �ʴ´�.

#����
�Ҿ��� ����(Unstable Sort) �̴�.
���ĵ� �迭�� ���ؼ��� Quick Sort�� �ұ��� ���ҿ� ���� ������ ����ð��� �� ���� �ɸ���.


*/