#include "QS.h"
#include <sstream>

using namespace std;

QS::QS() {
	pivot = 0;
	array_size = 0;
	add_count = 0;
	array = NULL;
}

QS::~QS() {
	clear();
}

void QS::swap(int left, int right) {
	int temp = array[left];
	array[left] = array[right];
	array[right] = temp;
}

void QS::sortAll() {
	if (array_size != 0) {
		pivot = partition(0, array_size - 1, medianOfThree(0, array_size - 1));
	}
}

int QS::medianOfThree(int left, int right) {
	if (left >= right || left < 0 || right > array_size) {
		// empty array/incorrect input
		return -1;
	} else if ((left - right) == 1) {
		// if two cells
		if (array[left] > array[right]) {
			swap(left, right);
		}
		return left;
	} else {
		// three or more cells
		pivot = (left + right) / 2;
		if (array[left] > array[pivot]) {
			swap(left, pivot);
		}
		if (array[pivot] > array[right]) {
			swap(right, pivot);
		}
		if (array[left] > array[pivot]) {
			swap(left, pivot);
		}	
		return pivot;
	}
}

int QS::partition(int left, int right, int pivotIndex) {
	if ((right - left) > 1) {
		// if partition is 3 or greater
		swap(pivotIndex, right);
		pivotIndex = right;
		right--;
		while (left < right) {
			while (array[left] < array[pivotIndex]) {
				left++;
			}
			while (array[right] > array[pivotIndex]) {
				right--;
			}
			if (left < right) {
				swap(left, right);
				left++;
				right--;
			}
		}
		swap(pivotIndex, left);
		int temp = pivotIndex;
		pivotIndex = left;
		left = temp;
		// recursive call on right partition
		partition(0, right, medianOfThree(0, right));
		// recursive call on left partition
		partition(pivotIndex + 1, left, medianOfThree(pivotIndex + 1, left));
	}
	return pivotIndex;
}

string QS::getArray() {
	string result = "";
	if (array_size == 0) {
		return result;
	}
	for (int i = 0; i < add_count - 1; i++) {
		stringstream convert;
		convert << array[i];
		result += convert.str() + ", ";
	}
	stringstream convert;
	convert << array[add_count - 1];
	result += convert.str();
	return result;
}

int QS::getSize() {
	return array_size;
}

void QS::addToArray(int value) {
	if (add_count != array_size) {
		array[add_count] = value;
		add_count++;
	}
}

bool QS::createArray(int size) {
	if (size <= 0) {
		return false;
	}
	array = new int[size];
	array_size = size;
	for (int i = 0; i < array_size - 1; i++) {
		array[i] = 0;
	}
	return true;
}

void QS::clear() {
	delete[] array;
	array_size = 0;
	array = NULL;
}