//
// Created by lukaa on 18.1.2025..
//

#include "opengles/util/OpenGLESConverter.h"

namespace mars {

    OpenGLESConverter::OpenGLESConverter(Logger &logger) : logger(logger) {
    }

    GLenum OpenGLESConverter::convertToGLHint(BufferUsage usage) {
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
                logger.error("Unknown buffer usage.");
                return GL_STATIC_DRAW;
        }
    }
}