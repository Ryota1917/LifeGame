#include"Cell.h"
#include"StageActor.h"
#include<vector>

Cell::Cell(CellState state,StageActor *stage,int x,int y):
	mPreCellState(state),mCellState(state),mStage(stage),mX(x),mY(y)
{

}

void Cell::UpdateActor(float deitaTime) {
	//mCellStateをmPreCellStateを使って更新する
	int count = CountAroundAliveCell();
	if (mPreCellState == CellState::EALIVE) {
		mCellState = count == 2 || count == 3 ? CellState::EALIVE : CellState::EDEAD;
	}
	else {
		mCellState = count == 3 ? CellState::EALIVE : CellState::EDEAD;
	}
}
void Cell::LastUpdateActor(float deltaTime) {
	//mPreCellStateをセットしておく
	mPreCellState = mCellState;
}

void Cell::Draw(SDL_Renderer* renderer) {
	if (mCellState == CellState::EALIVE) {
		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	}
	else if (mCellState == CellState::EDEAD) {
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	}

	SDL_Rect rect{ mX * (THICKNESS + 1),mY * (THICKNESS + 1),THICKNESS,THICKNESS };
	SDL_RenderFillRect(renderer, &rect);
}

int Cell::CountAroundAliveCell() {
	std::vector<std::pair<int, int>> arounds{
		{-1,-1},{0,-1},{1,-1},{-1,0},{1,0},{-1,1},{0,1},{1,1}
	};
	int count = 0;
	for (auto around : arounds) {
		int x = mX + around.first;
		int y = mY + around.second;

		if (!mStage->IsOutStage(x, y)) {
			count += mStage->GetCall(x, y)->GetPreCellState() == CellState::EALIVE ? 1 : 0;
		}
	}
	return count;
}