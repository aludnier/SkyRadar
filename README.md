# SkyRadar

Simulation of aerian traffic in 2D CSFML and use of Quadtree for optimisation

## Project:

Create a simulation for aerian traffic in 2D from a given map:

For the simulation we need to consider 2 type of entities
- Planes
- Control tower

### Basic Rules:
 - Planes fligth straigth from a point to an other in constant speed
 - Planes disapear when they arrived at destination
 - Two planes who collide both disapears
 - Towers disable collision in their radius

### Installation
 Clone this Repository or download the code, and compile the program with Makefile.

 ~~~bash
 make
 ~~~

 Run the program with the path to a script. Example script are given in the script folder.
 ~~~bash
 ./my_radar path_to_script
 ~~~

### Create scripts
 You can create a script with the generator in the script folfer

#### Requierment
 You need python3 to generate a script.
 Install it with :
 ~~~bash
 sudo apt instal python3
 ~~~
 #### Generation
 generate a script by precising the number of planes and towers.

 ~~~bash
 python3 generator.py -p [nb_planes] -t [nb_towers]
 ~~~

