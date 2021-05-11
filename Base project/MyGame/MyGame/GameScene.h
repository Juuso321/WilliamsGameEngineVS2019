#pragma once

#include "Engine/GameEngine.h"

class GameScene : public Scene {
 public:
  GameScene();
  int getLives();
  
  void decreaseLives();

  int getScore();
  void increaseScore();
private:
	int lives_ = 3;

	int score_ = 0;
};

typedef std::shared_ptr<GameScene> GameScenePtr;
