#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& array) {
	int size = array.size();

	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++) {
			if (array[j] < array[i]) {
				swap(array[i], array[j]);
			}
		}
	}
}

void insertionSort(vector<int>& array) {
	int size = array.size();
	int key;
	int j;

	for (int i = 1; i < size; i++)
	{
		key = array[i];
		j = i - 1;

		while (j >= 0 && key < array[j])
		{
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = key;
	}
}


int main() {

	vector<int> array = { 5, 2, 4, 6, 1, 3 };

	//insertionSort(array);

	//selectionSort(array);

	for (size_t i = 0; i < array.size(); i++)
	{
		cout << array[i] << " ";
	}


	return 0;
}