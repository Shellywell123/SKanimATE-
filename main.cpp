
#include <iostream>
#include <array>
#include <cmath>

//import from other files
#include "transforms.h"
#include "data.h"

int main() {
    double x     = 10;
    double y     = 10;
    double z     = 10;
    double theta = 45;

    std::cout << x << ' '<< y <<' ' << z << std::endl;

    std::array<double,3> coords {x,y,z};
    std::array<double,3> new_coords_x=x_clockwise(coords,theta);

    double X_x = new_coords_x[0];
    double Y_x = new_coords_x[1];
    double Z_x = new_coords_x[2];

    std::cout << X_x << ' '<< Y_x <<' ' << Z_x << std::endl;

    std::array<double,3> new_coords_y=y_clockwise(coords,theta);


    double X_y = new_coords_y[0];
    double Y_y = new_coords_y[1];
    double Z_y = new_coords_y[2];

    std::cout << X_y << ' '<< Y_y <<' ' << Z_y << std::endl;

    std::array<double,3> new_coords_z=z_clockwise(coords,theta);

    double X_z = new_coords_z[0];
    double Y_z = new_coords_z[1];
    double Z_z = new_coords_z[2];

    std::cout << X_z << ' '<< Y_z <<' ' << Z_z << std::endl;

    std::array<double,3> new_coords_c=custom(coords,10,10,10);

    double X_c = new_coords_c[0];
    double Y_c = new_coords_c[1];
    double Z_c = new_coords_c[2];

    std::cout << X_c << ' '<< Y_c <<' ' << Z_c << std::endl;
    std::cout << peak_frame <<std::endl;

    for ( double& x : d_theta_h) { std::cout << ' ' << x; };

    float trick_name = kickflip_info[0];
    for ( double& x : trick_name) { std::cout << ' ' << x; };

    return 0;


}
