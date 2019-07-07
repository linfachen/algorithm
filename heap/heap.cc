#include <vector>
#include <iostream>

typedef struct node {
	int key;
	int val;
	node(int x, int y) :key(x), val(y) {}
}node;

#define PARENT(i) ((i-1)/2) 
#define LEFT(i) (2*(i)+1)
#define RIGHT(i) (2*(i)+2)

inline void swap(node& a, node &b) {
	std::swap(*((uint64_t*)&a), *((uint64_t*)&b));
}

inline void max_heapify(std::vector<node> &_heap, int index) {
	int size = _heap.size();
	while (true) {
		int left = LEFT(index);
		int right = RIGHT(index);
		if ((left >= size || _heap[index].key >= _heap[left].key) && (right >= size || _heap[index].key >= _heap[right].key)) {
			return;
		}
		else {
			if (right >= size || _heap[left].key >= _heap[right].key) {
				swap(_heap[index], _heap[left]);
				index = left;
			}
			else {
				swap(_heap[index], _heap[right]);
				index = right;
			}
		}
	}
}


class heap {
public:
	std::vector<node> _heap;
	heap() {};
	template <class InputIterator> void init_heap(InputIterator first, InputIterator last);
	void push(int key, int val) {
		_heap.emplace_back(key, val);
	}
	node &top() {
		return _heap[0];
	}
	void pop() {
		swap(_heap[0], _heap.back());
		_heap.pop_back();
		max_heapify(_heap, 0);
	}
	int get_val() {
		node &nod = _heap[0];
		int res = nod.val;
		nod.key--;
		max_heapify(_heap, 0);
		return res;
	}
};

template <class InputIterator>
void heap::init_heap(InputIterator first, InputIterator last) {
	while (first != last) {
		_heap.emplace_back(first->first, first->second);
		++first;
	}

	int n = _heap.size();
	for (int i = (n - 1) / 2; i >= 0; i--) {
		max_heapify(_heap, i);
	}
}