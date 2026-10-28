
#include "InsertAt.h"
#include "CircularLinkedList.h"

void InsertBookAt(CircularLinkedList& library,
                  BookNode* book, int index) {
    library.InsertAt(book, index);
}
