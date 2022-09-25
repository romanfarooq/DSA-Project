#include<iostream>
using namespace std;

// function to swap two elements
void swap(int &x, int &y)
{
	int temp = x;
	x = y;
	y = temp;
}

class MaxHeap
{
private:
	int * heapArr;
	int maxSize;
	int heapSize;
public:
	MaxHeap(int size = 0)
	{
		heapSize = 0;
		maxSize = size;
		heapArr = new int[size];
	}

	int parent(int index)
	{
		return (index - 1) / 2;
	}

	int leftChild(int index)
	{
		return (2 * index + 1);
	}

	int rightChild(int index)
	{
		return (2 * index + 2);
	}

	int getMax()
	{
		return heapArr[0];
	}

	void insertKey(int key)
	{
		if (heapSize == maxSize)
		{
			cout << "Overflow: Could not insert Key" << endl;
			return;
		}

		// First insert the new key at the end
		heapSize++;
		int index = heapSize - 1;
		heapArr[index] = key;

		// Fix the max heap property if it is violated
		while (index != 0 && heapArr[parent(index)] < heapArr[index])
		{
			swap(heapArr[index], heapArr[parent(index)]);
			index = parent(index);
		}
	}

	void insertKeyAtIndex(int key, int index)
	{
		if (index > heapSize - 1)
		{
			cout << "Overflow: Could not insert Key" << endl;
			return;
		}
		else if (index < 0)
		{
			cout << "Underflow: Could not insert Key" << endl;
			return;
		}

		heapArr[index] = key;

		maxHeapify(index);
	}

	void deleteKey()
	{
		extractMax();
	}

	void deleteKeyAtIndex(int index)
	{
		if (index > heapSize - 1)
		{
			cout << "Overflow: Could not insert Key" << endl;
			return;
		}
		else if (index < 0)
		{
			cout << "Underflow: Could not insert Key" << endl;
			return;
		}

		heapArr[index] = heapArr[heapSize - 1];
		heapSize--;
		maxHeapify(index);
	}

	// Method to remove maximum element (or root) from max heap
	int extractMax()
	{
		if (heapSize <= 0)
		{
			cout << "Heap is empty" << endl;
			return -1;
		}

		// Store the maximum value, and remove it from heap
		int root = heapArr[0];
		heapArr[0] = heapArr[heapSize - 1];
		heapSize--;
		maxHeapify(0);

		return root;
	}

	void maxHeapSort()
	{
		int tempHeapSize = heapSize;
		// One by one extract an element from heap
		for (int i = heapSize - 1; i >= 0; i--)
		{
			// Move current root to end
			swap(heapArr[0], heapArr[i]);

			// call max heapify on the reduced heap
			heapSize--;
			maxHeapify(0);
		}
		heapSize = tempHeapSize;
	}

	void linearSearch(int val)
	{
		for (int i = 0; i < heapSize; i++)
		{
			if (heapArr[i] == val)
			{
				cout << "Value Found!";
				return;
			}
		}
		cout << "Value NOT Found!";
	}

	void maxHeapify(int index)
	{
		int left = leftChild(index);
		int right = rightChild(index);
		int largest = index;

		if (left < heapSize && heapArr[left] > heapArr[largest])
		{
			largest = left;
		}

		if (right < heapSize && heapArr[right] > heapArr[largest])
		{
			largest = right;
		}

		if (largest != index)
		{
			swap(heapArr[index], heapArr[largest]);
			maxHeapify(largest);
		}
	}

	void buildHeapThroughHeapify(int arr[], int size)
	{
		for (int i = 0; i < size; i++)
		{
			heapArr[i] = arr[i];
		}

		heapSize = size;

		// Index of last non-leaf node
		int startIndex = (heapSize / 2) - 1;

		// Perform reverse level order traversal
		// from last non-leaf node and heapify
		// each node
		for (int i = startIndex; i >= 0; i--)
		{
			maxHeapify(i);
		}
	}

	void buildHeapThroughInsertion(int arr[], int size)
	{
		for (int i = 0; i < size; i++)
		{
			insertKey(arr[i]);
		}
	}

	void printMaxHeap()
	{
		for (int i = 0; i < heapSize; i++)
		{
			cout << heapArr[i] << " ";
		}
		cout << endl;
	}

	~MaxHeap()
	{
		if (heapArr)
		{
			delete[]heapArr;
			heapArr = nullptr;
		}
	}
};

class MinHeap
{
private:
	int * heapArr;
	int maxSize;
	int heapSize;
public:
	MinHeap(int size = 0)
	{
		heapSize = 0;
		maxSize = size;
		heapArr = new int[size];
	}

	int parent(int index)
	{
		return (index - 1) / 2;
	}

	int leftChild(int index)
	{
		return (2 * index + 1);
	}

	int rightChild(int index)
	{
		return (2 * index + 2);
	}

	int getMin()
	{
		return heapArr[0];
	}

