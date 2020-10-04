
#include <iostream>
#include <array>
#include <cmath>

//#############################################################

float degrees_to_radians(float angle_deg)
    {
        float angle_rad = float(angle_deg/180)*M_PI;
        return angle_rad;
    }

//#############################################################

std::array<float,3> x_clockwise(std::array<float,3> old_coords, float theta)
	{
		float x = old_coords[0];
		float y = old_coords[1];
		float z = old_coords[2];

        float theta_rad = degrees_to_radians(theta);
        
        float X =  x;
        float Y = -z*sin(theta_rad)+y*cos(theta_rad);
        float Z =  z*cos(theta_rad)+y*sin(theta_rad);

        std::array<float,3> new_coords {X,Y,Z};

        return new_coords;
	}

//#############################################################

std::array<float,3> y_clockwise(std::array<float,3> old_coords, float theta)
	{
		float x = old_coords[0];
		float y = old_coords[1];
		float z = old_coords[2];

        float theta_rad = degrees_to_radians(theta);
        
        float X =  x*cos(theta_rad)+z*sin(theta_rad);
        float Y = -y;
        float Z =  -x*sin(theta_rad)+z*cos(theta_rad);

        std::array<float,3> new_coords {X,Y,Z};

        return new_coords;
	}

// //#############################################################

std::array<float,3> z_clockwise(std::array<float,3> old_coords, float theta)
	{
		float x = old_coords[0];
		float y = old_coords[1];
		float z = old_coords[2];

        float theta_rad = degrees_to_radians(theta);
        
        float X =  x*cos(theta_rad)+y*sin(theta_rad);
        float Y = -x*sin(theta_rad)+y*cos(theta_rad);
        float Z =  z;

        std::array<float,3> new_coords {X,Y,Z};

        return new_coords;
	}

// //#############################################################

std::array<float,3> custom(std::array<float,3> coords, float theta_x, float theta_y, float theta_z)
	{
        std::array<float,3> x_coord_trans   = x_clockwise(coords,theta_x);
        std::array<float,3> xy_coord_trans  = y_clockwise(x_coord_trans,theta_y);
        std::array<float,3> xyz_coord_trans = z_clockwise(xy_coord_trans,theta_z);
     	return xyz_coord_trans;
	}

// //#############################################################

std::array<float,3> ollie_motion(std::array<float,3> coords, float theta_h, float theta_r)
	{	
		float max_ollie_height = 35;
		std::array<float,3> new_coords = x_clockwise(coords,theta_r);
		float theta_h_rad = degrees_to_radians(theta_h);
		float current_hieght = max_ollie_height*sin(theta_h_rad);

		// add height to z coord
		new_coords[2] = new_coords[2] + current_hieght;

		return new_coords;
	}

// //#############################################################

std::array<float,3> nollie_motion(std::array<float,3> coords, float theta_h, float theta_r)
	{	
		float max_nollie_height = 35;
		std::array<float,3> new_coords = x_clockwise(coords,-theta_r);
		float theta_h_rad = degrees_to_radians(theta_h);
		float current_hieght = max_nollie_height*sin(theta_h_rad);

		// add height to z coord
		new_coords[2] = new_coords[2] + current_hieght;

		return new_coords;
	}

// //#############################################################

