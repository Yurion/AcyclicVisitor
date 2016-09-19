#include <iostream>
#include "visitor.h"
#include "client.h"

class MyConcreteVisitor : public BaseVisitor,
        public Visitor<DocElement>,
        public Visitor<Paragraph>,
        public Visitor<Section>
{
public:
    Visitor<DocElement>::ReturnType Visit(DocElement&) override {std::cout << "Visit(DocElement&)\n";}
    Visitor<Paragraph>::ReturnType  Visit(Paragraph&) override {std::cout << "Visit(Paragraph&)\n";}
    Visitor<Section>::ReturnType    Visit(Section&) override {}
};

int main()
{
    MyConcreteVisitor visitor;
    Section par;
    DocElement* d = &par;
    d->Accept(visitor);
}