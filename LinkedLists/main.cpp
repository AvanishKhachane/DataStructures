#include <iostream>
#include "LinkedLists.cpp"

int main() {
    linkedlist<int> list;

    // Test add
    list.add(10);
    list.add(20);
    list.add(30);

    std::cout << "List size after adding 3 elements: " << list.getsize() << "\n";
    std::cout << "First element: " << list[0] << "\n";
    std::cout << "Second element: " << list[1] << "\n";
    std::cout << "Third element: " << list[2] << "\n";

    // Test remove (middle)
    list.remove(20);
    std::cout << "List size after removing 20: " << list.getsize() << "\n";
    std::cout << "First element: " << list[0] << "\n";
    std::cout << "Second element: " << list[1] << "\n";

    // Test remove (head)
    list.remove(10);
    std::cout << "List size after removing 10: " << list.getsize() << "\n";
    std::cout << "First element: " << list[0] << "\n";

    // Test remove (tail)
    list.remove(30);
    std::cout << "List size after removing 30: " << list.getsize() << "\n";

    // Test out of range access
    try {
        list[0];
    }
    catch (const std::out_of_range& e) {
        std::cout << "Caught exception on out-of-range access: " << e.what() << "\n";
    }

    std::cout << "All linked list tests completed.\n";
    return 0;
}