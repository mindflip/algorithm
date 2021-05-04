#include <iostream>
#include <cstdlib>
#include <time.h>
#define SIZE 30000
using namespace std;

int arr[SIZE + 1];
bool visit[SIZE + 1];

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
	cout << "### Selection Sort ###\n";

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

	int idxMin, temp;
	for (int i = 0; i < SIZE - 1; ++i) {
		idxMin = i;
		for (int j = i + 1; j < SIZE; ++j) {
			if (arr[j] < arr[idxMin]) {
				idxMin = j;
			}
		}

		temp = arr[idxMin];
		arr[idxMin] = arr[i];
		arr[i] = temp;
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

// Time Complexity : O(n^2)
// Space Complexity : O(n)
// Execution Time (sec) : 0.9170000000


/*

Selection Sort는 Bubble Sort과 유사한 알고리즘으로, 해당 순서에 원소를 넣을 위치는 이미 정해져 있고, 어떤 원소를 넣을지 선택하는 알고리즘이다.
Selection Sort와 Insertion Sort를 헷갈려하는 사람들이 종종 있는데, Selection Sort는 배열에서 해당 자리를 선택하고 그 자리에 오는 값을 찾는 것이라고 생각하면 편하다.

 
#장점
Bubble sort와 마찬가지로 알고리즘이 단순하다.
정렬을 위한 비교 횟수는 많지만, Bubble Sort에 비해 실제로 교환하는 횟수는 적기 때문에 많은 교환이 일어나야 하는 자료상태에서 비교적 효율적이다.
Bubble Sort와 마찬가지로 정렬하고자 하는 배열 안에서 교환하는 방식이므로, 다른 메모리 공간을 필요로 하지 않는다. => 제자리 정렬(in-place sorting)


#단점
시간복잡도가 O(n^2)으로, 비효율적이다.
불안정 정렬(Unstable Sort) 이다.


*/