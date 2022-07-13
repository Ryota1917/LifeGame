#include"StageActor.h"
#include"Cell.h"
#include"Game.h"
#include<cstdlib>

StageActor::StageActor(Game *game):
	Actor(game),mDeltaTotalTime(0)
{
	std::srand(12345679);

	for (int h = 0; h < H; h++) {
		for (int w = 0; w < W; w++) {
			Cell::CellState state = (rand() % 8 >3 ) ? Cell::CellState::EALIVE : Cell::CellState::EDEAD;
			Cell* cell = new Cell(state, this, w, h);

			mCells[cell->GetY() * W + cell->GetX()] = cell;
		}
	}
}

StageActor::~StageActor() {
	for (auto cell : mCells) {
		delete cell.second;
	}
}

void StageActor::UpdateActor(float deltaTime) {
	mDeltaTotalTime += deltaTime;

	if (mDeltaTotalTime > mInterval) {
		for (auto cell : mCells) {
			cell.second->UpdateActor(deltaTime);
		}
		mDeltaTotalTime = 0;
	}
}

void StageActor::LastUpdateActor(float deltaTime) {
	for (auto cell : mCells) {
		cell.second->LastUpdateActor(deltaTime);
	}
}

void StageActor::Draw(SDL_Renderer* renderer) {
	for (auto cell : mCells) {
		cell.second->Draw(renderer);
	}
}

Cell* StageActor::GetCall(int x, int y) {
	return mCells[y * W + x];
}

bool StageActor::IsOutStage(int x, int y) {
	return (x < 0 || x >= W || y < 0 || y >= H) ?
		true : false;
}