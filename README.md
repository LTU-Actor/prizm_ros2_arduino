# PRIZM ROS2 Arduino Code

Unofficial Arduino microcode for the Tetrix PRIZM controller. Able to interface with [prizm_ros2](https://github.com/LTU-Actor/prizm_ros2).

## Setup & Installation
**NOTE: You only need to do this if you want to flash the controller!**

### Step 1: Install VSCode
Install VSCode for your machine from the official source: https://code.visualstudio.com/

### Step 2: Install PlatformIO for VSCode
In VSCode, install the PlatformIO IDE extension, and follow the installation steps provided by the extension.

### Step 3: Clone this Repository
Make a copy of this repository on your machine with the following command:
``` bash
git clone https://github.com/LTU-Actor/prizm_ros2_arduino.git
```

### Step 4: Build and Flash the Controller
With the PRIZM controller connected to you machine over USB, use PlatformIO to build and upload the code to the Arduino. The controller should now run prizm_ros2_arduino after rebooting.

## Usage
While this code is intended to interface with [prizm_ros2](https://github.com/LTU-Actor/prizm_ros2), the controller itself does not run ROS2. Instead, control messages are sent over serial in a JSON-like string, in the following format:
```
left:<int>,right:<int>,green:<bool>,red:<bool>;
```
Where left controls the left motor [-100,100], right controls the right motor [-100,100], green controls the green LED [0,1], and red controls the red LED [0,1].
