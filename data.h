// from transforms import PyTransforms
// tf = PyTransforms()
// import numpy as np

#include <iostream>
#include <array>
#include <cmath>
#include <vector>
#include <map>
#include <iterator>

#include "np.h"
#include "transforms.h"

/////////////////////////////////

const int num_of_frames = 25;
std::vector<double> list_of_zeros(num_of_frames, 0);

std::vector<double> d_theta_h = linspace(0,180,num_of_frames);

const double pop_lean_max = 60;
const double bone_angle   = 20;
const double bone_angle_per = (bone_angle/pop_lean_max)*90;
const double bone_angle_rad = degrees_to_radians(bone_angle_per);

const int peak_frame = 0.5*num_of_frames;
const int stomp_duration = num_of_frames - peak_frame;


       
std::vector<double> d_theta_r;
std::vector<double> d_theta_r_no_bone;
std::vector<double> d_theta_r_nollie;
std::vector<double> d_theta_r_nollie_no_bone;


std::vector<double> board_angle1 = linspace(0,M_PI+bone_angle_rad,peak_frame);
std::vector<double> board_angle1_no_bone         = linspace(0,M_PI,peak_frame);
std::vector<double> board_angle1_nollie          = linspace(0,M_PI - bone_angle_rad,peak_frame);
std::vector<double> board_angle1_nollie_no_bone  = linspace(0,M_PI,peak_frame);


std::vector<double> board_angle2 = linspace(0,M_PI/2,stomp_duration);
int main()
	{
		for( int i = 0; i < peak_frame-1; i = i + 1 ) 	
			{
				d_theta_r.push_back(pop_lean_max*sin(board_angle1[i]));
				d_theta_r_no_bone.push_back(pop_lean_max*sin(board_angle1_no_bone[i]));
				d_theta_r_nollie.push_back(pop_lean_max*sin(board_angle1_nollie[i]));
				d_theta_r_nollie_no_bone.push_back(pop_lean_max*sin(board_angle1_nollie_no_bone[i]));
		    }

		for(int i = 0; i < stomp_duration; i = i + 1 )
		{
			d_theta_r.push_back(-bone_angle_per*cos(board_angle2[i]));
			d_theta_r_no_bone.push_back(0);
			d_theta_r_nollie.push_back(bone_angle_per*cos(board_angle2[i]));
			d_theta_r_nollie_no_bone.push_back(0);
		}

		return 0;
	};


//         ########################################################################
//         # flip : catch duration calculations
//         ########################################################################

const int frame_of_catch =0.75*num_of_frames;
const int post_catch = num_of_frames - frame_of_catch;
std::vector<double> catch_and_land(post_catch, 0);



// ########################################################################
// # flip data
// ########################################################################

std::map<std::string, std::vector<double>> ollie_info =
		{
            {"trick name",   list_of_zeros}, //thiis is string to string
            {"x_rot_angles", list_of_zeros},
            {"y_rot_angles", list_of_zeros},
            {"z_rot_angles", list_of_zeros},
            {"h_rot_angles", d_theta_h},
            {"r_rot_angles", d_theta_r},
        };

std::map<std::string, std::vector<double>> nollie_info =
		{
            {"trick name",   list_of_zeros}, //thiis is string to string
            {"x_rot_angles", list_of_zeros},
            {"y_rot_angles", list_of_zeros},
            {"z_rot_angles", list_of_zeros},
            {"h_rot_angles", d_theta_h},
            {"r_rot_angles", d_theta_r_nollie},
        };

std::vector<double> kickflip_y_begin = linspace(0,-360,frame_of_catch);

//std::move(catch_and_land.begin(), catch_and_land.end(), std::back_inserter(kickflip_y_begin));
//std::vector<double> concat(kickflip_y_begin,catch_and_land);
std::vector<double> kicklflip_y      = catch_and_land.insert(catch_and_land.begin(),kickflip_y_begin.begin(),kickflip_y_begin.end())
std::map<std::string, std::vector<double>> kickflip_info =
		{
            {"trick name",   list_of_zeros}, //this is string to string
            {"x_rot_angles", list_of_zeros},
            {"y_rot_angles", kickflip_y},// check this is concat
            {"z_rot_angles", list_of_zeros},
            {"h_rot_angles", d_theta_h},
            {"r_rot_angles", d_theta_r},
        };

