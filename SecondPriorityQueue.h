#pragma once
#include <utility>


using namespace std;

typedef int TElem;
typedef int TPriority;
typedef std::pair<TElem, TPriority> Element;

typedef bool(*Relation)(TPriority p1, TPriority p2);

class SecondPriorityQueue
{
private:
    //representation of the SecondPriorityQueue

    Element *heap;
    int size;
    int capacity;

    Element firstElement;
    bool hasFirstElement;

    Relation relation;

    void expandHeap();

public:
    //implicit constructor
    explicit SecondPriorityQueue(Relation r);

    //adds an element with a priority to the queue
    //Complexity: O(log(n))
    void push(TElem e, TPriority p);

    //returns the element with the second highest priority with respect to the relation
    //throws exception if the queue has less than 2 elements
    //Complexity: Theta(1)
    Element top() const;

    //removes and returns the element with the second highest priority
    //throws exception if the queue has less than 2 elements
    //Complexity: O(log(n))
    Element pop();

    //checks if the queue has at most one element
    //Complexity: Theta(1)
    bool atMostOne() const;

    //destructor
    ~SecondPriorityQueue();
};

