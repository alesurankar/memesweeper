#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	field(20)
{
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
	if (wnd.mouse.LeftIsPressed())
	{
		const Vei2 mousePos = wnd.mouse.GetPos();
		if (field.GetRect().Contains(mousePos))
		{
			field.OnRevealClick(mousePos);
		}
	}
}

void Game::ComposeFrame()
{
	field.Draw(gfx);
}
