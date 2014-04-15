#ifndef _OBSERVABLE_HPP
#define _OBSERVABLE_HPP

#include <functional>
#include <set>
#include "Observer.hpp"

namespace ui {
	struct Compare {
		inline bool operator() (const std::reference_wrapper<const Observer>& lhs, const std::reference_wrapper<const Observer>& rhs) const;
	};

	class Observable {
	public:
		virtual void subscribe(const Observer & o);
		virtual void unsubscribe(const Observer & o);
		virtual void update() const;
	private:
		std::set<std::reference_wrapper<const Observer>, Compare> observed;
	};
}

#endif