#include <iostream>
#include "GameEngine.h"

int main()
{
	TDEngine::GameEngine::instance().init();
	TDEngine::GameEngine::instance().gameLoop();
    std::cout << "Hello World!\n"; 
}
