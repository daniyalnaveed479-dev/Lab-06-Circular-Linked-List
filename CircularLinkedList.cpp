
#include <iostream>
#include <utility>
#include "CircularLinkedList.h"

using namespace std;

CircularLinkedList::CircularLinkedList() {
    head = nullptr;
    count = 0;
    currentBook = nullptr;
}

int CircularLinkedList::NormalizeIndex(int index) {
    return ((index % count) + count) % count;
}

BookNode* CircularLinkedList::GetNodeAt(int index) {
    if (head == nullptr)
        return nullptr;

    BookNode* current = head->next;

    for (int i = 0; i < index; i++)
        current = current->next;

    return current;
}

void CircularLinkedList::SwapData(BookNode* a, BookNode* b) {
    swap(a->bookID, b->bookID);
    swap(a->title, b->title);
}

bool CircularLinkedList::IsEmpty() {
    return count == 0;
}

bool CircularLinkedList::IsNotEmpty() {
    return count > 0;
}

void CircularLinkedList::Insert(BookNode* book) {
    if (book == nullptr)
        return;

    if (IsEmpty()) {
        head = book;
        book->next = book;
        currentBook = book;
    } else {
        book->next = head->next;
        head->next = book;
    }

    count++;
}

BookNode* CircularLinkedList::Remove() {
    if (IsEmpty())
        return nullptr;

    BookNode* first = head->next;

    if (first == head) {
        head = nullptr;
        currentBook = nullptr;
    } else {
        head->next = first->next;

        if (currentBook == first)
            currentBook = first->next;
    }

    first->next = nullptr;
    count--;

    return first;
}

void CircularLinkedList::InsertAt(BookNode* book, int index) {
    if (book == nullptr)
        return;

    if (IsEmpty()) {
        head = book;
        book->next = book;
        currentBook = book;
        count++;
        return;
    }

    if (index < 0)
        index = NormalizeIndex(index);

    if (index > count)
        index %= count;

    if (index == 0) {
        Insert(book);
        return;
    }

    if (index == count) {
        book->next = head->next;
        head->next = book;
        head = book;
        count++;
        return;
    }

    BookNode* previous = GetNodeAt(index - 1);

    book->next = previous->next;
    previous->next = book;
    count++;
}

BookNode* CircularLinkedList::RemoveAt(int index) {
    if (IsEmpty())
        return nullptr;

    index = NormalizeIndex(index);

    if (index == 0)
        return Remove();

    BookNode* previous = GetNodeAt(index - 1);
    BookNode* target = previous->next;

    previous->next = target->next;

    if (target == head)
        head = previous;

    if (currentBook == target)
        currentBook = target->next;

    target->next = nullptr;
    count--;

    return target;
}

void CircularLinkedList::Swap(int index1, int index2) {
    if (IsEmpty())
        return;

    index1 = NormalizeIndex(index1);
    index2 = NormalizeIndex(index2);

    if (index1 == index2)
        return;

    SwapData(GetNodeAt(index1), GetNodeAt(index2));
}

void CircularLinkedList::Sort() {
    if (count < 2)
        return;

    BookNode* current = head->next;

    for (int i = 0; i < count - 1; i++) {
        BookNode* nextNode = current->next;

        for (int j = i + 1; j < count; j++) {
            if (current->bookID > nextNode->bookID)
                SwapData(current, nextNode);

            nextNode = nextNode->next;
        }

        current = current->next;
    }
}

void CircularLinkedList::Reverse() {
    if (count < 2)
        return;

    BookNode* oldTail = head;
    BookNode* oldFirst = head->next;

    BookNode* previous = oldTail;
    BookNode* current = oldFirst;

    while (current != oldTail) {
        BookNode* nextNode = current->next;
        current->next = previous;
        previous = current;
        current = nextNode;
    }

    oldTail->next = previous;
    head = oldFirst;
}

void CircularLinkedList::Print() {
    if (IsEmpty()) {
        cout << "\nNo books in the collection.\n";
        return;
    }

    BookNode* current = head->next;

    cout << "\nIndex\tBook ID\tTitle\n";
    cout << "-----------------------------------\n";

    for (int i = 0; i < count; i++) {
        cout << i << "\t"
             << current->bookID << "\t"
             << current->title << '\n';

        current = current->next;
    }

    cout << "Total books: " << count << '\n';
}

void CircularLinkedList::MoveToNextBook() {
    if (IsEmpty()) {
        cout << "\nNo books available.\n";
        return;
    }

    if (currentBook == nullptr)
        currentBook = head->next;

    cout << "\nCurrent Book: "
         << currentBook->bookID << " - "
         << currentBook->title << '\n';

    currentBook = currentBook->next;
}

void CircularLinkedList::CheckStatus() {
    cout << "\nCollection Status\n";

    if (IsEmpty()) {
        cout << "The collection is empty.\n";
    } else {
        cout << "The collection contains books.\n";
    }

    cout << "Total books: " << count << '\n';

    if (head != nullptr)
        cout << "Last book links back to the first book.\n";
}

CircularLinkedList::~CircularLinkedList() {
    while (IsNotEmpty())
        delete Remove();
}
