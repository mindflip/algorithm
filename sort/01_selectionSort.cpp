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

Selection Sort�� Bubble Sort�� ������ �˰�������, �ش� ������ ���Ҹ� ���� ��ġ�� �̹� ������ �ְ�, � ���Ҹ� ������ �����ϴ� �˰����̴�.
Selection Sort�� Insertion Sort�� �򰥷��ϴ� ������� ���� �ִµ�, Selection Sort�� �迭���� �ش� �ڸ��� �����ϰ� �� �ڸ��� ���� ���� ã�� ���̶�� �����ϸ� ���ϴ�.

 
#����
Bubble sort�� ���������� �˰����� �ܼ��ϴ�.
������ ���� �� Ƚ���� ������, Bubble Sort�� ���� ������ ��ȯ�ϴ� Ƚ���� ���� ������ ���� ��ȯ�� �Ͼ�� �ϴ� �ڷ���¿��� ���� ȿ�����̴�.
Bubble Sort�� ���������� �����ϰ��� �ϴ� �迭 �ȿ��� ��ȯ�ϴ� ����̹Ƿ�, �ٸ� �޸� ������ �ʿ�� ���� �ʴ´�. => ���ڸ� ����(in-place sorting)


#����
�ð����⵵�� O(n^2)����, ��ȿ�����̴�.
�Ҿ��� ����(Unstable Sort) �̴�.


*/