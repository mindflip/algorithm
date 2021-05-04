#include <iostream>
#include <cstdlib>
#include <time.h>
#define SIZE 30000
// execution time �� 30000�� ����

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
	cout << "### Insertion Sort ###\n";

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

	for (int i = 1; i < SIZE; ++i) {
		int temp = arr[i];
		int prev = i - 1;
		while (prev >= 0 && arr[prev] > temp) {
			arr[prev + 1] = arr[prev];
			prev--;
		}
		arr[prev + 1] = temp;
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
// ��� ������ �Ǿ��ִ� ���(Optimal)�� ���, �ѹ��� �ۿ� �񱳸� ���ϹǷ� O(n) �� �ð����⵵�� ������ �ȴ�.
// ����, �̹� ���ĵǾ� �ִ� �迭�� �ڷḦ �ϳ��� ����/�����ϴ� ��쿡��, ���������� �ְ��� ���� �˰����� �Ǵµ�, Ž���� ������ ������尡 �ſ� ���� �����̴�.
// Space Complexity : O(n)
// Execution Time (sec) : 0.42800


/*

�� ���� ī�带 �����ϴ� ����� �����ϴ�.
Insertion Sort�� Selection Sort�� ����������, �� �� ȿ������ ���� �˰����̴�.
Insertion Sort�� 2��° ���Һ��� �����Ͽ� �� ��(����)�� ���ҵ�� ���Ͽ� ������ ��ġ�� ������ ��, ���Ҹ� �ڷ� �ű�� ������ �ڸ��� �ڷḦ ���� �Ͽ� �����ϴ� �˰����̴�.
�ּ��� ��� O(N)�̶�� ��û���� ���� ȿ������ ������ �־�, �ٸ� ���� �˰����� �Ϻη� ���� ��ŭ ���� ���� �˰����̴�.


#����
�˰����� �ܼ��ϴ�.
��κ��� ���Ұ� �̹� ���ĵǾ� �ִ� ���, �ſ� ȿ������ �� �ִ�.
�����ϰ��� �ϴ� �迭 �ȿ��� ��ȯ�ϴ� ����̹Ƿ�, �ٸ� �޸� ������ �ʿ�� ���� �ʴ´�. => ���ڸ� ����(in-place sorting)
���� ����(Stable Sort) �̴�.
Selection Sort�� Bubble Sort�� ���� O(n^2) �˰��� ���Ͽ� ��������� ������.


#����
��հ� �־��� �ð����⵵�� O(n^2)���� ��ȿ�����̴�.
Bubble Sort�� Selection Sort�� ����������, �迭�� ���̰� ��������� ��ȿ�����̴�.


*/