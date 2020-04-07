/* -----------------------------------------------------------------------------
 *
 * File Name:  Heap.cpp
 * Author: Marco Borth
 * Assignment:   EECS 560 Lab 7 – Min Heap and Max Heap
 * Description:  Heap methods are defined, regardless of priority.
 * Date: 3/24/24
 *
 ---------------------------------------------------------------------------- */

template <typename T>
Heap<T>::Heap() {
	m_size = 1;
	m_heapSize = 0;
	m_arr = new T [m_size];
	kary = 2;
	priority = "";
}

template <typename T>
Heap<T>::Heap(int k, string mode){
	m_size = 1;
	m_heapSize = 0;
	m_arr = new T [m_size];
	if(k > 2)
		kary = k;
	else
		kary = 2;

	priority = mode;
}

template <typename T>
Heap<T>::~Heap() {
	clear();
	delete[] m_arr;
}

template <typename T>
bool Heap<T>::isEmpty() const {
	if (m_heapSize > 0)
		return false;
	else
		return true;
}

template <typename T>
void Heap<T>::setKary(int k){
	if(k > 2)
		kary = k;
	else
		kary = 2;
}

template <typename T>
void Heap<T>::setPriority(string mode){
	priority = mode;
}

template <typename T>
int Heap<T>::getNumberOfNodes() const {
	return m_heapSize;
}

template <typename T>
T Heap<T>::getEntry(int index) {
	if (index >= 0 && index < m_size) {
		return m_arr[index];
	} else {
		throw(std::runtime_error("ERROR: Invalid Index.\n"));
	}
}

template <typename T>
int Heap<T>::getHeight() const {
	int height = 0;

	while (3 * height + 3 < m_size) {
		height++;
	}

	return height;
}

template <typename T>
int Heap<T>::getSize() {
	return m_size;
}

template <typename T>
T Heap<T>::peekTop() const {
	if (!isEmpty())
		return m_arr[0];
	else
		throw(std::runtime_error("ERROR: Heap is empty.\n"));
}

template <typename T>
void Heap<T>::resize() {
	T* tempArr = new T [m_size + 1];

	for(int i = 0; i < m_size; i++) {
		tempArr[i] = m_arr[i];
	}

	T* swap = m_arr;
	m_arr = tempArr;
	tempArr = swap;

	delete[] tempArr;
	swap = nullptr;
	delete swap;
	m_size++;
}

template <typename T>
void Heap<T>::add(T data) {
	if (m_heapSize == m_size) {
		resize();
		add(data);
	} else {
		m_arr[m_heapSize] = data;
		m_heapSize++;
	}
}

template <typename T>
void Heap<T>::bottomUpHeapify() {
	for(int i = m_size; i >= 0; i--) {
		bool notALeaf = false;
		for(int j = 0; j < kary; j++) {
			if(kary * i + j + 1< m_size)
				notALeaf = true;
		}

		if(notALeaf)
			compareFamily(i);
	}
}

template <typename T>
void Heap<T>::compareFamily(int parentIndex) {
	if (kary * parentIndex + 1 < m_size) {
		int childIndex = kary * parentIndex + 1;
		if (priority == "max") {
			for(int j = 1; j < kary; j++) {
				if(kary * parentIndex + j + 1 < m_size) {
					if (m_arr[childIndex]->getPriority() < m_arr[kary * parentIndex + j + 1]->getPriority()) {
						childIndex = kary * parentIndex + j + 1;
					}
				}
			}

			if(m_arr[parentIndex]->getPriority() < m_arr[childIndex]->getPriority()) {
				T temp = m_arr[parentIndex];
				m_arr[parentIndex] = m_arr[childIndex];
				m_arr[childIndex] = temp;
				compareFamily(childIndex);
			}
		} else if (priority == "min") {
			for(int j = 1; j < kary; j++) {
				if(kary * parentIndex + j + 1 < m_size) {
				  if (m_arr[childIndex]->getPriority() > m_arr[kary * parentIndex + j + 1]->getPriority()) {
					  childIndex = kary * parentIndex + j + 1;
				  }
			  }
			}

		  if(m_arr[parentIndex]->getPriority() > m_arr[childIndex]->getPriority()) {
			  T temp = m_arr[parentIndex];
			  m_arr[parentIndex] = m_arr[childIndex];
			  m_arr[childIndex] = temp;
			  compareFamily(childIndex);
			}
		}
	}
}

template <typename T>
void Heap<T>::addTopDown(T data) {
	if (m_heapSize == m_size) {
		resize();
		add(data);
	} else {
		m_arr[m_heapSize] = data;
		upHeap(m_heapSize);
		m_heapSize++;
	}
}

template <typename T>
void Heap<T>::upHeap(int index) {
	int parent = (index - 1) / kary;

	if (index && m_arr[parent]->getPriority() < m_arr[index]->getPriority()) {
		T temp = m_arr[index];
		m_arr[index] = m_arr[parent];
		m_arr[parent] = temp;

		upHeap(parent);
	}
}

template <typename T>
void Heap<T>::clear() {
	if (!isEmpty()) {
		//for(int i = 0; i < m_size; i++)
			//delete m_arr[i];
	}

	m_heapSize = 0;
}
template <typename T>
void Heap<T>::remove(int index) {
	if (!isEmpty()) {
		int heapBound = m_size - 1;

		T temp = m_arr[heapBound];
		m_arr[heapBound] = m_arr[index];
		m_arr[index] = temp;

		delete m_arr[heapBound];

		T* tempArr = new T [m_size];

		for(int i = 0; i < m_size - 1; i++) {
			tempArr[i] = m_arr[i];
		}

		T* swap = m_arr;
		m_arr = tempArr;
		tempArr = swap;

		delete[] tempArr;
		swap = nullptr;
		delete swap;
		m_size--;
		m_heapSize--;

		bottomUpHeapify();
	} else
		throw(std::runtime_error("ERROR: Heap is empty.\n"));
}

template <typename T>
void Heap<T>::removeTopDown() {
	if (!isEmpty()) {
		int heapBound = getNumberOfNodes() - 1;

		T temp = m_arr[heapBound];
		m_arr[heapBound] = m_arr[0];
		m_arr[0] = temp;

		delete m_arr[heapBound];

		m_heapSize--;
		downHeap(0);
	} else
		throw(std::runtime_error("ERROR: Heap is empty.\n"));
}

template <typename T>
void Heap<T>::downHeap(int index) {
	int leftChild = (2 * index) + 1;
  int rightChild = (2 * index) + 1;

	int largest = index;

	if (leftChild < getNumberOfNodes() && m_arr[leftChild]->getSeverity() > m_arr[index]->getSeverity()) {
		largest = leftChild;
	} else if (leftChild < getNumberOfNodes() && m_arr[leftChild]->getSeverity() == m_arr[index]->getSeverity()) {
		if (leftChild < getNumberOfNodes() && m_arr[leftChild]->getAge() > m_arr[index]->getAge())
			largest = leftChild;
	}

	if (rightChild < getNumberOfNodes() && m_arr[rightChild]->getSeverity() > m_arr[largest]->getSeverity()) {
		largest = rightChild;
	} else if (rightChild < getNumberOfNodes() && m_arr[rightChild]->getSeverity() == m_arr[index]->getSeverity()) {
		if (rightChild < getNumberOfNodes() && m_arr[rightChild]->getAge() > m_arr[index]->getAge())
			largest = rightChild;
	}

	if (largest != index) {
		T temp = m_arr[index];
  	m_arr[index] = m_arr[largest];
  	m_arr[largest] = temp;
		downHeap(largest);
	}
}
