#include<iostream>
using namespace std;

template <typename T>
struct Node
{
    Node(const T& _data)
        : data{_data}
        , next(nullptr)
        { }
        
	T data;
	Node<T> *next;	
};

template <typename T, typename MyAllocator = allocator<T>>
class ForwardList
{
    private:
		Node<T> *head = nullptr;
        Node<T> *tail = nullptr;
        
        using alloc_t = typename MyAllocator::template rebind<Node<T>>::other;
        alloc_t my_allocator;
        
    public:
		void append(T value)
		{
            auto newNode = my_allocator.allocate(1);       
            my_allocator.construct(newNode, value);           
            
			newNode->data = value;
			newNode->next = nullptr;
            
			if(head == nullptr)
			{
				head = newNode;
				tail = newNode;
				newNode = nullptr;
			}
			else
			{	
				tail->next = newNode;
				tail = newNode;
			}
		}
        
		void display()
		{
			auto currentNode = head;
            
			while(currentNode != nullptr)
			{
				cout << currentNode->data << "\t";
				currentNode = currentNode->next;
			}
		}
};