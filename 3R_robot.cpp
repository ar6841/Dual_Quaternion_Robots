#include<iostream>
#include"Dual_Quaternion_Forward_Kinematics/kinematics.h"
#include"Dual_Quaternion_Control/Dual_Pose_Control.h"


// Order of joint vars {theta, alpha, a, d, type}
int main()
{
    

    double arm_length = 5.0;
    //Joint 1
    DH::DH_joint<double> J1(0,0,arm_length,0, 0);

    //Joint 2
    DH::DH_joint<double> J2(0,0,arm_length,0, 0);

    //Joint 3
    DH::DH_joint<double> J3(0,0,arm_length,0, 0);

    

    Kinematics::RobotLinks<double> MyRobot;

    MyRobot.addJoint(J1);
    MyRobot.addJoint(J2);
    MyRobot.addJoint(J3);

    std::cout<<"\nTest Outputs"<<std::endl;
    std::cout<<"\n"<<Kinematics::ComputeJacobian(MyRobot)<<std::endl;
    std::cout<<"\n"<<Kinematics::compute_pose_dot(MyRobot)<<std::endl;

    double total_time = 10, dt = 0.01;

    int N = static_cast<int>(ceil(total_time/dt)); 

    Eigen::Matrix<double,3,1> joint_vec_desired;

    /*
        Target joint configuration
    */
    joint_vec_desired<<90,0,0;

    std::cout<<"\nJoint Vec desired: "<<joint_vec_desired<<std::endl;

    dualquat::DualQuaternion q_desired  = MyRobot.ComputeForwardKinematics(joint_vec_desired);

    Eigen::Matrix<double,3,Eigen::Dynamic> Output(3,N);

    Output = Controller::pose_difference_controller(MyRobot,q_desired,dt,total_time,10.0);

    /*
        Did we reach target?
    */
    std::cout<<"\nControl output : "<<Output.col(N-1)<<std::endl;


return 0;
}