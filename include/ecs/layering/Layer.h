//
// Created by lukaa on 21.1.2025..
//

#ifndef LAYER_H
#define LAYER_H

#include <memory>
#include <string>
#include <utility>

namespace mars {
    //! The Layer class represents a layer in the ECS (Entity-Component-System) architecture.
    class Layer {
    public:
        //! Construct a new SpriteLayer object.
        //! @param name The name of the layer.
        //! @param order The order of the layer.
        //! @param description The description of the layer.
        Layer(std::string name, uint32_t order, std::string description);

        //! The layer name.
        //! @return The name of the layer.
        [[nodiscard]] const std::string& getName() const { return name; }

        //! The order of the layer. Lower order means the layer is rendered first.
        //! @return The order of the layer.
        [[nodiscard]] uint32_t getOrder() const { return order; }

        //! The description of the layer.
        //! @return The description of the layer.
        [[nodiscard]] const std::string& getDescription() const { return description; }

    protected:
        std::string name;
        uint32_t order;
        std::string description;
    };
}


#endif //LAYER_H
