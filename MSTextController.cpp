#include <iostream>
#include "MSTextController.h"

MSTextController::MSTextController(MinesweeperBoard &board, MSBoardTextView &view):board(board), view(view)
{
  height=board.getBoardHeight();
  width=board.getBoardWidth();
}

void MSTextController::play()
{
  int row;
  int column;
  int action;

  do
  {
    view.display();
    std::cout<<"Choose your action:"<<std::endl;
    std::cout<<"1-RevealField"<<std::endl;
    std::cout<<"2-ToggleFLag"<<std::endl;
    std::cin>>action;
    if(action==1)
    {
      std::cout<<"Type in ROW"<<std::endl;
      std::cin>>row;
      std::cout<<"Type in COLUMN"<<std::endl;
      std::cin>>column;
      board.revealField(row, column);
    }
    if(action==2)
    {
      std::cout<<"Type in ROW"<<std::endl;
      std::cin>>row;
      std::cout<<"Type in COLUMN"<<std::endl;
      std::cin>>column;
      board.toggleFlag(row, column);
    }
  }while(board.getGameState()==RUNNING);
  
  if(board.getGameState()==FINISHED_WIN)
  {    
    view.display();
    std::cout<<std::endl;
    std::cout<<"YOU WON!"<<std::endl;
  }
  if(board.getGameState()==FINISHED_LOSS)
  {
    view.display();
    std::cout<<std::endl;
    std::cout<<"YOU LOSE!"<<std::endl;
  }
}


