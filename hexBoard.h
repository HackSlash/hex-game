#ifndef HEXBOARD_H
#define HEXBOARD_H

#include <vector>

enum Space {P_EMPTY, P_RED, P_BLUE};

class hexBoard
{
public:
	hexBoard(){
		spaces = new std::vector<Space>(11 * 11, P_EMPTY);
	}


	virtual ~hexBoard() {
		delete spaces;
	}

	inline int getSize() const {return spaces->size();}
	int getIndex(unsigned int x, unsigned int y) const;
	std::pair<int, int> getCoords(unsigned int index) const;
	Space getSpace(unsigned int index) const;
	Space getSpace(unsigned int x, unsigned int y) const;
	void setSpace(unsigned int index, Space sp);
	void setSpace(unsigned int x, unsigned int y, Space sp);
	bool isValidMove(unsigned int x, unsigned int y, bool piRule = false) const;
	bool isValidMove(unsigned int index, bool piRule = false) const;
	bool isValidSpace(unsigned int index) const;
	bool isValidSpace(unsigned int x, unsigned int y) const;
private:
	std::vector<Space> spaces;
};

inline bool hexBoard::isValidSpace(unsigned int index) const {
	return index < spaces->size();
}

inline bool hexBoard::isValidSpace(unsigned int x, unsigned int y) const {
	return x < 11 && y < 11;
}

inline bool hexBoard::isValidMove(unsigned int x, unsigned int y, bool piRule) const {
	return isValidSpace(x, y) && (getSpace(x, y) == P_EMPTY || piRule);
}

inline bool hexBoard::isValidMove(unsigned int index, bool piRule) const {
	return isValidSpace(index) && (getSpace(index) == P_EMPTY || piRule);
}

inline int hexBoard::getIndex(unsigned int x, unsigned int y) const {
	return 11 * y + x;
}

inline std::pair<int, int> hexBoard::getCoords(unsigned int index) const {
	int x = index % 11;
	int y = index / 11;
	return srd::pair<int, int>(x, y);
}

inline Space hexBoard::getSpace(unsigned int index) const {
	return (*spaces)[index];
}

inline Space hexBoard::getSpace(unsigned int x, unsigned int y) const {
	return getSpace(getIndex(x, y));
}

inline void hexBoard::setSpace(unsigned int index, Space sp) {
	(*spaces)[index] = sp;
}

inline void hexBoard::setSpace(unsigned int x, unsigned int y, Space sp) {
	setSpace(getIndex(x,y), sp)
}

#endif /* HEXBOARD_H */