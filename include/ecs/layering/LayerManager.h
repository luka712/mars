//
// Created by lukaa on 21.1.2025..
//

#ifndef LAYERMANAGER_H
#define LAYERMANAGER_H

#include <vector>
#include "ecs/layering/Layer.h"

namespace mars {
    class Framework;

    //! The LayerManager class.
    //! Contains all created layers.
    class LayerManager {
    public:
        //! Construct a new LayerManager object.
        //! @param framework The framework.
        explicit LayerManager(Framework& framework);

        //! Creates a new layer with the specified name, order, and description.
        //! @param name The name of the layer.
        //! @param order The order of the layer.
        //! @param description The description of the layer.
        //! @return The created layer.
        std::shared_ptr<Layer> createLayer(std::string name, uint32_t order, std::string description);

        //! Get the default layer.
        //! @return The default layer.
        [[nodiscard]] const std::shared_ptr<Layer>& getDefaultLayer() const { return defaultLayer; }

        //! Get all layers.
        //! @return All layers.
        [[nodiscard]] const std::vector<std::shared_ptr<Layer>>& getLayers() { return layers; }

    private:
        Framework& framework;
        std::shared_ptr<Layer> defaultLayer;
        std::vector<std::shared_ptr<Layer>> layers;
    };
}


#endif //LAYERMANAGER_H
