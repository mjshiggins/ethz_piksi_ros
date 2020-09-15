cmake_minimum_required(VERSION 3.5)
project(piksi_rtk_msgs)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(builtin_interfaces REQUIRED)
find_package(rosidl_default_generators REQUIRED)

## Find catkin macros and libraries
#find_package(catkin REQUIRED
#  COMPONENTS
#    rospy
#    message_generation
#    std_msgs
#    geometry_msgs
#    sensor_msgs
#)

# find dependencies
set(${PROJECT_NAME}_DEPS
  std_msgs
  geometry_msgs
  sensor_msgs
)
foreach(dep IN ITEMS ${${PROJECT_NAME}_DEPS})
  find_package(${dep} REQUIRED)
endforeach(dep)

#######################################
## Declare ROS messages and services ##
#######################################

## Generate messages in the 'msg' folder
#add_message_files(
#  FILES
rosidl_generate_interfaces(${PROJECT_NAME}
    "msg/AgeOfCorrections.msg"
    "msg/BaselineEcef.msg"
    "msg/BaselineHeading.msg"
    "msg/BaselineNed.msg"
    "msg/BasePosEcef.msg"
    "msg/BasePosLlh.msg"
    "msg/DeviceMonitorV2315.msg"
    "msg/Dops.msg"
    "msg/DopsMulti.msg"
    "msg/ExtEvent.msg"
    "msg/GpsTime.msg"
    "msg/GpsTimeMulti.msg"
    "msg/Heartbeat.msg"
    "msg/ImuAuxMulti.msg"
    "msg/ImuRawMulti.msg"
    "msg/InfoWifiCorrections.msg"
    "msg/Log.msg"
    "msg/MagRaw.msg"
    "msg/MeasurementStateV241.msg"
    "msg/Observation.msg"
    "msg/PosEcef.msg"
    "msg/PosEcefCov.msg"
    "msg/PositionSampling.msg"
    "msg/PositionWithCovariance.msg"
    "msg/PositionWithCovarianceStamped.msg"
    "msg/PosLlh.msg"
    "msg/PosLlhCov.msg"
    "msg/PosLlhMulti.msg"
    "msg/ReceiverState.msg"
    "msg/ReceiverStateV2215.msg"
    "msg/ReceiverStateV2315.msg"
    "msg/ReceiverStateV241.msg"
    "msg/ReceiverStateV265.msg"
    "msg/TrackingState.msg"
    "msg/TrackingStateV2215.msg"
    "msg/TrackingStateV2315.msg"
    "msg/TrackingStateV263.msg"
    "msg/UartState.msg"
    "msg/UartStateV2315.msg"
    "msg/UtcTimeMulti.msg"
    "msg/VelEcef.msg"
    "msg/VelEcefCov.msg"
    "msg/VelNed.msg"
    "msg/VelNedCov.msg"
    "msg/VelocityWithCovariance.msg"
    "msg/VelocityWithCovarianceStamped.msg"

    "srv/EnuOrigin.srv"
    "srv/SamplePosition.srv"
    "srv/SettingsWrite.srv"
    "srv/SettingsReadReq.srv"
    "srv/SettingsReadResp.srv"

    DEPENDENCIES builtin_interfaces ${${PROJECT_NAME}_DEPS}
)

## Generate services in the 'srv' folder
#add_service_files(
#  FILES
#    EnuOrigin.srv
#    SamplePosition.srv
#    SettingsWrite.srv
#    SettingsReadReq.srv
#    SettingsReadResp.srv
#)

## Generate added messages and services with any dependencies listed here
#generate_messages(
#  DEPENDENCIES
#    std_msgs
#    geometry_msgs
#    sensor_msgs
#)

###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if your package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
#catkin_package(
##  INCLUDE_DIRS
##  LIBRARIES
#  CATKIN_DEPENDS
#    message_runtime
#    std_msgs
#    geometry_msgs
##  DEPENDS
#)

ament_export_dependencies(rosidl_default_runtime)

ament_package()