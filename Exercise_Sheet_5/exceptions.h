
#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_

#include <stdexcept>


class GameException : public std::runtime_error {
public:
	using runtime_error::runtime_error;
};

class InventoryException : public GameException {
public:
	using GameException::GameException;
};

class InventoryFullException : public InventoryException {
public:
	InventoryFullException() : InventoryException("Inventory is full") {}
};

class InventoryEmptySlotException : public InventoryException {
public:
	InventoryEmptySlotException() : InventoryException("Inventory slot is empty") {}
};

class InvalidArgumentException : public GameException {
public:
	using GameException::GameException;
};

class InvalidIndexException : public InvalidArgumentException {
public:
	InvalidIndexException() : InvalidArgumentException("Invalid Array Index") {}
};

class InvalidLoot : public GameException {
public:
	InvalidLoot() : GameException("Invalid Loot") {}
};

#endif /* EXCEPTIONS_H_ */
