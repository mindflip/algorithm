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
Bubble Sort�� Selection Sort�� ������ �˰������� ���� ������ �� ������ ��Ҹ� ���ϰ�, ���ǿ� ���� �ʴٸ� �ڸ��� ��ȯ�ϸ� �����ϴ� �˰��� �̴�.
�̸��� �����δ� ���� �������� ������ �̵��� ��ǰ�� �������� �ö���� ���� ����� ���̱� ������ �������ٰ� �Ѵ�.*

#����
������ �ſ� �����ϰ�, �ҽ��ڵ尡 �������̴�.
�����ϰ��� �ϴ� �迭 �ȿ��� ��ȯ�ϴ� ����̹Ƿ�, �ٸ� �޸� ������ �ʿ�� ���� �ʴ�. => ���ڸ� ����(in-place sorting)
���� ����(Stable Sort) �̴�.


#����
�ð����⵵�� �־�, �ּ�, ��� ��� O(n^2)����, ������ ��ȿ�����̴�.
���� ������ ���� ���Ұ� ���� �������� �ڸ��� ���� ���ؼ�, ��ȯ ����(swap)�� ���� �Ͼ�� �ȴ�.
*/