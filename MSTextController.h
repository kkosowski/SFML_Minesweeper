#ifndef MSTESTCONTROLLER_H__
#define MSTESTCONTROLLER_H__

#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"

class MSTextController
{
  int height;
  int width;

  MinesweeperBoard &board;
  MSBoardTextView &view;

  public:

  MSTextController(MinesweeperBoard &board, MSBoardTextView &view);
  void play();
 

};

#endif