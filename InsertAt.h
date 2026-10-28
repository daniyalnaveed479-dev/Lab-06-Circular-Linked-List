
#ifndef INSERTAT_H
#define INSERTAT_H

#include "BookNode.h"

class CircularLinkedList;

void InsertBookAt(CircularLinkedList& library,
                  BookNode* book, int index);

#endif
