//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
//////////////////////////////////////////////////////////////////////////////

#ifndef _LISTENELEMENT_H_
#define _LISTENELEMENT_H_

#include "Student.h"

class ListenElement
{
private:
    Student data;
    ListenElement* next;
    ListenElement* last;

public:
    ListenElement(Student pData, ListenElement* pNext, ListenElement* pLast);

    void setData(Student pData);
    void setNext(ListenElement* pNext);
    void setLast(ListenElement* pLast);

    Student getData() const;
    ListenElement* getNext() const;
    ListenElement* getLast() const;
};

#endif