	void insertKey(int key)
	{
		if (heapSize == maxSize)
		{
			cout << "Overflow: Could not insert Key" << endl;
			return;
		}

		// First insert the new key at the end
		heapSize++;
		int index = heapSize - 1;
		heapArr[index] = key;

		// Fix the min heap property if it is violated
		while (index != 0 && heapArr[parent(index)] > heapArr[index])
		{
			swap(heapArr[index], heapArr[parent(index)]);
			index = parent(index);
		}
	}

	void insertKeyAtIndex(int key, int index)
	{
		if (index > heapSize - 1)
		{
			cout << "Overflow: Could not insert Key" << endl;
			return;
		}
		else if (index < 0)
		{
			cout << "Underflow: Could not insert Key" << endl;
			return;
		}

		heapArr[index] = key;

		minHeapify(index);
	}

	void deleteKey()
	{
		extractMin();
	}

	void deleteKeyAtIndex(int index)
	{
		if (index > heapSize - 1)
		{
			cout << "Overflow: Could not insert Key" << endl;
			return;
		}
		else if (index < 0)
		{
			cout << "Underflow: Could not insert Key" << endl;
			return;
		}

		heapArr[index] = heapArr[heapSize - 1];
		heapSize--;
		minHeapify(index);
	}

	// Method to remove minimum element (or root) from min heap
	int extractMin()
	{
		if (heapSize <= 0)
		{
			cout << "Heap is empty" << endl;
			return -1;
		}

		// Store the minimum value, and remove it from heap
		int root = heapArr[0];
		heapArr[0] = heapArr[heapSize - 1];
		heapSize--;
		minHeapify(0);

		return root;
	}

	void minHeapSort()
	{
		int tempHeapSize = heapSize;
		// One by one extract an element from heap
		for (int i = heapSize - 1; i >= 0; i--)
		{
			// Move current root to end
			swap(heapArr[0], heapArr[i]);

			// call max heapify on the reduced heap
			heapSize--;
			minHeapify(0);
		}
		heapSize = tempHeapSize;
	}

	void linearSearch(int val)
	{
		for (int i = 0; i < heapSize; i++)
		{
			if (heapArr[i] == val)
			{
				cout << "Value Found!";
				return;
			}
		}
		cout << "Value NOT Found!";
	}

	void minHeapify(int index)
	{
		int left = leftChild(index);
		int right = rightChild(index);
		int smallest = index;

		if (left < heapSize && heapArr[left] < heapArr[smallest])
		{
			smallest = left;
		}

		if (right < heapSize && heapArr[right] < heapArr[smallest])
		{
			smallest = right;
		}

		if (smallest != index)
		{
			swap(heapArr[index], heapArr[smallest]);
			minHeapify(smallest);
		}
	}

	void buildHeapThroughHeapify(int arr[], int size)
	{
		for (int i = 0; i < size; i++)
		{
			heapArr[i] = arr[i];
		}

		heapSize = size;

		// Index of last non-leaf node
		int startIndex = (heapSize / 2) - 1;

		// Perform reverse level order traversal
		// from last non-leaf node and heapify
		// each node
		for (int i = startIndex; i >= 0; i--)
		{
			minHeapify(i);
		}
	}

	void buildHeapThroughInsertion(int arr[], int size)
	{
		for (int i = 0; i < size; i++)
		{
			insertKey(arr[i]);
		}
	}

	void printMaxHeap()
	{
		for (int i = 0; i < heapSize; i++)
		{
			cout << heapArr[i] << " ";
		}
		cout << endl;
	}

	~MinHeap()
	{
		if (heapArr)
		{
			delete[]heapArr;
			heapArr = nullptr;
		}
	}
};

int main()
{

	MaxHeap obj(20);

	int arr[7] = { 5, 10, 30, 20, 35, 40, 15 };

	cout << "Building Max Heap" << endl;
	obj.buildHeapThroughHeapify(arr, 7);
	// obj.buildHeapThroughInsertion(arr, 7);
	obj.printMaxHeap();

	cout << endl << "Inserting 38 in Max Heap." << endl;
	obj.insertKey(38);
	obj.printMaxHeap();

	cout << endl << "Inserting 8 in Max Heap at index 3." << endl;
	obj.insertKeyAtIndex(8, 3);
	obj.printMaxHeap();

	cout << endl << "Deleting Key in Max Heap." << endl;
	obj.deleteKey();
	obj.printMaxHeap();

	cout << endl << "Deleting Key in Max Heap at index 2." << endl;
	obj.deleteKeyAtIndex(2);
	obj.printMaxHeap();

	cout << endl << "Get Max: " << obj.getMax() << endl;
	obj.printMaxHeap();

	cout << endl << "Extract Max: " << obj.extractMax() << endl;
	obj.printMaxHeap();

	cout << endl << "Max Heap Sort" << endl;
	obj.maxHeapSort();
	obj.printMaxHeap();
	return 0;
}
