#include <memory>

template<typename T>
struct node {
	T data;
	std::unique_ptr<node<T>> next;

	node(T val, std::unique_ptr<node<T>> nextnode = nullptr) : data(val)
        {
		node = std::move(nextnode);
	}

	T getvalue() {return data};

	T setvalue(T val) {
		data = val;
		return data;
	}

	setnextnode(std::unique_ptr<node<T>> nextNode) {
		next = std::move(nextNode);
	}
};
