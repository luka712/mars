//
// Created by luka on 12.02.25.
//

#ifndef MATRIX_H
#define MATRIX_H

#include <string>
#include <sstream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace mars {

    //! Print matrix to pretty string.
    //! @param matrix The matrix.
    //! @return The pretty string
    inline std::string toPrettyString(glm::mat4 matrix) {
        std::ostringstream oss;

        for (int i = 0; i < 4; i++) {
            oss << "[";
            for (int j = 0; j < 4; j++) {
                oss << std::to_string(matrix[i][j]);
                if (j != 3) {
                    oss << ", ";
                }
            }
            oss << "]\n";
        }

        return oss.str();
    }

}



#endif //MATRIX_H
