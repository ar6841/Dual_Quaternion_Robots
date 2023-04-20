# Dual_Quaternion_Robots
Robotics projects using dual quaternion algebra, some example .cpp files are shown. The submodules contain header files for modelling and controlling the robots. This repo should help you learn about dual quaternions and how you can apply them to robotics.

TODO: Expand definition

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
\underline{q}=\mathcal{P}(\underline{q})+\varepsilon \mathcal{D}(\underline{q})
$$

Where $\mathcal{P}$ is the primary part and $\mathcal{D}$ is the dual part.

## Unit dual quaternions and rigid body motions




## List of resources to learn dualquats and apply it for robotics.

## Refrences

## Notes
