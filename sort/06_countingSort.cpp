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

// Time Complexity : O(n^2)
// 모두 정렬이 되어있는 경우(Optimal)한 경우, 한번씩 밖에 비교를 안하므로 O(n) 의 시간복잡도를 가지게 된다.
// 또한, 이미 정렬되어 있는 배열에 자료를 하나씩 삽입/제거하는 경우에는, 현실적으로 최고의 정렬 알고리즘이 되는데, 탐색을 제외한 오버헤드가 매우 적기 때문이다.
// Space Complexity : O(n)
// Execution Time (sec) : 0.42800


/*

손 안의 카드를 정렬하는 방법과 유사하다.
Insertion Sort는 Selection Sort와 유사하지만, 좀 더 효율적인 정렬 알고리즘이다.
Insertion Sort는 2번째 원소부터 시작하여 그 앞(왼쪽)의 원소들과 비교하여 삽입할 위치를 지정한 후, 원소를 뒤로 옮기고 지정된 자리에 자료를 삽입 하여 정렬하는 알고리즘이다.
최선의 경우 O(N)이라는 엄청나게 빠른 효율성을 가지고 있어, 다른 정렬 알고리즘의 일부로 사용될 만큼 좋은 정렬 알고리즘이다.


#장점
알고리즘이 단순하다.
대부분의 원소가 이미 정렬되어 있는 경우, 매우 효율적일 수 있다.
정렬하고자 하는 배열 안에서 교환하는 방식이므로, 다른 메모리 공간을 필요로 하지 않는다. => 제자리 정렬(in-place sorting)
안정 정렬(Stable Sort) 이다.
Selection Sort나 Bubble Sort과 같은 O(n^2) 알고리즘에 비교하여 상대적으로 빠르다.


#단점
평균과 최악의 시간복잡도가 O(n^2)으로 비효율적이다.
Bubble Sort와 Selection Sort와 마찬가지로, 배열의 길이가 길어질수록 비효율적이다.


*/