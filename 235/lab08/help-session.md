# Help session for quick sort

## Valgrind

private variable that will hold integers

private:
	int* values; <- array of stuff

clear() {
	delete[] values;
}

create(int size) {
	if (size > 0) {
		values = new int[size]
	}
}

## Algorithim

medianOfThree(left, right)
	pivot in the middle
	left on the left
	right on the right
	put all three in order relative to each other
		if left is greater than pivot, swap
		if pivot is greater than right, swap
		if left is greater than pivot, swap
	return pivot index (index not the value!)

partition(left, right, pivot) 
	
	swap pivot with the element on the far right 

	i = far left of the sub array
	j = next greatest index in the sub array (right next to pivot)


	incrament i until it hits something more than the pivot
	decrament j until it hits something less
	check if they have crossed, if not, swap the values 
	do it again
	etc
	until i and j cross, while j is not greater than i
	once they do, switch pivot with closet counter (i or j)

	returns where pivot finishes

	recursively call medianOfThree and partion on 