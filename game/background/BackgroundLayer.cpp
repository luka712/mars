//
// Created by lukaa on 19.9.2025..
//

#include "BackgroundLayer.h"
#include "GameConstants.h"
#include "Background.h"


BackgroundLayer::BackgroundLayer(std::shared_ptr<mars::ATexture2D> texture, float xSpeed)
	: texture(texture), xSpeed(xSpeed)
{
}

BackgroundLayer::~BackgroundLayer()
{
}

void BackgroundLayer::initialize()
{
	if (xSpeed == 0)
	{
		positions.push_back(glm::vec2(0, 0));
	}
	else
	{
		positions.push_back(glm::vec2(0, 0));
		positions.push_back(glm::vec2(GameConstants::getResolution().x, 0));
	}
}

void BackgroundLayer::update(mars::Time& gameTime)
{
	float move = xSpeed * gameTime.getDeltaTimeMS();

	for (size_t i = 0; i < positions.size(); i++)
	{
		glm::vec2 position = positions[i];

		position.x -= move;

		if (position.x <= -GameConstants::getResolution().x)
		{
			position.x = GameConstants::getResolution().x;
		}

		positions[i] = position;
	}
}

void BackgroundLayer::render(mars::SpriteBatch& spriteBatch)
{
	for (glm::vec2 pos : positions)
	{
		mars::Rect rect = mars::Rect(
			(int)pos.x, (int)pos.y,
			(int)GameConstants::getResolution().x, (int)GameConstants::getResolution().y);
		spriteBatch.draw(texture.get(), rect, mars::Color::white());
	}
}
