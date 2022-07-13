#pragma once
#include"Actor.h"

#define THICKNESS 10

class Cell {
public:
	enum class CellState
	{
		EALIVE,
		EDEAD
	};

	Cell(CellState state,class StageActor *stage,int x,int y);

	void UpdateActor(float deltaTime);
	void LastUpdateActor(float deltaTime);
	void Draw(SDL_Renderer* renderer);

	CellState GetPreCellState() { return mPreCellState; }

	int GetX(){ return mX; }
	int GetY() { return mY; }

private:
	int mX;
	int mY;

	CellState mPreCellState;
	CellState mCellState;
	class StageActor* mStage;

	int CountAroundAliveCell();
};