//         kickflip_info = {
//                 'trick name'   : 'Kickflip',
//                 'x_rot_angles' : list_of_zeros,
//                 'y_rot_angles' : list(np.linspace(0,-360,frame_of_catch))+catch_and_land,
//                 'z_rot_angles' : list_of_zeros,
//                 'h_rot_angles' : d_theta_h,
//                 'r_rot_angles' : d_theta_r
//                 }

//         nollie_kickflip_info = {
//                 'trick name'   : 'Nollie Kickflip',
//                 'x_rot_angles' : list_of_zeros,
//                 'y_rot_angles' : list(np.linspace(0,-360,frame_of_catch))+catch_and_land,
//                 'z_rot_angles' : list_of_zeros,
//                 'h_rot_angles' : d_theta_h,
//                 'r_rot_angles' : d_theta_r_nollie
//                 }

//         heelflip_info = {
//                 'trick name'   : 'Heelflip',
//                 'x_rot_angles' : list_of_zeros,
//                 'y_rot_angles' : list(np.linspace(0,360,frame_of_catch))+catch_and_land,
//                 'z_rot_angles' : list_of_zeros,
//                 'h_rot_angles' : d_theta_h,
//                 'r_rot_angles' : d_theta_r
//                 }

//         nollie_heelflip_info = {
//                 'trick name'   : 'Nollie Heelflip',
//                 'x_rot_angles' : list_of_zeros,
//                 'y_rot_angles' : list(np.linspace(0,360,frame_of_catch))+catch_and_land,
//                 'z_rot_angles' : list_of_zeros,
//                 'h_rot_angles' : d_theta_h,
//                 'r_rot_angles' : d_theta_r_nollie
//                 }

//         BS_360_pop_shuvit_info = {
//                 'trick name'   : 'BS 360 Pop Shuvit',
//                 'x_rot_angles' : list_of_zeros,
//                 'y_rot_angles' : list_of_zeros,
//                 'z_rot_angles' : list(np.linspace(0,360,frame_of_catch))+catch_and_land,
//                 'h_rot_angles' : d_theta_h,
//                 'r_rot_angles' : d_theta_r
//                 }

//         nollie_BS_360_pop_shuvit_info = {
//                 'trick name'   : 'Nollie BS 360 Pop Shuvit',
//                 'x_rot_angles' : list_of_zeros,
//                 'y_rot_angles' : list_of_zeros,
//                 'z_rot_angles' : list(np.linspace(0,-360,frame_of_catch))+catch_and_land,
//                 'h_rot_angles' : d_theta_h,
//                 'r_rot_angles' : d_theta_r_nollie
//                 }

//         FS_360_pop_shuvit_info = {
//                 'trick name'   : 'FS 360 Pop Shuvit',
//                 'x_rot_angles' : list_of_zeros,
//                 'y_rot_angles' : list_of_zeros,
//                 'z_rot_angles' : list(np.linspace(0,-360,frame_of_catch))+catch_and_land,
//                 'h_rot_angles' : d_theta_h,
//                 'r_rot_angles' : d_theta_r
//                 }

//         nollie_FS_360_pop_shuvit_info = {
//                 'trick name'   : 'Nollie FS 360 Pop Shuvit',
//                 'x_rot_angles' : list_of_zeros,
//                 'y_rot_angles' : list_of_zeros,
//                 'z_rot_angles' : list(np.linspace(0,360,frame_of_catch))+catch_and_land,
//                 'h_rot_angles' : d_theta_h,
//                 'r_rot_angles' : d_theta_r_nollie
//                 }

//         back_foot_impossible_info = {
//                 'trick name'   : 'Back Foot Impossible',
//                 'x_rot_angles' : list(np.linspace(0,360,frame_of_catch))+catch_and_land,
//                 'y_rot_angles' : list_of_zeros,
//                 'z_rot_angles' : list_of_zeros,
//                 'h_rot_angles' : d_theta_h,
//                 'r_rot_angles' : d_theta_r_no_bone
//                 }

