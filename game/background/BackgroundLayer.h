//
// Created by lukaa on 19.9.2025.

#ifndef BACKGROUNDLAYER_H
#define BACKGROUNDLAYER_H

#include "core/texture/a_texture2d.h"
#include <memory>
#include <core/time/Time.h>
#include <core/sprite/SpriteBatch.h>

class BackgroundLayer {
public:
	BackgroundLayer(std::shared_ptr<mars::ATexture2D> texture, float xSpeed);
	~BackgroundLayer();

	void initialize();
	void update(mars::Time& deltaTime);
	void render(mars::SpriteBatch& spriteBatch);
private:
	std::shared_ptr<mars::ATexture2D> texture;
	float xSpeed;
	std::vector<glm::vec2> positions;


};



#endif //BACKGROUNDLAYER_H
