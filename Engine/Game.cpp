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
	while (!wnd.mouse.IsEmpty())
	{
		const auto e = wnd.mouse.Read();
		if (e.GetType() == Mouse::Event::Type::LPress)
		{
			const Vei2 mousePos = e.GetPos();
			if (field.GetRect().Contains(mousePos))
			{
				field.OnRevealClick(mousePos);
			}
		}
		else if (e.GetType() == Mouse::Event::Type::RPress)
		{
			const Vei2 mousePos = e.GetPos();
			if (field.GetRect().Contains(mousePos))
			{
				field.OnFlagClick(mousePos);
			}
		}
	}
}

void Game::ComposeFrame()
{
	field.Draw(gfx);
}
