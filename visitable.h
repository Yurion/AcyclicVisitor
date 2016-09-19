#ifndef VISITOR_VISITABLE_H
#define VISITOR_VISITABLE_H

template <typename R = void>
class BaseVisitable
{
public:
    using ReturnType = R;

    virtual ~BaseVisitable() = default;
    virtual ReturnType  Accept(BaseVisitor&) = 0;
protected:
    template <typename T>
    static ReturnType AcceptImpl(T& visited, BaseVisitor& guest)
    {
        if (Visitor<T>* p = dynamic_cast<Visitor<T>*>(&guest))
        {
            return p->Visit(visited);
        }
        return ReturnType();
    }
};

#define DEFINE_VISITABLE() \
    ReturnType Accept(BaseVisitor& guest) override \
    { return AcceptImpl(*this, guest); }

#endif //VISITOR_VISITABLE_H
