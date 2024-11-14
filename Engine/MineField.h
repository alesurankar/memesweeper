#pragma once

#include "Graphics.h"

class MineField
{
private:
	class Tile
	{
	public:
		enum class State
		{
			Hidden,
			Flagged,
			Revealed
		};
	public:
		void SpawnMine();
		bool HasMine() const;
		void Draw(const Vei2& screenPos, bool gameOver, Graphics& gfx) const;
		void Reveal();
		bool IsRevealed() const;
		void ToggleFlag();
		bool IsFlagged() const;
		void SetNeighborMineCount(int mineCount);
	private:
		State state = State::Hidden;
		bool hasMine = false;
		int nNeighborMines = -1;
	};
public:
	MineField(const Vei2& center, int nMines);
	void Draw(Graphics& gfx) const;
	RectI GetRect() const;
	void OnRevealClick( const Vei2& screenPos );
	void OnFlagClick(const Vei2 screenPos);
private:
	Tile& TileAt(const Vei2& gridPos);
	const Tile& TileAt(const Vei2& gridPos) const;
	Vei2 ScreenToGrid(const Vei2& screenPos);
	int CountNeighborMines(const Vei2& gridPos);
private:
	static constexpr int width = 20;
	static constexpr int height = 16;
	Vei2 topLeft;
	bool gameOver = false;
	Tile field[width * height];
};