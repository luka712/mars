//
// Created by lukaa on 20.9.2025..
//

#ifndef GAMECONSTANTS_H
#define GAMECONSTANTS_H

#include <glm/glm.hpp>

struct GameConstants
{
	static glm::vec2 getResolution();

private:
	static glm::vec2 resolution;
};

#endif //GAMECONSTANTS_H
