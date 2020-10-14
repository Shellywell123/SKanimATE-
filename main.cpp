
#include <iostream>
#include <array>
#include <vector>
#include <cmath>

//import from other files
//#include "transforms.h"
#include "data.h"

int main() {
    // double x     = 10;
    // double y     = 10;
    // double z     = 10;
    // double theta = 45;

    // std::cout << x << ' '<< y <<' ' << z << std::endl;

    // std::array<double,3> coords {x,y,z};
    // std::array<double,3> new_coords_x=x_clockwise(coords,theta);

    // double X_x = new_coords_x[0];
    // double Y_x = new_coords_x[1];
    // double Z_x = new_coords_x[2];

    // std::cout << "\nx_clockwise" << std::endl;
    // std::cout << X_x << ' '<< Y_x <<' ' << Z_x << std::endl;

    // std::array<double,3> new_coords_y=y_clockwise(coords,theta);


    // double X_y = new_coords_y[0];
    // double Y_y = new_coords_y[1];
    // double Z_y = new_coords_y[2];

    // std::cout << "\ny_clockwise" << std::endl;
    // std::cout << X_y << ' '<< Y_y <<' ' << Z_y << std::endl;

    // std::array<double,3> new_coords_z=z_clockwise(coords,theta);

    // double X_z = new_coords_z[0];
    // double Y_z = new_coords_z[1];
    // double Z_z = new_coords_z[2];
    // std::cout << "\nz_clockwise" << std::endl;
    // std::cout << X_z << ' '<< Y_z <<' ' << Z_z << std::endl;

    // std::array<double,3> new_coords_c=custom(coords,10,10,10);

    // double X_c = new_coords_c[0];
    // double Y_c = new_coords_c[1];
    // double Z_c = new_coords_c[2];

    // std::cout << "\ncustom_clockwise" << std::endl;
    // std::cout << X_c << ' '<< Y_c <<' ' << Z_c << std::endl;

    std::cout << "\npeak frame" << std::endl;
    std::cout << peak_frame <<std::endl;

    std::cout << "\ntheta h" << std::endl;
    for ( double& x : d_theta_h) { std::cout << ' ' << x; };

    std::cout << "\nkicklfip info" << std::endl;

    std::vector<double> trick_name   = kickflip_info["trick name"];
    std::vector<double> x_rot_angles = kickflip_info["x_rot_angles"];
    std::vector<double> y_rot_angles = kickflip_info["y_rot_angles"];
    std::vector<double> z_rot_angles = kickflip_info["z_rot_angles"];
    std::vector<double> h_rot_angles = kickflip_info["h_rot_angles"];
    std::vector<double> r_rot_angles = kickflip_info["r_rot_angles"];

    std::cout << "\nname" << std::endl;
    for ( double& x : trick_name) { std::cout << ' ' << x; };

    std::cout << "\nx_rot_anglest" << std::endl;
    for ( double& x : x_rot_angles) { std::cout << ' ' << x; };
    
    std::cout << "\ny_rot_angles" << std::endl;
    for ( double& x : y_rot_angles) { std::cout << ' ' << x; };
    
    std::cout << "\nz_rot_angles" << std::endl;
    for ( double& x : z_rot_angles) { std::cout << ' ' << x; };
    
    std::cout << "\nh_rot_angles" << std::endl;
    for ( double& x : h_rot_angles) { std::cout << ' ' << x; };

    std::cout << "\nr_rot_angles" << std::endl;
    for ( double& x : r_rot_angles) { std::cout << ' ' << x; };

    return 0;

};
