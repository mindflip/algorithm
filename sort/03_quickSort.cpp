#include <iostream>
#include <cstdlib>
#include <time.h>
#define SIZE 30000
// execution time 은 30000개 기준

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
// 최선의 경우(Best cases) : T(n) = O(nlog₂n)
// 최악의 경우(Worst cases) : T(n) = O(n^2)		 정렬하고자 하는 배열이 오름차순 정렬되어있거나 내림차순 정렬되어있는 경우
// 평균의 경우(Average cases) : T(n) = O(nlog₂n)
// 
// 모두 정렬이 되어있는 경우(Optimal)한 경우, 한번씩 밖에 비교를 안하므로 O(n) 의 시간복잡도를 가지게 된다.
// 또한, 이미 정렬되어 있는 배열에 자료를 하나씩 삽입/제거하는 경우에는, 현실적으로 최고의 정렬 알고리즘이 되는데, 탐색을 제외한 오버헤드가 매우 적기 때문이다.
// Space Complexity : O(n)
// Execution Time (sec) : 0.00500


/*

Quick Sort은 분할 정복(divide and conquer) 방법 을 통해 주어진 배열을 정렬한다.
* [분할 정복(divide and conquer) 방법]
문제를 작은 2개의 문제로 분리하고 각각을 해결한 다음, 결과를 모아서 원래의 문제를 해결하는 전략이다.
Quick Sort은 불안정 정렬에 속하며, 다른 원소와의 비교만으로 정렬을 수행하는 비교 정렬에 속한다. 또한 Merge Sort와 달리 Quick Sort는 배열을 비균등하게 분할한다.



#장점
불필요한 데이터의 이동을 줄이고 먼 거리의 데이터를 교환할 뿐만 아니라, 한 번 결정된 피벗들이 추후 연산에서 제외되는 특성 때문에, 시간 복잡도가 O(nlog₂n)를 가지는 다른 정렬 알고리즘과 비교했을 때도 가장 빠르다.
정렬하고자 하는 배열 안에서 교환하는 방식이므로, 다른 메모리 공간을 필요로 하지 않는다.

#단점
불안정 정렬(Unstable Sort) 이다.
정렬된 배열에 대해서는 Quick Sort의 불균형 분할에 의해 오히려 수행시간이 더 많이 걸린다.


*/