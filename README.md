# Dual_Quaternion_Robots
Robotics projects using dual quaternion algebra, some example .cpp files are shown. The submodules contain header files for modelling and controlling the robots. This repo should help you learn about dual quaternions and how you can use them to model robots.

This topic is way too deep for me to explain in a github readme file, I'll present some useful formulations that will motivate you to go through the [list of resources](#list). I HIGHLY recommend going through each topic in the list.

TODO: Expand definitions and visualizations

## Background and motivation

The homogeneous transformation matrix is most commonly used for representing rotation and translations of a rigid body in 3D space. They encode 6 DOF with 12 parameters, and a prone to many numerical issues. Dual quaternions are extentions of quaternions as a dual number, just as quaternions of unit length can be used to represent 3D rotations, dual quaternions of unit length can be used to represent 3D rigid motions, encoding both translation and rotation into one formulation. Dual quaternions provide a more stable and compact form for representing rigid body motion, and a unified space for performing modelling, control and planning when compared to classical tranformation methods.

## Quaternions 

Quaternions are a type of hypercomplex number used extensively in mathematics and engineering for representing rotations in three-dimensional space. They are formulated as:

$$
\mathbf{q}=w+(x \mathbf{i}+y \mathbf{j}+z \mathbf{k})
$$

$w,x,y,z\in \mathbb{R}$
$w$ is the real part, $(x,y,z)$ is the vector part and $\mathbf{i}, \mathbf{j}, \mathbf{k}$ are the basis elements.
In 1843 Sir William Rowan Hamilton carved out the multiplication rules of a quaternion as:

$$
\mathbf{i}^2=\mathbf{j}^2=\mathbf{k}^2= \mathbf{i}\mathbf{j}\mathbf{k} = -1
$$

The products of other basis elements are:

$$
\begin{aligned}
i j & =k, & & j i=-k \\
j k & =i, & & k j=-i \\
k i & =j, & & i k=-j
\end{aligned}
$$


## Dual numbers

Dual numbers are an extention of real numbers introduced by Clifford in 1873. A dual number is defined as 

$$
d=p+\varepsilon q
$$

