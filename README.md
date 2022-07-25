# IIUM Medibot v4 simulation
Simulation of multiple IIUM medibots in Gazebo and Rviz using ROS Melodic with working Genetic Algorithm as path planner


## Requirements

### Software

- Ubuntu 18.04
- ROS Melodic Morenia

## Installation

1.  Clone the repository
    ```shell
    cd ~/catkin_ws/src &&
    git clone https://github.com/msyahmizulkepli/medibotv4-simulation.git
    ```

2.  Install packages dependencies 
    ```shell
    rosdep install medibotv4 -y
    ```

3. Build the packages 
    ```shell
    cd ~/catkin_ws &&
    catkin_make &&
    source ~/catkin_ws/devel/setup.bash
    ```

## How to Use

### Simulation

- Single Robot
```shell
roslaunch medibotv4-simulation simulation.launch
```

- Multi Robot
```shell
roslaunch medibotv4-simulation multirobot_simulation.launch
```
