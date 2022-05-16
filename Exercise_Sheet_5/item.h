

#ifndef ITEM_H_
#define ITEM_H_

#include <string>
#include <iostream>
#include "exceptions.h"

class Item {
private:
	std::string name;
	int gold;

public:
	Item(const std::string& name, int gold);

	Item();

	// Getter & Setter

	int getGold() const {
		return gold;
	}

	void setGold(int gold) {
		if (gold >= 0) {
			this->gold = gold;
		} else {
			throw InvalidArgumentException("Gold may not be negative");
		}
	}

	const std::string& getName() const {
		return name;
	}

	void setName(const std::string &name) {
		if (!name.empty()) {
			this->name = name;
		} else {
			throw InvalidArgumentException("Name may not be empty");
		}
	}
};

std::ostream& operator<<(std::ostream& out, const Item& item);


#endif /* ITEM_H_ */
