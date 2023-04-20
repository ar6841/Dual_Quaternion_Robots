# Dual_Quaternion_Robots
Robotics projects using dual quaternion algebra, some example .cpp files are shown. The submodules contain header files for modelling and controlling the robots. This repo should help you learn about dual quaternions and how you can apply them to robotics.

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


## Dual numbers and dual vector space

Dual numbers are an extention of real numbers introduced by Clifford in 1873. A dual number is defined as 

$$
d=p+\varepsilon q
$$

Where $p, q \in \mathbb{R}$ and $\varepsilon^2=0$ while $\varepsilon \neq 0$. 

## What is a dual quaternion?

Suppose each part of the dual number above was a quaternion in itself,

$$
\underline{\boldsymbol{q}}=\underline{q}_p+\varepsilon \underline{q}_d
$$

Where $\underline{q}_p$ is the primary part and $\underline{q}_d$ is the dual part.

$$
\underline{q}_p=w_1+(x_1 \mathbf{i}+y_1 \mathbf{j}+z_1 \mathbf{k}) and, 
\underline{q}_d=w_2+(x_2 \mathbf{i}+y_2 \mathbf{j}+z_2 \mathbf{k})
$$

The conjugate of a dual quaternion $\underline{\boldsymbol{q}}$ is:

$$
\underline{\boldsymbol{q}}^* = \underline{q}_p^* + \varepsilon \underline{q}_d^*
$$

The norm of a dual quaternion is given by:


$$
\|\|{\underline{\boldsymbol{q}}}\|\|=\sqrt{{\underline{\boldsymbol{q}}}^{\ast}{\underline{\boldsymbol{q}}}}=\sqrt{{\underline{\boldsymbol{q}}}{\underline{\boldsymbol{q}}}^{\ast}}
$$



## Unit dual quaternions and rigid body motions

If $\|\underline{\boldsymbol{q}}\|=1$ then the dual quaternion is known as a unit dual quaternion.

The unit dual quaternion corresponding to the translation $tT followed by the rotation $r$ is
given by: 

Unit dual quaternions as frame transformations:


This lets us encode both translation and rotation into one unique mathematical formulation, the applications of which are immense 

## List of resources to learn dualquats and apply it for robotics.

I would go about learning the topics in this order, not all topics are listed as a good understanding of linear algebra is assumed:

1. To understand quaternions and how they represent 3D rotations, I suggest watching [this 3Blue1Brown video](https://www.youtube.com/watch?v=d4EgbgTm0Bg)

2. [A Beginners Guide to Dual-Quaternions](https://cs.gmu.edu/~jmlien/teaching/cs451/uploads/Main/dual-quaternion.pdf)

3. [Robot Kinematic Modeling and Control Based on Dual Quaternion Algebra by Dr.Bruno Vilhena Adorno](https://hal.science/hal-01478225/file/Robot_Kinematic_Modeling_and_Control_Based_on_Dual_Quaternion_Algebra_Part_I_Fundamentals_28Feb2017.pdf)

I suggest reading Dr.Bruno Vilhena Adorno's PhD thesis as well, and head on over to (DQ Robotics)[https://dqrobotics.github.io/]



## Refrences

## Notes
