#ifndef _OBSERVABLE_HPP
#define _OBSERVABLE_HPP

#include <functional>
#include <set>
#include "Observer.hpp"
#include <memory>

namespace ui {

class Observable {
public:
	using ObserverPtr = std::weak_ptr<Observer>;

	Observable():observed([](ObserverPtr const & lhs, ObserverPtr const & rhs){return lhs.lock().get() < rhs.lock().get();}) {
	}

	virtual void subscribe(Observer& o) {
		observed.insert(ObserverPtr(std::shared_ptr<Observer>(&o)));
	}
	virtual void unsubscribe(Observer& o) {
		observed.erase(ObserverPtr(std::shared_ptr<Observer>(&o)));
	}
	virtual void update() const {
		for (auto i = observed.begin(); i != observed.end(); ++i) {
			i->lock().get()->notify();
		}
	}
	virtual ~Observable() = default;
private:
	std::set<ObserverPtr, std::function<bool (ObserverPtr const &, ObserverPtr const &)>> observed;
};

}

#endif
