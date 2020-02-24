# AROSYS

[![Build Status](https://travis-ci.com/cyberbotics/AROSYS.svg?token=F34e6fzg7bnX1UAbdRpa&branch=master)](https://travis-ci.com/cyberbotics/AROSYS)
[![Safety](https://img.shields.io/badge/safety-secure-brightgreen.svg)](https://app.gitguardian.com)
[![Software License](https://img.shields.io/badge/license-Apache--2.0-brightgreen.svg)](LICENSE)

## Components
The following components are new components for RobMoSys in order to be able to use them with the [Webots simulator](https://cyberbotics.com).

### ComponentWebots
This component allows the user to use Webots simulator instead of Gazebo, PlayerStage, etc. There exists a pre-requirement to use Webots. You have to execute this command once in a Terminal and restart the computer/Virtual Machine. Don't forget to adapt the path if necessary.
`echo -e "export WEBOTS_HOME=/home/smartsoft/SOFTWARE/webots" >> ~/.profile`

![ComponentWebots](ComponentWebots/model/ComponentWebotsComponentDefinition.jpg)

### ComponentWebotsBumper

This component configures bumper's sensors in SmartSoft according to Webots prototype sensors and provides the bumper value.

![ComponentWebotsBumper](ComponentWebotsBumper/model/ComponentWebotsBumperComponentDefinition.jpg)

| Input  | Output |
| ------ | ------ |
|   | **BumperEventServiceOut**: bumper value |


### ComponentWebotsLidar

This component configures lidar's sensors in SmartSoft according to Webots prototype sensors and provides the sensor's data.

![ComponentWebotsLidar](ComponentWebotsLidar/model/ComponentWebotsLidarComponentDefinition.jpg)

| Input  | Output |
| ------ | ------ |
| **BaseStateServiceIn**: state of the robot base (position and orientation) | **LaserServiceOut**: lidar values |

> **Note** : It is important to mentionned that the lidar range has to be under 65.535 meter otherwise it will be set at 65 meter because the variable type to store the value is `short`. This comes from source files generated by SmartMDSD. Maintainers will be alerted to this problem so that it can be improved.

### ComponentWebotsPioneer3DX
This component configures in SmartSoft the [Pioneer 3-DX](https://cyberbotics.com/doc/guide/pioneer-3dx) robot from Adept according to Webots prototype robot.

![ComponentWebotsPioneer3DX](ComponentWebotsPioneer3DX/model/ComponentWebotsPioneer3DXComponentDefinition.jpg)

| Inputs  | outputs |
| ------- | ------- |
| **LocalizationUpdateServiceIn**: not implemented yet | **BatteryEventServiceOut**: not implemented yet |
| **NavigationVelocityServiceIn**: velocity commands (linear velocities and turnrate) | **BaseStateServiceOut**: state of the robot base (position and orientation) |

### ComponentWebotsRobotino3
This component configures in SmartSoft the [Robotino 3](https://cyberbotics.com/doc/guide/robotino3) robot from Festo according to Webots prototype robot.

![ComponentWebotsRobotino3](ComponentWebotsRobotino3/model/ComponentWebotsRobotino3ComponentDefinition.jpg)

| Inputs  | outputs |
| ------- | ------- |
| **LocalizationUpdateServiceIn**: not implemented yet | **BatteryEventServiceOut**: not implemented yet |
| **NavigationVelocityServiceIn**: velocity commands (linear velocities and turnrate) | **BaseStateServiceOut**: state of the robot base (position and orientation) |

### ComponentWebotsTIAGo
This component configures in SmartSoft all versions of TIAGo's  robot from Pal Robotics according to Webots prototype robot.

![ComponentWebotsTIAGo](ComponentWebotsTIAGo/model/ComponentWebotsTIAGoComponentDefinition.jpg)

| Inputs  | outputs |
| ------- | ------- |
| **LocalizationUpdateServiceIn**: not implemented yet | **BatteryEventServiceOut**: not implemented yet |
| **NavigationVelocityServiceIn**: velocity commands (linear velocities and turnrate) | **BaseStateServiceOut**: state of the robot base (position and orientation) |

---

## Systems
The following systems are examples to be able to test new components.

### SystemLaserObstacleAvoidTiagoWebotsSimulator
This system is a copy of the `SystemLaserObstacleAvoidTiagoGazeboSimulator` in order to show that the new components developed to use Webots simulator are working since the robot has the same behavior as expected.

![SystemLaserObstacleAvoidTiagoWebotsSimulator](SystemLaserObstacleAvoidTiagoWebotsSimulator/model/SystemLaserObstacleAvoidTiagoWebotsSimulator.jpg)

A [TIAGo Iron](https://cyberbotics.com/doc/guide/tiago-iron) is used with a lidar that seems to be a [Sick TIM150-3010300](https://www.sick.com/ca/en/detection-and-ranging-solutions/2d-lidar-sensors/tim1xx/tim150-3010300/p/p595144?ff_data=JmZmX2lkPXA1OTUxNDQmZmZfbWFzdGVySWQ9cDU5NTE0NCZmZl90aXRsZT1UaU0xNTAtMzAxMDMwMCZmZl9xdWVyeT0mZmZfcG9zPTImZmZfb3JpZ1Bvcz0yJmZmX3BhZ2U9MSZmZl9wYWdlU2l6ZT0yNCZmZl9vcmlnUGFnZVNpemU9MjQmZmZfc2ltaT05MS4w) with a range of 10 meters and an aperture angle of 200 degree.

### SystemLaserObstacleAvoidP3dxWebotsSimulator
This system is a copy of the `SystemLaserObstacleAvoidP3dxPlayerStageSimulator` in order to show that the new components developed to use Webots simulator are working since the robot has the same behavior as expected.

![SystemLaserObstacleAvoidP3dxWebotsSimulator](SystemLaserObstacleAvoidP3dxWebotsSimulator/model/SystemLaserObstacleAvoidP3dxWebotsSimulator.jpg)

A [Pioneer 3-DX](https://cyberbotics.com/doc/guide/pioneer-3dx) is used with a lidar that seems to be a [Sick TIM150-3010300](https://www.sick.com/ca/en/detection-and-ranging-solutions/2d-lidar-sensors/tim1xx/tim150-3010300/p/p595144?ff_data=JmZmX2lkPXA1OTUxNDQmZmZfbWFzdGVySWQ9cDU5NTE0NCZmZl90aXRsZT1UaU0xNTAtMzAxMDMwMCZmZl9xdWVyeT0mZmZfcG9zPTImZmZfb3JpZ1Bvcz0yJmZmX3BhZ2U9MSZmZl9wYWdlU2l6ZT0yNCZmZl9vcmlnUGFnZVNpemU9MjQmZmZfc2ltaT05MS4w) with a range of 10 meters and an aperture angle of 180 degree.

### SystemWebotsMultiRobots
This system shows an example of multi-robots simulation. All the robots are using a [lidar sensor](https://cyberbotics.com/doc/guide/lidar-sensors) (`ComponentWebotsLidar`) to perfom obstacle avoidance.

### SystemWebotsPioneer3DXNavigation
This system shows a complete example of communication between a [lidar sensor](https://cyberbotics.com/doc/guide/lidar-sensors) (`ComponentWebotsLidar`) used by a [Pioneer 3-DX](https://cyberbotics.com/doc/guide/pioneer-3dx) robot (`ComponentWebotsPioneer3DX`) to navigate in a square arena filled with obstacles. It works with the new components developped to use Webots.

![SystemWebotsPioneer3DXNavigation](SystemWebotsPioneer3DXNavigation/model/SystemWebotsPioneer3DXNavigation.jpg)

### SystemWebotsRobotino3Navigation
This system shows a complete example of communication between a [lidar sensor](https://cyberbotics.com/doc/guide/lidar-sensors) (`ComponentWebotsLidar`) used by a [Robotino 3](https://cyberbotics.com/doc/guide/robotino3) robot (`ComponentWebotsRobotino3`) to navigate in a square arena filled with obstacles. It works with the new components developped to use Webots.

![SystemWebotsRobotino3Navigation](SystemWebotsRobotino3Navigation/model/SystemWebotsRobotino3Navigation.jpg)

### SystemWebotsTiagoNavigation
This system is a copy of the `SystemTiagoNavigation` in order to show that the new components developed to use Webots simulator are working since the robot has the same behavior as expected.

![SystemWebotsTiagoNavigation](SystemWebotsTiagoNavigation/model/SystemWebotsTiagoNavigation.jpg)

