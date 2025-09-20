//
// Created by lukaa on 20.9.2025..
//

#include "Background.h"

Background::Background(mars::ContentManager& contentManager)
	: contentManager(contentManager)
{
	addLayer("Background", 0);
	addLayer("Background2", 0.03f);
	addLayer("Background3", 0.06f);
	addLayer("Background4", 0.1f);
}

Background::~Background()
{
	for (auto& layer : layers)
	{
		delete layer;
	}
	layers.clear();
}


BackgroundLayer& Background::addLayer(std::string layerSprite, float xSpeed)
{
	BackgroundLayer* backgroundLayer = new BackgroundLayer(
		contentManager.load<mars::ATexture2D>("images/" + layerSprite + ".png"),
		xSpeed);
	backgroundLayer->initialize();
	layers.push_back(backgroundLayer);
	return *backgroundLayer;
}

void Background::update(mars::Time& time)
{
	for (auto& layer : layers)
	{
		layer->update(time);
	}
}

void Background::render(mars::SpriteBatch& spriteBatch)
{
	for (auto& layer : layers)
	{
		layer->render(spriteBatch);
	}
}  