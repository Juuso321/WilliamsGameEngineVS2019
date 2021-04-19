#pragma once

#include "Engine/GameEngine.h"

class GameScene : public Scene {
 public:
  GameScene();
};

typedef std::shared_ptr<GameScene> GameScenePtr;
