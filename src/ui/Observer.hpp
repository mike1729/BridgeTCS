#ifndef Observer_hpp
#define Observer_hpp
namespace ui
{
    class Observer {
    public:
        virtual void notify() const = 0;
    };
}

#endif
