
#include "RemoveAt.h"
#include "CircularLinkedList.h"

BookNode* RemoveBookAt(CircularLinkedList& library, int index) {
    return library.RemoveAt(index);
}
