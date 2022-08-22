#include "MSSFMLView.h"
#include "SFML/Graphics.hpp"


MSSFMLView::MSSFMLView(MinesweeperBoard & board) : board(board)
{
 
}

void MSSFMLView::draw (sf::RenderWindow & win)
{


  
  sf::Texture UnrevealedTexture;
  sf::Texture RevealedTexture;

  sf::Texture ZeroTexture;
  sf::Texture OneTexture;
  sf::Texture TwoTexture;
  sf::Texture ThreeTexture;
  sf::Texture FourTexture;
  sf::Texture FiveTexture;
  sf::Texture SixTexture;
  sf::Texture SevenTexture;
  sf::Texture EightTexture;

  sf::Texture FlagTexture;
  sf::Texture BombTexture;

  sf::Texture YouWon;
  sf::Texture YouLose;

  UnrevealedTexture.loadFromFile("../resources/icons/unrevealed.png");
  RevealedTexture.loadFromFile("../resources/icons/0.png");
  ZeroTexture.loadFromFile("../resources/icons/0.png");
  OneTexture.loadFromFile("../resources/icons/1.png");
  TwoTexture.loadFromFile("../resources/icons/2.png");
  ThreeTexture.loadFromFile("../resources/icons/3.png");
  FourTexture.loadFromFile("../resources/icons/4.png");
  FiveTexture.loadFromFile("../resources/icons/5.png");
  SixTexture.loadFromFile("../resources/icons/6.png");
  SevenTexture.loadFromFile("../resources/icons/7.png");
  EightTexture.loadFromFile("../resources/icons/8.png");

  FlagTexture.loadFromFile("../resources/icons/flag.png");
  BombTexture.loadFromFile("../resources/icons/bomb.png");

  YouWon.loadFromFile("../resources/icons/youwon.png");
  YouLose.loadFromFile("../resources/icons/youlose.png");

  if(board.getGameState()==FINISHED_WIN)
  {
   sf::Sprite Winning;
   Winning.setTexture(YouWon);
   Winning.setPosition(400,100);
   win.draw(Winning);

  } 

  if(board.getGameState()==FINISHED_LOSS)
  {
    sf::Sprite Lost;
    Lost.setTexture(YouLose);
    Lost.setPosition(400,100);
    win.draw(Lost);
  }
 
	
  for (int row = 0; row<board.getBoardHeight(); row++)
  {
    for (int column =0; column<board.getBoardWidth(); column++)
    {
      int x=50+51*column;
      int y=50+51*row;

      

      

      if(board.getFieldInfo(row,column)=='_')
      {
        sf::Sprite UnrevealedField;
        UnrevealedField.setTexture(UnrevealedTexture);
        UnrevealedField.setPosition(x,y);
        win.draw(UnrevealedField);
      }

      if(board.getFieldInfo(row,column)=='x')
      {
        sf::Sprite BombField;
        BombField.setTexture(BombTexture);
        BombField.setPosition(x,y);
        win.draw(BombField);
      }

      if(board.getFieldInfo(row,column)=='F')
      {
        sf::Sprite FlagField;
        FlagField.setTexture(FlagTexture);
        FlagField.setPosition(x,y);
        win.draw(FlagField);

      }

      if(board.getFieldInfo(row,column)=='0')
      {
        sf::Sprite ZeroField;
        ZeroField.setTexture(ZeroTexture);
        ZeroField.setPosition(x,y);
        win.draw(ZeroField);
      }

      if(board.getFieldInfo(row,column)=='1')
      {
        sf::Sprite OneField;
        OneField.setTexture(OneTexture);
        OneField.setPosition(x,y);
        win.draw(OneField);
      }

      if(board.getFieldInfo(row,column)=='2')
      {
        sf::Sprite TwoField;
        TwoField.setTexture(TwoTexture);
        TwoField.setPosition(x,y);
        win.draw(TwoField);
      }

      if(board.getFieldInfo(row,column)=='3')
      {
        sf::Sprite ThreeField;
        ThreeField.setTexture(ThreeTexture);
        ThreeField.setPosition(x,y);
        win.draw(ThreeField);
      }

      if(board.getFieldInfo(row,column)=='4')
      {
        sf::Sprite FourField;
        FourField.setTexture(FourTexture);
        FourField.setPosition(x,y);
        win.draw(FourField);
      }

      if(board.getFieldInfo(row,column)=='5')
      {
        sf::Sprite FiveField;
        FiveField.setTexture(FiveTexture);
        FiveField.setPosition(x,y);
        win.draw(FiveField);
      }

      if(board.getFieldInfo(row,column)=='6')
      {
        sf::Sprite SixField;
        SixField.setTexture(SixTexture);
        SixField.setPosition(x,y);
        win.draw(SixField);
      }

      if(board.getFieldInfo(row,column)=='7')
      {
        sf::Sprite SevenField;
        SevenField.setTexture(SevenTexture);
        SevenField.setPosition(x,y);
        win.draw(SevenField);
      }

      if(board.getFieldInfo(row,column)=='8')
      {
        sf::Sprite EightField;
        EightField.setTexture(EightTexture);
        EightField.setPosition(x,y);
        win.draw(EightField);
      }
      
    }       
  }
}