//         nollie_back_foot_impossible_info = {
//                 'trick name'   : 'Nollie Back Foot Impossible',
//                 'x_rot_angles' : list(np.linspace(0,360,frame_of_catch))+catch_and_land,
//                 'y_rot_angles' : list_of_zeros,
//                 'z_rot_angles' : list_of_zeros,
//                 'h_rot_angles' : d_theta_h,
//                 'r_rot_angles' : d_theta_r_nollie_no_bone
//                 }

//         front_foot_impossible_info = {
//                 'trick name'   : 'Front Foot Impossible',
//                 'x_rot_angles' : list(np.linspace(0,-360,frame_of_catch))+catch_and_land,
//                 'y_rot_angles' : list_of_zeros,
//                 'z_rot_angles' : list_of_zeros,
//                 'h_rot_angles' : d_theta_h,
//                 'r_rot_angles' : d_theta_r_no_bone
//                 }

//         nollie_front_foot_impossible_info = {
//                 'trick name'   : 'Nollie Front Foot Impossible',
//                 'x_rot_angles' : list(np.linspace(0,-360,frame_of_catch))+catch_and_land,
//                 'y_rot_angles' : list_of_zeros,
//                 'z_rot_angles' : list_of_zeros,
//                 'h_rot_angles' : d_theta_h,
//                 'r_rot_angles' : d_theta_r_nollie_no_bone
//                 }

//         treflip_info = {
//                 'trick name'   : 'Treflip',
//                 'x_rot_angles' : list_of_zeros,
//                 'y_rot_angles' : list(np.linspace(0,-360,frame_of_catch))+catch_and_land,
//                 'z_rot_angles' : list(np.linspace(0,360,frame_of_catch))+catch_and_land,
//                 'h_rot_angles' : d_theta_h,
//                 'r_rot_angles' : d_theta_r
//                 }

//         nollie_treflip_info = {
//                 'trick name'   : 'Nollie Treflip',
//                 'x_rot_angles' : list_of_zeros,
//                 'y_rot_angles' : list(np.linspace(0,-360,frame_of_catch))+catch_and_land,
//                 'z_rot_angles' : list(np.linspace(0,-360,frame_of_catch))+catch_and_land,
//                 'h_rot_angles' : d_theta_h,
//                 'r_rot_angles' : d_theta_r_nollie
//                 }

//         lazerflip_info = {
//                 'trick name'   : 'Lazerflip',
//                 'x_rot_angles' : list_of_zeros,
//                 'y_rot_angles' : list(np.linspace(0,360,frame_of_catch))+catch_and_land,
//                 'z_rot_angles' : list(np.linspace(0,-360,frame_of_catch))+catch_and_land,
//                 'h_rot_angles' : d_theta_h,
//                 'r_rot_angles' : d_theta_r
//                 }

//         nollie_lazerflip_info = {
//                 'trick name'   : 'Nollie Lazerflip',
//                 'x_rot_angles' : list_of_zeros,
//                 'y_rot_angles' : list(np.linspace(0,360,frame_of_catch))+catch_and_land,
//                 'z_rot_angles' : list(np.linspace(0,360,frame_of_catch))+catch_and_land,
//                 'h_rot_angles' : d_theta_h,
//                 'r_rot_angles' : d_theta_r_nollie
//                 }

//         hardflip_info = {
//                 'trick name'   : 'Hardflip',
//                 'x_rot_angles' : list_of_zeros,
//                 'y_rot_angles' : list(np.linspace(0,-360,frame_of_catch))+catch_and_land,
//                 'z_rot_angles' : list(np.linspace(0,-180,frame_of_catch))+catch_and_land,
//                 'h_rot_angles' : d_theta_h,
//                 'r_rot_angles' : d_theta_r
//                 }

//         nollie_hardflip_info = {
//                 'trick name'   : 'Nollie Hardflip',
//                 'x_rot_angles' : list_of_zeros,
//                 'y_rot_angles' : list(np.linspace(0,-360,frame_of_catch))+catch_and_land,
//                 'z_rot_angles' : list(np.linspace(0,180,frame_of_catch))+catch_and_land,
//                 'h_rot_angles' : d_theta_h,
//                 'r_rot_angles' : d_theta_r_nollie
//                 }
                
