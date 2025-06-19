//
// Created by Luka Erkapic on 18.06.25.
//

#ifndef A_TRIANGLE_TEST_PIPELINE_H
#define A_TRIANGLE_TEST_PIPELINE_H

namespace mars {
    //! The test pipeline for rendering a triangle.
    //! Mainly used for testing purposes.
    //! Renders single triangle centered around origin.
    class ATriangleTestPipeline {
    public:
        //! The destructor.
        virtual ~ATriangleTestPipeline() = default;

        //! Render the triangle from the pipeline.
        virtual void render() = 0;

        //! Destroys the pipeline.
        virtual void destroy() = 0;
    };
}

#endif //A_TRIANGLE_TEST_PIPELINE_H
