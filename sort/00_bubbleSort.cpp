#include <iostream>
#include <cstdlib>
#include <time.h>
#define SIZE 30000
using namespace std;

int arr[SIZE+1];
bool visit[SIZE+1];

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
	cout << "### Bubble Sort ###\n";
	
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
		for (int j = 1; j < SIZE - i; ++j) {
			if (arr[j - 1] > arr[j]) {
				int temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
			}
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
// Space Complexity : O(n)
// Execution Time (sec) : 1.90800



/*
Bubble Sort는 Selection Sort와 유사한 알고리즘으로 서로 인접한 두 원소의 대소를 비교하고, 조건에 맞지 않다면 자리를 교환하며 정렬하는 알고리즘 이다.
이름의 유래로는 정렬 과정에서 원소의 이동이 거품이 수면으로 올라오는 듯한 모습을 보이기 때문에 지어졌다고 한다.*

#장점
구현이 매우 간단하고, 소스코드가 직관적이다.
정렬하고자 하는 배열 안에서 교환하는 방식이므로, 다른 메모리 공간을 필요로 하지 않다. => 제자리 정렬(in-place sorting)
안정 정렬(Stable Sort) 이다.


#단점
시간복잡도가 최악, 최선, 평균 모두 O(n^2)으로, 굉장히 비효율적이다.
정렬 돼있지 않은 원소가 정렬 됐을때의 자리로 가기 위해서, 교환 연산(swap)이 많이 일어나게 된다.
*/