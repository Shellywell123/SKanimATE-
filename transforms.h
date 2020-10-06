
#include <iostream>
#include <array>
#include <cmath>

//#############################################################

double degrees_to_radians(double angle_deg)
    {
        double angle_rad = double(angle_deg/180)*M_PI;
        return angle_rad;
    }

//#############################################################

std::array<double,3> x_clockwise(std::array<double,3> old_coords, double theta)
	{
		double x = old_coords[0];
		double y = old_coords[1];
		double z = old_coords[2];

        double theta_rad = degrees_to_radians(theta);
        
        double X =  x;
        double Y = -z*sin(theta_rad)+y*cos(theta_rad);
        double Z =  z*cos(theta_rad)+y*sin(theta_rad);

        std::array<double,3> new_coords {X,Y,Z};

        return new_coords;
	}

//#############################################################

std::array<double,3> y_clockwise(std::array<double,3> old_coords, double theta)
	{
		double x = old_coords[0];
		double y = old_coords[1];
		double z = old_coords[2];

        double theta_rad = degrees_to_radians(theta);
        
        double X =  x*cos(theta_rad)+z*sin(theta_rad);
        double Y = -y;
        double Z =  -x*sin(theta_rad)+z*cos(theta_rad);

        std::array<double,3> new_coords {X,Y,Z};

        return new_coords;
	}

// //#############################################################

std::array<double,3> z_clockwise(std::array<double,3> old_coords, double theta)
	{
		double x = old_coords[0];
		double y = old_coords[1];
		double z = old_coords[2];

        double theta_rad = degrees_to_radians(theta);
        
        double X =  x*cos(theta_rad)+y*sin(theta_rad);
        double Y = -x*sin(theta_rad)+y*cos(theta_rad);
        double Z =  z;

        std::array<double,3> new_coords {X,Y,Z};

        return new_coords;
	}

// //#############################################################

std::array<double,3> custom(std::array<double,3> coords, double theta_x, double theta_y, double theta_z)
	{
        std::array<double,3> x_coord_trans   = x_clockwise(coords,theta_x);
        std::array<double,3> xy_coord_trans  = y_clockwise(x_coord_trans,theta_y);
        std::array<double,3> xyz_coord_trans = z_clockwise(xy_coord_trans,theta_z);
     	return xyz_coord_trans;
	}

// //#############################################################

std::array<double,3> ollie_motion(std::array<double,3> coords, double theta_h, double theta_r)
	{	
		double max_ollie_height = 35;
		std::array<double,3> new_coords = x_clockwise(coords,theta_r);
		double theta_h_rad = degrees_to_radians(theta_h);
		double current_hieght = max_ollie_height*sin(theta_h_rad);

		// add height to z coord
		new_coords[2] = new_coords[2] + current_hieght;

		return new_coords;
	}

// //#############################################################

std::array<double,3> nollie_motion(std::array<double,3> coords, double theta_h, double theta_r)
	{	
		double max_nollie_height = 35;
		std::array<double,3> new_coords = x_clockwise(coords,-theta_r);
		double theta_h_rad = degrees_to_radians(theta_h);
		double current_hieght = max_nollie_height*sin(theta_h_rad);

		// add height to z coord
		new_coords[2] = new_coords[2] + current_hieght;

		return new_coords;
	}

// //#############################################################

