
#include <iostream>
#include <array>
#include <cmath>
#include "transforms.h"

int main() {
    float x     = 10;
    float y     = 10;
    float z     = 10;
    float theta = 45;

    std::cout << x << ' '<< y <<' ' << z << std::endl;

    std::array<float,3> coords {x,y,z};
    std::array<float,3> new_coords_x=x_clockwise(coords,theta);

    float X_x = new_coords_x[0];
    float Y_x = new_coords_x[1];
    float Z_x = new_coords_x[2];

    std::cout << X_x << ' '<< Y_x <<' ' << Z_x << std::endl;

    std::array<float,3> new_coords_y=y_clockwise(coords,theta);


    float X_y = new_coords_y[0];
    float Y_y = new_coords_y[1];
    float Z_y = new_coords_y[2];

    std::cout << X_y << ' '<< Y_y <<' ' << Z_y << std::endl;

    std::array<float,3> new_coords_z=z_clockwise(coords,theta);

    float X_z = new_coords_z[0];
    float Y_z = new_coords_z[1];
    float Z_z = new_coords_z[2];

    std::cout << X_z << ' '<< Y_z <<' ' << Z_z << std::endl;

    std::array<float,3> new_coords_c=custom(coords,10,10,10);

    float X_c = new_coords_c[0];
    float Y_c = new_coords_c[1];
    float Z_c = new_coords_c[2];

    std::cout << X_c << ' '<< Y_c <<' ' << Z_c << std::endl;
    return 0;
}