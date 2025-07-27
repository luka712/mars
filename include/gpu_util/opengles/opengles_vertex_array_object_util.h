//
// Created by Erkapic Luka on 14.02.25.
//

#ifndef OPENGLES_VERTEX_ARRAY_OBJECT_UTIL_H
#define OPENGLES_VERTEX_ARRAY_OBJECT_UTIL_H

#include "gpu_util/opengles.h"
#include "gpu_util/logger.h"

namespace gpu_util {
    //! The utility class for Vertex Array Object.
    class OpenGLESVertexArrayObjectUtil {
    public:
        //! Create vertex array object.
        //! @param label The label.
        //! @returns The vertex array object.
        GLuint create(const std::string& label);

        //! Creates a vertex array object which is configured to use position of 3 components
        //! color of 4 components and texture coordinate of two components using interleaved buffer.
        GLuint createPositionColorTextureCoordinatesVAO(GLuint interleavedBuffer, const std::string& label);
    };
}


#endif //OPENGLES_VERTEX_ARRAY_OBJECT_UTIL_H
