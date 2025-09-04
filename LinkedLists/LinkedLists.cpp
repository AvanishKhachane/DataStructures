#include <memory>
#include <stdexcept>

template <typename T = int>
struct node
{
private:
	T data;
	std::unique_ptr<node<T>> next;

public:
	node(T val, node<T> *nextNode = nullptr) : data(val)
	{
		if (nextNode)
		{
			next = std::unique_ptr<struct node<T>>(nextNode);
		}
	}

	node(const node<T> &other) : data(other.data)
	{
		if (other.next)
		{
			next = std::unique_ptr<struct node<T>>(*other.next);
		}
		else
		{
			next = nullptr;
		}
	}

	T getvalue() const { return data; };

	T setvalue(T val)
	{
		data = val;
		return data;
	}

	void setnextnode(node<T> &nextNode)
	{
		next = std::unique_ptr<struct node<T>>(nextNode);
	}

	node<T> *getnextnode() { return next.get(); }
};

template <typename T = int>
class linkedlist
{
private:
	std::unique_ptr<node<T>> head;
	node<T> *tail; // raw pointer, not unique_ptr
	int size;

public:
	linkedlist() : head(nullptr), tail(nullptr), size(0) {}

	void add(T val)
	{
		std::unique_ptr<node<T>> newNode = std::make_unique<node<T>>(val);

		if (!head)
		{
			head = std::move(newNode);
			tail = head.get();
		}
		else
		{
			tail->setnextnode(*(newNode.get()));
			tail = tail->getnextnode();
		}
		size++;
	}

	void remove(T val)
	{
		if (!head)
			return;
		node<T> *current = head.get();
		while (current->getnextnode() && current->getnextnode()->getvalue() != val)
		{
			current = current->getnextnode();
		}
		if (current->getnextnode() && current->getnextnode()->getvalue() == val)
		{
			node<T> *toDelete = current->getnextnode();
			current->setnextnode(*(toDelete->getnextnode()));
			if (toDelete == tail)
			{
				tail = current;
			}
			size--;
		}
		else if (head->getvalue() == val)
		{ // Special case for head
			head = std::unique_ptr<struct node<T>>(head->getnextnode());
			if (!head)
			{
				tail = nullptr;
			}
			size--;
		}
	}

	int getsize() const { return size; }
	node<T> *gethead() const { return head.get(); }
	node<T> *gettail() const { return tail; }

	node<T> *getnode(int index) const
	{
		if (index < 0 || index >= size)
		{
			throw std::out_of_range("Index out of range");
		}
		node<T> *current = head.get();
		for (int i = 0; i < index; ++i)
		{
			current = current->getnextnode();
		}
		return current;
	}

	T operator[](int index) const
	{
		return this->getnode(index)->getvalue();
	}
};