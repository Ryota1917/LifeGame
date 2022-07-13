#pragma once
#include"Actor.h"
#include<unordered_map>

#define H 70
#define W 93

class StageActor :public  Actor {
public:
	StageActor(Game* game);
	~StageActor();

	void UpdateActor(float deltaTime)override;
	void LastUpdateActor(float deltaTime)override;
	void Draw(SDL_Renderer* renderer)override;

	class Cell* GetCall(int x, int y);

	//ƒwƒ‹ƒp[ŠÖ”
	bool IsOutStage(int x, int y);

private:
	std::unordered_map<int, class Cell*> mCells;

	float mDeltaTotalTime;
	const float mInterval = 0.3f;


};