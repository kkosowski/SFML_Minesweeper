#include "MinesweeperBoard.h"
#include "Array2D.h"
#include <iostream>
#include <ctime>



MinesweeperBoard::MinesweeperBoard(int width, int height, GameMode mode)
{
  //Czyszczenie planszy(tylko do SFML)
  for (int row = 0; row<height; row++)
  {
    for (int column =0; column<width; column++)
    {
      board[row][column].hasFlag=false;
      board[row][column].isRevealed=false;
      board[row][column].hasMine=false;
    }
  }


  this->width=width;
  this->height=height;
  this->game_mode = mode;
  
  game_state=RUNNING;

  int MineCount;
  float multiplier;
  
  if(mode==EASY)
  {
    multiplier=0.1;
    MineCount=width*height*multiplier;
  }
  if(mode==NORMAL)
  {
    multiplier=0.2;
    MineCount=width*height*multiplier;
  }
  if(mode==HARD)
  {
    multiplier=0.3;
    MineCount=width*height*multiplier;
  }
  if(mode==DEBUG)
  {
    
    for(int row=0; row<height; row++)
    {
      for(int column=0; column<width; column++)
      {
        if (row==column or row==0 or (column==0 and row%2==0))
        {
          board[row][column].hasMine=true;
        }   
      }
    }  
  }
  //Random bombs
  srand (time(NULL));
  for(int counter=0; counter<MineCount; counter++)
  {
    int RandomRow=rand()%height;
    int RandomColumn=rand()%height;
    if(board[RandomRow][RandomColumn].hasMine==true)
    {
       counter--;
    }
    else
    {
      board[RandomRow][RandomColumn].hasMine=true;
    }   
  }
 
}



void MinesweeperBoard::debug_display() const
{
  std::cout<<std::endl;

  for(int row=0; row<height; row++)
    {
      for(int column=0; column<width; column++)
      {
        if(board[row][column].hasMine)
        {
          std::cout<<"[M";
        }
        else
          std::cout<<"[.";

        if(board[row][column].isRevealed)
        {
          std::cout<<"o";
        }
        else
          std::cout<<".";

        if(board[row][column].hasFlag)
        {
          std::cout<<"F]";
        }
        else
          std::cout<<".]";
      }
      std::cout<<std::endl;
    }
}

int MinesweeperBoard::getBoardWidth() const
{
  return width;
}
int MinesweeperBoard::getBoardHeight() const
{
  return height;
}
int MinesweeperBoard::getMineCount() const 
{
  int counter=0;
  for(int row=0; row<height; row++)
  {
      for(int column=0; column<width; column++)
      {
        if(board[row][column].hasMine)
        {
          counter++;
        }
      }
  }
  return counter;
}

bool MinesweeperBoard::isOutsideBoard(int row, int col) const
{
  if((row>height or col>width) or (row<0 or col<0))
  {
    return true;
  }
  return false;
}

int MinesweeperBoard::countMines(int row, int col) const
{
  int counter=0;
  
  if(isOutsideBoard(row, col) or board[row][col].isRevealed==false)
  {
    return -1;
  }
  if(isOutsideBoard(row+1, col+1)==false and board[row+1][col+1].hasMine )
  {
    counter++;
  }
  if(isOutsideBoard(row, col+1)==false and board[row][col+1].hasMine)
  {
    counter++;
  }
  if(isOutsideBoard(row-1, col+1)==false and board[row-1][col+1].hasMine)
  {
    counter++;
  }
  if(isOutsideBoard(row-1, col)==false and board[row-1][col].hasMine)
  {
    counter++;
  }
  if(isOutsideBoard(row-1, col-1)==false and board[row-1][col-1].hasMine)
  {
    counter++;
  }
  if(isOutsideBoard(row+1, col-1)==false and board[row+1][col-1].hasMine)
  {
    counter++;
  }
  if(isOutsideBoard(row, col-1)==false and board[row][col-1].hasMine)
  {
    counter++;
  }
  if(isOutsideBoard(row+1, col)==false and board[row+1][col].hasMine)
  {
    counter++;
  }
  return counter;
}


bool MinesweeperBoard::hasMine(int row, int col) const
{
  if (board[row][col].hasMine)
   {
    return true;
   }
    return false;
}


bool MinesweeperBoard::hasFlag(int row, int col) const
{
  if(board[row][col].hasFlag)
  {
    return true;
  }
  if(board[row][col].isRevealed or board[row][col].hasFlag==false or (row>height or col>width))
  {
    return false;
  }
}

void MinesweeperBoard::toggleFlag(int row, int col)
{
  if(board[row][col].isRevealed==false and board[row][col].hasFlag)
  {
    board[row][col].hasFlag=false;
  }
  if(board[row][col].isRevealed==false and board[row][col].hasFlag==false)
  {
    board[row][col].hasFlag=true;
  }
  if(board[row][col].isRevealed or (row>height or col>width) or getGameState()!=RUNNING)
  {
    return;
  }
}

bool MinesweeperBoard::isFirstAction() const
{
  for(int row=0; row<height; row++)
  {
      for(int column=0; column<width; column++)
      {
        if(board[row][column].isRevealed)
        {
          return false;
        }
      }
  }
  return true;
}

void MinesweeperBoard::revealField(int row, int col)
{
  if(board[row][col].isRevealed or (row>height or col>width) or getGameState()!=RUNNING or board[row][col].hasFlag)
  {
    return;
  }
  if(board[row][col].isRevealed==false and board[row][col].hasMine==false)
  {
    board[row][col].isRevealed=true;
  }
  if(board[row][col].isRevealed==false and board[row][col].hasMine==true)
  {
    if(isFirstAction()==true and game_mode!=DEBUG)
    {
      int RandomRow=rand()%height;
      int RandomColumn=rand()%height;
      board[RandomRow][RandomColumn].hasMine=true;
      board[row][col].isRevealed=true;
    }
    board[row][col].isRevealed=true;
    game_state=FINISHED_LOSS;
  }
}

bool MinesweeperBoard::isRevealed(int row, int col) const
{
  if(board[row][col].isRevealed)
  {
    return true;
  }
  return false;
}

GameState MinesweeperBoard::getGameState() const
{
  int counter=0;
  for(int row=0; row<height; row++)
  {
    for(int column=0; column<width; column++)
    {
      if(board[row][column].hasMine and board[row][column].isRevealed)
      {
        return FINISHED_LOSS;
      }
      if(board[row][column].isRevealed==false)
      {
        counter++;
      }
    }
  }
  if(counter==getMineCount())
  {
    return FINISHED_WIN;
  }
  return RUNNING;
}
char MinesweeperBoard::getFieldInfo(int row, int col) const
{ 
  int mineAmount=countMines(row, col);

  if(isOutsideBoard(row, col) or (row<0 or col<0))
  return '#';
  else if(board[row][col].isRevealed==false and board[row][col].hasFlag)
  return 'F';
  else if(board[row][col].isRevealed==false and board[row][col].hasFlag==false)
  return '_';
  else if(board[row][col].isRevealed and board[row][col].hasMine)
  return 'x';
  else if(countMines(row, col)==0 and board[row][col].isRevealed)
  return '0';
  else if(countMines(row, col)!=0 and board[row][col].isRevealed)
  {
  char x='0'+mineAmount;
  return x;
  }
}

