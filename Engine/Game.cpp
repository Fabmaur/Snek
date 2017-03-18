/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	brd( gfx ),
	snake( startPos ),
	rng(std::random_device()()),
	apple(rng, brd)
{
	rock[0].init(rng, brd);
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if (start == true) {
		

		if (wnd.kbd.KeyIsPressed(VK_UP)) {
			vector = { 0, -1 };
		}
		else if (wnd.kbd.KeyIsPressed(VK_DOWN)) {
			vector = { 0, 1 };
		}
		else if (wnd.kbd.KeyIsPressed(VK_RIGHT)) {
			vector = { 1, 0 };
		}
		else if (wnd.kbd.KeyIsPressed(VK_LEFT)) {
			vector = { -1, 0 };
		}

		counter++;
	
		if (counter >= frameOverNumber) {
			counter = 0;
			if (apple.checkEaten(snake.getCoord()) == true) {
				
				if (frameOverNumber > 4) {
					frameOverNumber -= 1;
				}
				snake.grow();
				apple.respawn(rng);
			}
			if (snake.isNotTouching() == false) {
				game = false;
			}
			snake.Move(vector);
			if (snake.inGrid()) {

			}
			else {
				game = false;
			}
		}
	}
	else{
		if (wnd.kbd.KeyIsPressed(VK_RETURN)) {
			start = true;
			game = true;
		}
			
	}

}

void Game::ComposeFrame()
{
	if (start == true) {
		second++;
		
		if (second == 60 * seconds) { 
			second = 0;
			currentRock++;
			rock[currentRock].init(rng, brd);
		}
		
		if (game) {
			
			for (int n = 0; n < currentRock; n++) {
				rock[n].Draw(brd);
				if (rock[n].checkTouch(snake.getCoord())) {
					game = false;
				}
			}
			snake.Draw(brd);
			if (apple.checkEaten(snake.getCoord()) == false) {
				apple.Draw();
			}
		}

		else {
			screen.DrawGameOver(300, 265, gfx);
		}
	}
	else {
		screen.DrawTitle(290, 225, gfx);

	}
}