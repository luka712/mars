//
// Created by Erkapic Luka on 18.1.2025.
//

#include "opengles/util/opengles_converter.h"
#include <stdexcept>
#include <string>

namespace mars {

    GLenum OpenGLESConverter::convertToGLHint(const BufferUsage usage) {
        switch (usage) {
            case BufferUsage::Vertex:
                return GL_STATIC_DRAW;
            case BufferUsage::Index:
                return GL_STATIC_DRAW;
            case BufferUsage::Uniform:
                return GL_STATIC_DRAW;
            case BufferUsage::CopyDst:
                return GL_DYNAMIC_DRAW;
            case BufferUsage::Vertex_CopyDst:
                return GL_DYNAMIC_DRAW;
            default:
                std::string msg = "Unsupported buffer usage: " + std::to_string(static_cast<int>(usage));
                throw std::runtime_error(msg);
        }
    }
}