// from transforms import PyTransforms
// tf = PyTransforms()
// import numpy as np


#include <cmath>
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

std::vector<double> make_theta_r(std::string bone_or_nobone, std::string ollie_or_nollie)
    {
        // compute all lists 
        
        std::vector<double> d_theta_r;
        std::vector<double> d_theta_r_no_bone;
        std::vector<double> d_theta_r_nollie;
        std::vector<double> d_theta_r_nollie_no_bone;

        std::vector<double> board_angle1 = linspace(0,M_PI+bone_angle_rad,peak_frame);
        std::vector<double> board_angle1_no_bone         = linspace(0,M_PI,peak_frame);
        std::vector<double> board_angle1_nollie          = linspace(0,M_PI - bone_angle_rad,peak_frame);
        std::vector<double> board_angle1_nollie_no_bone  = linspace(0,M_PI,peak_frame);

        std::vector<double> board_angle2 = linspace(0,M_PI/2,stomp_duration);


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

        // return correct list
        if (ollie_or_nollie == "ollie")
                {
                    if (bone_or_nobone == "bone")
                        {
                            return d_theta_r;
                        }
                    if (bone_or_nobone== "nobone")
                        {
                            return d_theta_r_no_bone;
                        }
                }
            if (ollie_or_nollie == "nollie")
                {
                    if (bone_or_nobone == "bone")
                        {
                            return d_theta_r_nollie;
                        }
                    if (bone_or_nobone== "nobone")
                        {
                            return d_theta_r_nollie_no_bone;
                        }
                }            
    };

    // ########################################################################
    // # ollie/nollie bone/nobone motions
    // ########################################################################
        
    std::vector<double> d_theta_r                = make_theta_r( "bone" , "ollie");
    std::vector<double> d_theta_r_no_bone        = make_theta_r("nobone", "ollie");
    std::vector<double> d_theta_r_nollie         = make_theta_r( "bone" ,"nollie");
    std::vector<double> d_theta_r_nollie_no_bone = make_theta_r("nobone","nollie");

    // ########################################################################
    // # flip : catch duration calculations
    // ########################################################################

    const int frame_of_catch =0.75*num_of_frames;
    const int post_catch = num_of_frames - frame_of_catch;

    std::vector<double> flip_and_catch(std::vector<double> flip_theta)
        {
            std::vector<double> new_theta;

            for(int i = 0; i < frame_of_catch ; i = i + 1 )
                {
                    new_theta.push_back(flip_theta[i]); 
                };
            
            for(int i = 0; i < frame_of_catch ; i = i + 1 )
                {
                    new_theta.push_back(0); 
                };
            
            return new_theta;
        }

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

    std::map<std::string, std::vector<double>> kickflip_info =
            {
                {"trick name",   list_of_zeros}, //this is string to string
                {"x_rot_angles", list_of_zeros},
                {"y_rot_angles", flip_and_catch(linspace(0,-360,frame_of_catch))},
                {"z_rot_angles", list_of_zeros},
                {"h_rot_angles", d_theta_h},
                {"r_rot_angles", d_theta_r},
            };

    std::map<std::string, std::vector<double>> nollie_kickflip_info =
            {
                {"trick name",   list_of_zeros}, //this is string to string
                {"x_rot_angles", list_of_zeros},
                {"y_rot_angles", flip_and_catch(linspace(0,-360,frame_of_catch))},
                {"z_rot_angles", list_of_zeros},
                {"h_rot_angles", d_theta_h},
                {"r_rot_angles", d_theta_r_nollie},
            };

    std::map<std::string, std::vector<double>> heelflip_info =
            {
                {"trick name",   list_of_zeros}, //this is string to string
                {"x_rot_angles", list_of_zeros},
                {"y_rot_angles", flip_and_catch(linspace(0,360,frame_of_catch))},
                {"z_rot_angles", list_of_zeros},
                {"h_rot_angles", d_theta_h},
                {"r_rot_angles", d_theta_r},
            };

    std::map<std::string, std::vector<double>> nollie_heelflip_info =
            {
                {"trick name",   list_of_zeros}, //this is string to string
                {"x_rot_angles", list_of_zeros},
                {"y_rot_angles", flip_and_catch(linspace(0,360,frame_of_catch))},
                {"z_rot_angles", list_of_zeros},
                {"h_rot_angles", d_theta_h},
                {"r_rot_angles", d_theta_r_nollie},
            };

    std::map<std::string, std::vector<double>> BS_360_pop_shuvit_info =
            {
                {"trick name",   list_of_zeros}, //this is string to string
                {"x_rot_angles", list_of_zeros},
                {"y_rot_angles", list_of_zeros},
                {"z_rot_angles", flip_and_catch(linspace(0,360,frame_of_catch))},
                {"h_rot_angles", d_theta_h},
                {"r_rot_angles", d_theta_r},
            };

    std::map<std::string, std::vector<double>> nollie_BS_360_pop_shuvit_info =
            {
                {"trick name",   list_of_zeros}, //this is string to string
                {"x_rot_angles", list_of_zeros},
                {"y_rot_angles", list_of_zeros},
                {"z_rot_angles", flip_and_catch(linspace(0,360,frame_of_catch))},
                {"h_rot_angles", d_theta_h},
                {"r_rot_angles", d_theta_r_nollie},
            };

    std::map<std::string, std::vector<double>> FS_360_pop_shuvit_info =
            {
                {"trick name",   list_of_zeros}, //this is string to string
                {"x_rot_angles", list_of_zeros},
                {"y_rot_angles", list_of_zeros},
                {"z_rot_angles", flip_and_catch(linspace(0,-360,frame_of_catch))},
                {"h_rot_angles", d_theta_h},
                {"r_rot_angles", d_theta_r},
            };

    std::map<std::string, std::vector<double>> nollie_FS_360_pop_shuvit_info =
            {
                {"trick name",   list_of_zeros}, //this is string to string
                {"x_rot_angles", list_of_zeros},
                {"y_rot_angles", list_of_zeros},
                {"z_rot_angles", flip_and_catch(linspace(0,-360,frame_of_catch))},
                {"h_rot_angles", d_theta_h},
                {"r_rot_angles", d_theta_r_nollie},
            };

    std::map<std::string, std::vector<double>> back_foot_impossible_info =
            {
                {"trick name",   list_of_zeros}, //this is string to string
                {"x_rot_angles", flip_and_catch(linspace(0,360,frame_of_catch))},
                {"y_rot_angles", list_of_zeros},
                {"z_rot_angles", list_of_zeros},
                {"h_rot_angles", d_theta_h},
                {"r_rot_angles", d_theta_r_no_bone},
            };

    std::map<std::string, std::vector<double>> nollie_back_foot_impossible_info =
            {
                {"trick name",   list_of_zeros}, //this is string to string
                {"x_rot_angles", flip_and_catch(linspace(0,360,frame_of_catch))},
                {"y_rot_angles", list_of_zeros},
                {"z_rot_angles", list_of_zeros},
                {"h_rot_angles", d_theta_h},
                {"r_rot_angles", d_theta_r_nollie_no_bone},
            };
 
    std::map<std::string, std::vector<double>> front_foot_impossible_info =
            {
                {"trick name",   list_of_zeros}, //this is string to string
                {"x_rot_angles", flip_and_catch(linspace(0,-360,frame_of_catch))},
                {"y_rot_angles", list_of_zeros},
                {"z_rot_angles", list_of_zeros},
                {"h_rot_angles", d_theta_h},
                {"r_rot_angles", d_theta_r_no_bone},
            };

    std::map<std::string, std::vector<double>> nollie_front_foot_impossible_info =
            {
                {"trick name",   list_of_zeros}, //this is string to string
                {"x_rot_angles", flip_and_catch(linspace(0,-360,frame_of_catch))},
                {"y_rot_angles", list_of_zeros},
                {"z_rot_angles", list_of_zeros},
                {"h_rot_angles", d_theta_h},
                {"r_rot_angles", d_theta_r_nollie_no_bone},
            };

    std::map<std::string, std::vector<double>> treflip_info =
            {
                {"trick name",   list_of_zeros}, //this is string to string
                {"x_rot_angles", list_of_zeros},
                {"y_rot_angles", flip_and_catch(linspace(0,-360,frame_of_catch))},
                {"z_rot_angles", flip_and_catch(linspace(0,360,frame_of_catch))},
                {"h_rot_angles", d_theta_h},
                {"r_rot_angles", d_theta_r},
            };

    std::map<std::string, std::vector<double>> nollie_treflip_info =
            {
                {"trick name",   list_of_zeros}, //this is string to string
                {"x_rot_angles", list_of_zeros},
                {"y_rot_angles", flip_and_catch(linspace(0,-360,frame_of_catch))},
                {"z_rot_angles", flip_and_catch(linspace(0,-360,frame_of_catch))},
                {"h_rot_angles", d_theta_h},
                {"r_rot_angles", d_theta_r_nollie},
            };

    std::map<std::string, std::vector<double>> lazerflip_info =
            {
                {"trick name",   list_of_zeros}, //this is string to string
                {"x_rot_angles", list_of_zeros},
                {"y_rot_angles", flip_and_catch(linspace(0,360,frame_of_catch))},
                {"z_rot_angles", flip_and_catch(linspace(0,-360,frame_of_catch))},
                {"h_rot_angles", d_theta_h},
                {"r_rot_angles", d_theta_r},
            };

    std::map<std::string, std::vector<double>> nollie_lazerflip_info =
            {
                {"trick name",   list_of_zeros}, //this is string to string
                {"x_rot_angles", list_of_zeros},
                {"y_rot_angles", flip_and_catch(linspace(0,360,frame_of_catch))},
                {"z_rot_angles", flip_and_catch(linspace(0,360,frame_of_catch))},
                {"h_rot_angles", d_theta_h},
                {"r_rot_angles", d_theta_r_nollie},
            };

     std::map<std::string, std::vector<double>> hardflip_info =
            {
                {"trick name",   list_of_zeros}, //this is string to string
                {"x_rot_angles", list_of_zeros},
                {"y_rot_angles", flip_and_catch(linspace(0,-360,frame_of_catch))},
                {"z_rot_angles", flip_and_catch(linspace(0,-180,frame_of_catch))},
                {"h_rot_angles", d_theta_h},
                {"r_rot_angles", d_theta_r},
            };

     std::map<std::string, std::vector<double>> nollie_hardflip_info =
            {
                {"trick name",   list_of_zeros}, //this is string to string
                {"x_rot_angles", list_of_zeros},
                {"y_rot_angles", flip_and_catch(linspace(0,-360,frame_of_catch))},
                {"z_rot_angles", flip_and_catch(linspace(0,180,frame_of_catch))},
                {"h_rot_angles", d_theta_h},
                {"r_rot_angles", d_theta_r_nollie},
            };

   std::map<std::string, std::vector<double>> inward_heelflip_info =
            {
                {"trick name",   list_of_zeros}, //this is string to string
                {"x_rot_angles", list_of_zeros},
                {"y_rot_angles", flip_and_catch(linspace(0,360,frame_of_catch))},
                {"z_rot_angles", flip_and_catch(linspace(0,180,frame_of_catch))},
                {"h_rot_angles", d_theta_h},
                {"r_rot_angles", d_theta_r},
            };          

   std::map<std::string, std::vector<double>> nollie_inward_heelflip_info =
            {
                {"trick name",   list_of_zeros}, //this is string to string
                {"x_rot_angles", list_of_zeros},
                {"y_rot_angles", flip_and_catch(linspace(0,360,frame_of_catch))},
                {"z_rot_angles", flip_and_catch(linspace(0,180,frame_of_catch))},
                {"h_rot_angles", d_theta_h},
                {"r_rot_angles", d_theta_r_nollie},
            };    

   std::map<std::string, std::vector<double>> varial_heelflip_info =
            {
                {"trick name",   list_of_zeros}, //this is string to string
                {"x_rot_angles", list_of_zeros},
                {"y_rot_angles", flip_and_catch(linspace(0,360,frame_of_catch))},
                {"z_rot_angles", flip_and_catch(linspace(0,-180,frame_of_catch))},
                {"h_rot_angles", d_theta_h},
                {"r_rot_angles", d_theta_r},
            };          

   std::map<std::string, std::vector<double>> nollie_varial_heelflip_info =
            {
                {"trick name",   list_of_zeros}, //this is string to string
                {"x_rot_angles", list_of_zeros},
                {"y_rot_angles", flip_and_catch(linspace(0,360,frame_of_catch))},
                {"z_rot_angles", flip_and_catch(linspace(0,180,frame_of_catch))},
                {"h_rot_angles", d_theta_h},
                {"r_rot_angles", d_theta_r_nollie},
            };   

   std::map<std::string, std::vector<double>> varial_kickflip_info =
            {
                {"trick name",   list_of_zeros}, //this is string to string
                {"x_rot_angles", list_of_zeros},
                {"y_rot_angles", flip_and_catch(linspace(0,-360,frame_of_catch))},
                {"z_rot_angles", flip_and_catch(linspace(0,180,frame_of_catch))},
                {"h_rot_angles", d_theta_h},
                {"r_rot_angles", d_theta_r},
            };          

   std::map<std::string, std::vector<double>> nollie_varial_kickflip_info =
            {
                {"trick name",   list_of_zeros}, //this is string to string
                {"x_rot_angles", list_of_zeros},
                {"y_rot_angles", flip_and_catch(linspace(0,-360,frame_of_catch))},
                {"z_rot_angles", flip_and_catch(linspace(0,-180,frame_of_catch))},
                {"h_rot_angles", d_theta_h},
                {"r_rot_angles", d_theta_r_nollie},
            };     
            
    std::map<std::string, std::map<std::string, std::vector<double>>> trick_list = 
        {	
            {"Ollie"                        , ollie_info},
            {"Nollie"                       ,nollie_info},
            {"Kickflip"                     ,kickflip_info},
            {"Nollie Kickflip"              ,nollie_kickflip_info},
            {"Heelflip"                     ,heelflip_info},
            {"Nollie Heelflip"              ,nollie_heelflip_info},
            {"BS 360 Pop Shuvit"            ,BS_360_pop_shuvit_info},
            {"Nollie BS 360 Pop Shuvit"     ,nollie_BS_360_pop_shuvit_info},
            {"FS 360 Pop Shuvit"            ,FS_360_pop_shuvit_info},
            {"Nollie FS 360 Pop Shuvit"     ,nollie_FS_360_pop_shuvit_info},
            {"Front Foot Impossible"        ,front_foot_impossible_info},
            {"Nollie Front Foot Impossible" ,nollie_front_foot_impossible_info},
            {"Back Foot Impossible"         ,back_foot_impossible_info},
            {"Nollie Back Foot Impossible"  ,nollie_back_foot_impossible_info},
            {"Treflip"                      ,treflip_info},
            {"Nollie Treflip"               ,nollie_treflip_info},
            {"Lazerflip"                    ,lazerflip_info},
            {"Nollie Lazerflip"             ,nollie_lazerflip_info},
            {"Hardflip"                     ,hardflip_info},
            {"Nollie Hardflip"              ,nollie_hardflip_info},
            {"Inward Heelflip"              ,inward_heelflip_info},
            {"Nollie Inward Heelflip"       ,nollie_inward_heelflip_info},
            {"Varial Heelflip"              ,varial_heelflip_info},
            {"Nollie Varial Heelflip"       ,nollie_varial_heelflip_info},
            {"Varial Kickflip"              ,varial_kickflip_info},
            {"Nollie Varial Kickflip"       ,nollie_varial_kickflip_info}
        };
