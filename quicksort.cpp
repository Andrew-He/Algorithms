#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std; 

#include <iostream>

template <typename T>
void QuickSort(T elems[], int begin, int end)
{
	int i = begin, j = end, key = elems[begin+(end-begin)/2];

	do {
		while (elems[i] < key) {
		      i++;
		}
		while (elems[j] > key) {
		      j--;
		}
		if (i <= j) {
			std::swap(elems[i++], elems[j--]);
		}
	} while (i < j);

	if (j > begin) {
		QuickSort(elems, begin, j);
	}
	if (i < end) {
		QuickSort(elems, i, end);
	}
}

int main(int argc, char *argv[])
{
	int array[10];

	srand(time(0));

	for (auto &i : array) {
		i = rand() % 100;
	}

	QuickSort(array, 0, 9);

	for (auto i : array) {
		std::cout << i << " ";
	}
	std::cout << std::endl;

	return 0;
} 










