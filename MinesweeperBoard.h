#ifndef MinesweeperBoard_H__
#define MinesweeperBoard_H__
#include "Array2D.h"

enum GameMode  { DEBUG, EASY, NORMAL, HARD };
enum GameState { RUNNING, FINISHED_WIN, FINISHED_LOSS };

struct Field
{
	bool hasMine;
	bool hasFlag;
	bool isRevealed;
};

class MinesweeperBoard
{
  Field board[100][100];
  //Array2D<Field> board;
  
  int width;                // rzeczywista szerokość planszy
  int height;               // rzeczywista wysokość planszy

  int game_state;           //stan gry
  GameMode game_mode;

public:
  MinesweeperBoard(int width, int height, GameMode mode);  
  void debug_display() const;
  //Etap2
  int getBoardWidth() const;//
  int getBoardHeight() const;//
  int getMineCount() const;//
  

  int countMines(int row, int col) const;//

  bool hasFlag(int row, int col) const;//

  bool hasMine(int row, int col) const;//

  void toggleFlag(int row, int col);//
  
  void revealField(int row, int col);

  bool isFirstAction() const;//Sprawdza czy gracz wykonał 1 ruch

  bool isOutsideBoard(int row, int col) const;//Sprawdza czy podane parametry sa poza polem

  bool isRevealed(int row, int col) const;//

  GameState getGameState() const;//

  char getFieldInfo(int row, int col) const;//

};

#endif