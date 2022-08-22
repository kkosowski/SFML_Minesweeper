#ifndef MSSFMLVIEW_H__
#define MSSFMLVIEW_H__

#include <iostream>
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"


class MSSFMLView
{
	MinesweeperBoard & board;

public:
	explicit MSSFMLView(MinesweeperBoard & board);
	void draw (sf::RenderWindow & win);
  void clearBoard(MinesweeperBoard &board);
};
#endif
