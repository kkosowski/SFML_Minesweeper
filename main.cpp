#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include <iostream>
#include "MinesweeperBoard.h"
#include "MSTextController.h"
#include "MSBoardTextView.h"
#include "MSSFMLView.h"

using namespace sf;

int main()
{

 
sf::RenderWindow window(VideoMode(800,600),"Saper");
window.setFramerateLimit(10);

MinesweeperBoard board(5,5,HARD);
board.debug_display();

MSSFMLView view(board);

while(window.isOpen())
{
   sf::Event event;
    while (window.pollEvent(event))
    {
      if(event.type == sf::Event::Closed) 
      window.close();

      if(event.type==Event::MouseButtonPressed)
      {
        int row=(event.mouseButton.y-50)/51;
        int column=(event.mouseButton.x-50)/51;
        
        if(event.mouseButton.button==Mouse::Left)
        {
          board.revealField(row, column);
          board.getGameState();
        }

        if(event.mouseButton.button==Mouse::Right)
        {
          board.toggleFlag(row, column);
          board.getGameState();
        }
      }	
    }

  window.clear();
  view.draw(window);
  window.display();
}

} 



