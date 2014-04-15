#include "Observable.hpp"

namespace ui {
	inline bool Compare::operator() (const std::reference_wrapper<const Observer>& lhs, const std::reference_wrapper<const Observer>& rhs) const {
		return &lhs.get() < &rhs.get();
	}

	void Observable::subscribe(const Observer & o) {
		observed.insert(std::cref(o));
	}

	void Observable::unsubscribe(const Observer & o) {
		observed.erase(std::cref(o));
	}

	void Observable::update() const {
		for (auto i = observed.begin(); i != observed.end(); ++i) {
			i->get().notify();
		}
	}
}