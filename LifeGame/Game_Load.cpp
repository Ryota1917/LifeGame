#include"Game.h"
#include"Actor.h"
#include"StageActor.h"

void Game::LoadData() {
	AddActor(new StageActor(this));
}

void Game::UnloadData() {

}