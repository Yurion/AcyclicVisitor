#ifndef VISITOR_VISITOR_H
#define VISITOR_VISITOR_H

struct BaseVisitor
{
    virtual ~BaseVisitor() {}
};

template <typename T, typename R = void>
class Visitor
{
public:
    using ReturnType = R;

    virtual ReturnType Visit(T&) = 0;
    virtual ~Visitor() = default;
};

#endif //VISITOR_VISITOR_H
