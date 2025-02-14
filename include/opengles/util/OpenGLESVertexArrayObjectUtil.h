//
// Created by luka on 14.02.25.
//

#ifndef OPENGLES_VERTEX_ARRAY_OBJECT_UTIL_H
#define OPENGLES_VERTEX_ARRAY_OBJECT_UTIL_H

#include <string>
#include "opengles/opengles.h"

namespace mars {
    //! The utility class for Vertex Array Object.
    class OpenGLESVertexArrayObjectUtil {
    public:
        //! Create vertex array object.
        //! @param label The label.
        //! @returns The vertex array object.
        GLuint create(const std::string& label);
    };
}


#endif //OPENGLES_VERTEX_ARRAY_OBJECT_UTIL_H
