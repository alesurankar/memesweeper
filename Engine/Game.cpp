#include "MainWindow.h"
#include "Game.h"
#include "SpriteCodex.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	field(gfx.GetRect().GetCenter(),2)
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
	if (wnd.kbd.KeyIsPressed(VK_RETURN))
	{
		field.SetGameNotOver();
		field = MineField(gfx.GetRect().GetCenter(), 2);
	}
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
	if (field.GameIsWon())
	{
		SpriteCodex::DrawWin(gfx);
	}
	if (field.GameIsLost())
	{
		SpriteCodex::DrawLoose(gfx);
	}
	field.Draw(gfx);
}
