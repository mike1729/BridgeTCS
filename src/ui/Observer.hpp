#ifndef Observer_hpp
#define Observer_hpp
namespace ui
{
	template <typename T>
	class Observer {
		public:
			virtual void notify(const T & observed) const = 0;
	};
}

#endif
