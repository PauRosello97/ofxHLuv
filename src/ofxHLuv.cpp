#include "ofxHLuv.h"

ofColor ofxHLuv::getColor(float hue, float luminance) {
    double k = 0.0011070564598794539; //(3/29)^3.
    double maxS = 93.727325; // Max Saturation.
    float kL = 7.67; // A constant to adjust the luminance curve.

    float S = 0;
    float L = kL * sqrt(luminance); // From exponential to lineal luminance.

    // We add 19.06 to the hue so hue=0 is red as in the HSB mode (optional).
    float H = hue + 19.06;
    if (L >= 73 || L == 0) {
        S = 0;
    }
    else if (73 > L&& L > 57) {
        S = 93.727325 - maxS * (L - 57) / 16;
    }
    else if (57 >= L) {
        S = L * maxS / 57;
    }

    // U and V values are calculated drawing a circle which radius is S
    // so we'll get the color whose distance to the center is S and
    // its position in the circle is H (hue).
    float U = S * cos(H * PI / 180);
    float V = S * sin(H * PI / 180);

    // Now we transform the LUV color into XYZ.
    float X, Y, Z;

    // We adjust luminance from a 0-50 to a 0-100 range.
    L *= 2;

    // And we do the calculations to transform the color from CIELUV to CIEXYZ
    // as the CIE has published.
    if (L != 0) {
        float un = 0.2009;
        float vn = 0.4610;
        float Xn = 0.312713;
        float Yn = 0.329016;
        float u = U / (13.0 * L) + un;
        float v = V / (13.0 * L) + vn;
        if (L <= 8) {
            Y = Yn * L * k;
        }
        else {
            Y = Yn * pow((L + 16) / 116.0, 3);
        }
        X = (Y * 9 * u) / (4.0 * v);
        Z = Y * (12 - 3 * u - 20 * v) / (4 * v);
    }
    else {
        X = 0;
        Y = 0;
        Z = 0;
    }

    // Now we transform the XYZ color to RGB using the CIE documentation.
    float R = +3.2406 * X - 1.5372 * Y - 0.4986 * Z;
    float G = -0.9689 * X + 1.8758 * Y + 0.0415 * Z;
    float B = +0.0555 * X - 0.2040 * Y + 1.0570 * Z;

    // We transform the RGB range from [0-1], to [0-255] trying not to get
    // values greater than 255.
    // (The constants are not exact so we could get impossible colors).
    R = R * 255 > 255 ? 255 : R * 255;
    G = G * 255 > 255 ? 255 : G * 255;
    B = B * 255 > 255 ? 255 : B * 255;
    // We'll also delete negative values.
    R = R < 0 ? 0 : R;
    G = G < 0 ? 0 : G;
    B = B < 0 ? 0 : B;

    return ofColor(R, G, B);
}