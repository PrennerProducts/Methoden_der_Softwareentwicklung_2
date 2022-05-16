

#include "item.h"




Item::Item(const std::string& name, int gold)
		: name(name), gold(gold) {}

Item::Item()
	: gold(0) {}


std::ostream& operator<<(std::ostream& out, const Item& item) {
	out << "Gegenstand " << item.getName();
	return out;
}