//         inward_heelflip_info = {
//                 'trick name'   : 'Inward Heelflip',
//                 'x_rot_angles' : list_of_zeros,
//                 'y_rot_angles' : list(np.linspace(0,360,frame_of_catch))+catch_and_land,
//                 'z_rot_angles' : list(np.linspace(0,180,frame_of_catch))+catch_and_land,
//                 'h_rot_angles' : d_theta_h,
//                 'r_rot_angles' : d_theta_r
//                 }

//         nollie_inward_heelflip_info = {
//                 'trick name'   : 'Nollie Inward Heelflip',
//                 'x_rot_angles' : list_of_zeros,
//                 'y_rot_angles' : list(np.linspace(0,360,frame_of_catch))+catch_and_land,
//                 'z_rot_angles' : list(np.linspace(0,-180,frame_of_catch))+catch_and_land,
//                 'h_rot_angles' : d_theta_h,
//                 'r_rot_angles' : d_theta_r_nollie
//                 }

//         varial_heelflip_info = {
//                 'trick name'   : 'Varial Heelflip',
//                 'x_rot_angles' : list_of_zeros,
//                 'y_rot_angles' : list(np.linspace(0,360,frame_of_catch))+catch_and_land,
//                 'z_rot_angles' : list(np.linspace(0,-180,frame_of_catch))+catch_and_land,
//                 'h_rot_angles' : d_theta_h,
//                 'r_rot_angles' : d_theta_r
//                 }

//         nollie_varial_heelflip_info = {
//                 'trick name'   : 'Nollie Varial Heelflip',
//                 'x_rot_angles' : list_of_zeros,
//                 'y_rot_angles' : list(np.linspace(0,360,frame_of_catch))+catch_and_land,
//                 'z_rot_angles' : list(np.linspace(0,180,frame_of_catch))+catch_and_land,
//                 'h_rot_angles' : d_theta_h,
//                 'r_rot_angles' : d_theta_r_nollie
//                 }

//         varial_kickflip_info = {
//                 'trick name'   : 'Varial Kickflip',
//                 'x_rot_angles' : list_of_zeros,
//                 'y_rot_angles' : list(np.linspace(0,-360,frame_of_catch))+catch_and_land,
//                 'z_rot_angles' : list(np.linspace(0,180,frame_of_catch))+catch_and_land,
//                 'h_rot_angles' : d_theta_h,
//                 'r_rot_angles' : d_theta_r
//                 }

//         nollie_varial_kickflip_info = {
//                 'trick name'   : 'Nollie Varial Kickflip',
//                 'x_rot_angles' : list_of_zeros,
//                 'y_rot_angles' : list(np.linspace(0,-360,frame_of_catch))+catch_and_land,
//                 'z_rot_angles' : list(np.linspace(0,-180,frame_of_catch))+catch_and_land,
//                 'h_rot_angles' : d_theta_h,
//                 'r_rot_angles' : d_theta_r_nollie
//                 }
        
std::vector<std::string> trick_list = 
	{	
		ollie_info,
        nollie_info,
        kickflip_info,
        nollie_kickflip_info,
        heelflip_info,
        nollie_heelflip_info,
        BS_360_pop_shuvit_info,
        nollie_BS_360_pop_shuvit_info,
        FS_360_pop_shuvit_info,
        nollie_FS_360_pop_shuvit_info,
        front_foot_impossible_info,
        nollie_front_foot_impossible_info,
        back_foot_impossible_info,
        nollie_back_foot_impossible_info,
        treflip_info,
        nollie_treflip_info,
        lazerflip_info,
        nollie_lazerflip_info,
        hardflip_info,
        nollie_hardflip_info,
        inward_heelflip_info,
        nollie_inward_heelflip_info,
        varial_heelflip_info,
        nollie_varial_heelflip_info,
        varial_kickflip_info,
        nollie_varial_kickflip_info
    }
