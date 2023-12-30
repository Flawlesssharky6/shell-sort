#include <iostream>

using namespace std;
const int SIZE = 10;
template <class T>
void shellsort(T a[], int size);
template <class T>
void swapper(T& a, T& b);
template <class T>
int search(T a[], T key);

int main() {
	int array[] = { 1,4,5,7,3,8,2,4,3,5 };
	string array1[] = { "shs", "s", "w", "wq", "e", "wr", "qw", "ty", "asd", "asd" };
	shellsort(array, SIZE);
	for (int i = 0; i < SIZE; i++) {
		cout << array[i] << endl;
	}
	shellsort(array1, SIZE);
	for (int i = 0; i < SIZE; i++) {
		cout << array1[i] << endl;
	}
	string arg = "qw";
	int x = search(array1, arg);
	if (x != -1)
		cout << array1[x] << " found at: " << x << endl;
	else
		cout << "not found" << endl;
	return 0;
}

template <class T>
void shellsort(T a[], int size) {
	bool flag = true;
	int i, d = size;
	while (flag || d > 1) {
		flag = false;
		d = (d + 1) / 2;
		for (i = 0; i < (size - d); i++) {
			if (a[i + d] < a[i]) {
				T temp = a[i];
				a[i] = a[i + d];
				a[i + d] = temp;
				//swapper(a[i], a[i+d])

				flag = true;
			}
		}
	}
}

template <class T>
void swapper(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

template <class T>
int search(T a[], T key) {
	int first = 0;
	int last = SIZE - 1, middle, pos = -1;
	bool found = false;
	while (!found && first <= last) {
		middle = (first + last) / 2;
		if (a[middle] == key) {
			found = true;
			pos = middle;
		}
		else {
			if (a[middle] > key) {
				last = middle - 1;
			}
			else {
				first = middle + 1;
			}
		}
	}
	return pos;
}