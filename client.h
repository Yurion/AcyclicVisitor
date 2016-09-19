#ifndef VISITOR_CLIENT_H
#define VISITOR_CLIENT_H

#include <iostream>
#include "visitable.h"

class DocElement : public BaseVisitable<>
{
public:
    DEFINE_VISITABLE()
};

class Paragraph : public DocElement
{
public:
    DEFINE_VISITABLE()
};

class Section : public DocElement
{
    Paragraph p1, p2;
public:
    //manual override Accept for custom functionality
    ReturnType Accept(BaseVisitor& guest) override
    {
        p1.Accept(guest);
        p2.Accept(guest);
    }
};

#endif //VISITOR_CLIENT_H
