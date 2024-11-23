//
// Created by lukaa on 23.11.2024..
//

#ifndef COLOR_H
#define COLOR_H


namespace mars {
class Color {
    public:
      //! The red component of the color.
      float r;

        //! The green component of the color.
        float g;

        //! The blue component of the color.
        float b;

        //! The alpha component of the color.
        float a;

        //! Returns a new light pink color.
        inline static Color LightPink()  { return Color(1.0f, 0.71f, 0.76f, 1.0f); }
};

}

#endif //COLOR_H
