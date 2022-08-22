#ifndef MSBoardTextView_H__
#define MSBoardTextView_H__
#include "MinesweeperBoard.h"

class MSBoardTextView
{
  int height;
  int width;
  MinesweeperBoard &board;

  public:

  MSBoardTextView(MinesweeperBoard &board);
  void display();

};

#endif