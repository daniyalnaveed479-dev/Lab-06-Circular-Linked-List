
#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H

#include "BookNode.h"

class CircularLinkedList {
private:
    BookNode* head;
    int count;
    BookNode* currentBook;

    int NormalizeIndex(int index);
    BookNode* GetNodeAt(int index);
    void SwapData(BookNode* a, BookNode* b);

public:
    CircularLinkedList();

    bool IsEmpty();
    bool IsNotEmpty();

    void Insert(BookNode* book);
    BookNode* Remove();

    void InsertAt(BookNode* book, int index);
    BookNode* RemoveAt(int index);

    void Swap(int index1, int index2);
    void Sort();
    void Reverse();
    void Print();

    void MoveToNextBook();
    void CheckStatus();

    ~CircularLinkedList();
};

#endif
