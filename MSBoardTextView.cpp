#include "MSBoardTextView.h"
#include <iostream>
#include "MinesweeperBoard.h"

MSBoardTextView::MSBoardTextView(MinesweeperBoard &board):board(board)
{
  height=board.getBoardHeight();
  width=board.getBoardWidth();
}

void MSBoardTextView::display()
{
  GameState state=board.getGameState();
  std::cout<<std::endl;
  for(int row=0; row<height; row++)
  {
    for(int column=0; column<width; column++)
    { 
      std::cout<<board.getFieldInfo(row, column)<<"  ";
    }
    std::cout<<std::endl;
  }
}