Where $p, q \in \mathbb{R}$ and $\varepsilon^2=0$ while $\varepsilon \neq 0$. The motivation for this is to create a vector space where $\sqrt{0} \neq 0$, and imagine $\varepsilon$ to be a very very small quantity. This is super useful in differential geometry and mechanics as $\varepsilon$ can represent infinitesmal translations and rotations in a vector space. If $V$ is a vector space, then the space of dual numbers over $V$, denoted by $V[ε]$, can be used to represent infinitesimal translations and rotations of $V$. You can check out the algebra of [dual numbers](https://en.wikipedia.org/wiki/Dual_number) to see how they're a computationally efficient tool. 

This is not to be confused with [Dual Vector Space](https://en.wikipedia.org/wiki/Dual_space). Although there exists some relations between the two, a dual vector space and dual numbers are different topics.

## What is a dual quaternion?

Suppose each part of the dual number above was a quaternion in itself,

$$
\underline{\boldsymbol{q}}=\underline{q}_p+\varepsilon \underline{q}_d
$$

Where $\underline{q}_p$ is the primary part and $\underline{q}_d$ is the dual part.

$$
\underline{q}_p=w_1+(x_1 \mathbf{i}+y_1 \mathbf{j}+z_1 \mathbf{k})
$$

$$
\underline{q}_d=w_2+(x_2 \mathbf{i}+y_2 \mathbf{j}+z_2 \mathbf{k})
$$

### The conjugate of a dual quaternion $\underline{\boldsymbol{q}}$ is:

$$
\underline{\boldsymbol{q}}^* = \underline{q}_p^* + \varepsilon \underline{q}_d^*
$$

Where $\underline{q}_p^*$ is the standard quaternion conjugate

${\underline{q}_p}^*  = w - (x \mathbf{i} + y \mathbf{j} + z \mathbf{k})$

### The norm of a dual quaternion is given by:


$$
\|\|{\underline{\boldsymbol{q}}}\|\|=\sqrt{{\underline{\boldsymbol{q}}}^{\ast}{\underline{\boldsymbol{q}}}}=\sqrt{{\underline{\boldsymbol{q}}}{\underline{\boldsymbol{q}}}^{\ast}}
$$



## Unit dual quaternions and rigid body motions

If $\|\underline{\boldsymbol{q}}\|=1$ then the dual quaternion is known as a unit dual quaternion.

The unit dual quaternion corresponding to the translation $t$ followed by the rotation $r$ is
given by: 

$$
\underline{\boldsymbol{q}}=\boldsymbol{r}+\varepsilon \frac{1}{2} \boldsymbol{t} \boldsymbol{r}
$$

$\boldsymbol{r}$ is our ration and we can define it using our known axis of rotaion $\boldsymbol{n}=n_x \mathbf{i}+n_y \mathbf{j}+n_z \mathbf{k}$, a pure imaginary quaternion and angle of rotation $\phi$

$$
\boldsymbol{r}=\cos (\phi / 2)+\sin (\phi / 2) \boldsymbol{n}
$$

and $\boldsymbol{t}$ is a pure quaternion given by $\boldsymbol{t}=t_x \mathbf{i}+t_y \mathbf{j}+t_z \mathbf{k}$


### Unit dual quaternions as frame transformations:

If ${ }^0 \underline{q}_{1}$ reporesents a rotation and translation from frame ${0}$ to frame ${1}$. Then the composite successive transformations are given by:


$$
{ }^0 \underline{q_N} =  { }^0 \underline{q_1}{ }^1 \underline{q_2} { }^2 \underline{q_3}  . . .{ }^N{ }^-{ }^1 \underline{q_N} 
$$

### The Adjoint operation:

If we have a pure vector dual quaternion $\underline{v}$, defined in frame ${0}$ where the primary and dual parts are pure vector quaternions then we can tranform the frame of $\underline{v}$ by the adjoint operation :

$$
{ }^k \underline{v} = { }^0 \underline{q_k} { }^0\underline{v} ({ }^0 \underline{q_k})^*
$$


This lets us encode both translation and rotation into one unique mathematical formulation, the applications of which are immense 

## List of resources to understand dualquats. <a name="list"></a>

I would go about learning the topics in this order, a good understanding of linear algebra is assumed:

1. To understand quaternions and how they represent 3D rotations, I suggest watching [this 3Blue1Brown video](https://www.youtube.com/watch?v=d4EgbgTm0Bg)

2. [A Beginners Guide to Dual-Quaternions](https://cs.gmu.edu/~jmlien/teaching/cs451/uploads/Main/dual-quaternion.pdf)

3. [Robot Kinematic Modeling and Control Based on Dual Quaternion Algebra by Dr.Bruno Vilhena Adorno](https://hal.science/hal-01478225/file/Robot_Kinematic_Modeling_and_Control_Based_on_Dual_Quaternion_Algebra_Part_I_Fundamentals_28Feb2017.pdf)

I suggest reading Dr.Bruno Vilhena Adorno's PhD thesis as well, and head on over to [DQ Robotics](https://dqrobotics.github.io/)



## Notes

### Dual quaternions for graphics:

1. [Screw Linear Interpolation](https://arxiv.org/pdf/2303.13395.pdf)
2. [Dual Quaternions for Rigid Transformation Blending](https://users.cs.utah.edu/~ladislav/kavan06dual/kavan06dual.pdf)
3. [Enhanced Dual Quaternion Skinning](https://disneyanimation.com/publications/enhanced-dual-quaternion-skinning-for-production-use/#:~:text=Dual%20Quaternion%20Skinning%20(DQS)%20is,and%20effectively%20simulates%20volume%20preservation.)

### Other helpful videos
1. [A quaternion version of Euler's formula](https://www.youtube.com/watch?v=dvpAFWBVgy0&t=548s) *We can extend this easily into the dual quaternion space*

## Refrences

[1] Adorno, B. V. (2011). *Two-arm Manipulation: From Manipulators to Enhanced Human-Robot Collaboration* [PhD dissertation]. Université de Montpellier II.

[2] Adorno, B.V. (2017) *Robot Kinematic Modeling and Control Based on Dual
Quaternion Algebra Part I: Fundamentals*, *ReasearchGate*. Available at:
https://hal.science/hal-01478225v1 (Accessed: April 9, 2023).

[3] Valverde, A. (2018) *Spacecraft Robot Kinematics Using Dual
Quaternions*, *MDPI*. Available at:
https://www.dcsl.gatech.edu/papers/mdpi18%20(Printed).pdf (Accessed:
April 9, 2023).

[4] Hoang-Lan Pham, Perdereau, V., Adorno, B. V., &amp; Fraisse, P. (2010). Position and orientation control of robot manipulators using dual quaternion feedback. *2010 IEEE/RSJ International Conference on Intelligent Robots and Systems.* https://doi.org/10.1109/iros.2010.5651097 

[5] Özgür, E., &amp; Mezouar, Y. (2016). Kinematic modeling and control of a robot arm using unit dual quaternions. *Robotics and Autonomous Systems*, 77, 66–73. https://doi.org/10.1016/j.robot.2015.12.005 

[6] Xiangke Wang, Changbin Yu, &amp; Zhiyun Lin. (2012). A dual quaternion solution to attitude and position control for rigid-body coordination. *IEEE Transactions on Robotics, 28(5), 1162–1170.* https://doi.org/10.1109/tro.2012.2196310 

[7] Markley, F. L., &amp; Mortari, D. (2000). Quaternion attitude estimation using vector observations. *The Journal of the Astronautical Sciences, 48(2–3), 359–380.* https://doi.org/10.1007/bf03546284 
