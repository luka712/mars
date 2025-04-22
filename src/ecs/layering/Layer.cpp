//
// Created by lukaa on 21.1.2025..
//

#include <utility>

#include "ecs/layering/Layer.h"

namespace mars {
    Layer::Layer(std::string name, const uint32_t order, std::string description) {
        this->name = std::move(name);
        this->order = order;
        this->description = std::move(description);
    }

}
