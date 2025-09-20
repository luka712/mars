//
// Created by lukaa on 20.9.2025.
//

#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "BackgroundLayer.h"
#include "core/content/ContentManager.h"

class Background {
public:
    Background(mars::ContentManager& contentManager);
    ~Background();

    void update(mars::Time& deltaTime);
    void render(mars::SpriteBatch& spriteBatch);
private:
	mars::ContentManager& contentManager;
	std::vector<BackgroundLayer*> layers;

    BackgroundLayer& addLayer(std::string layerSprite, float xSpeed);
};



#endif //BACKGROUND_H
