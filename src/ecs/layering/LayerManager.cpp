//
// Created by Erkapic Luka on 21.1.2025.
//

#include <stdexcept>
#include <algorithm>
#include "Framework.h"
#include "ecs/layering/LayerManager.h"

namespace mars {
    LayerManager::LayerManager(Framework &framework) : framework(framework) {
        defaultLayer = createLayer("Default", 0, "The default layer for all scene elements.");
    }

    std::shared_ptr<Layer> LayerManager::createLayer(std::string name, const uint32_t order, std::string description) {
        for (const auto &layer: layers) {
            if (layer->getName() == name) {
                const std::string msg = "Layer with name " + name + " already exists.";
                framework.getLogger().error(msg.c_str());
                throw std::runtime_error(msg);
            }
        }

        auto layer = std::make_shared<Layer>(std::move(name), order, std::move(description));
        layers.push_back(layer);

        std::ranges::sort(layers, [&](const std::shared_ptr<Layer> &a, const std::shared_ptr<Layer> &b) {
            return a->getOrder() < b->getOrder();
        });

        return layer;
    }
}
