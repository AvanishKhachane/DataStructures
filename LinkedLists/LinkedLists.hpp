#include <memory>

template<typename T>
struct node {
	T data;
	node* next;

	node(T val, node* node = nullptr) : data(val), next(node) {}

	T getvalue() {};

	T setvalue(T val) {
		data = val;
		return data;
	}

	setnextnode(nod* nextNode) {
		next = nextNode;
	}
};
