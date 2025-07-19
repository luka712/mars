//
// Created by Erkapic Luka on 23.11.2024.
//

#ifndef COLOR_H
#define COLOR_H

namespace mars {
    struct Color {
        Color(float r, float g, float b, float a = 1.0f);

        Color();


        //! The red component of the color.
        float r;

        //! The green component of the color.
        float g;

        //! The blue component of the color.
        float b;

        //! The alpha component of the color.
        float a;

        //! Returns a new white color.
        static Color white() { return Color(1.0f, 1.0f, 1.0f, 1.0f); }

        //! Returns a new red color.
        static Color red() { return Color(1.0f, 0.0f, 0.0f ,1.0f); }

        //! Returns a new green color.
        static Color green() { return Color(0.0f, 1.0f, 0.0f, 1.0f); }

        //! Returns a new blue color.
        static Color blue() { return Color(0.0f, 0.0f, 1.0f, 1.0f); }

        //! Returns a new black color.
        static Color black() { return Color(0.0f, 0.0f, 0.0f, 1.0f); }

        //! Returns a new yellow color.
        static Color yellow() { return Color(1.0f, 1.0f, 0.0f, 1.0f); }

        //! Returns a new light pink color.
        static Color lightPink() { return Color(1.0f, 0.71f, 0.76f, 1.0f); }
    };
}

#endif //COLOR_H
