#ifndef PIKSI_MULTI_CPP_ROS_RECEIVER_H_
#define PIKSI_MULTI_CPP_ROS_RECEIVER_H_

#include <libsbp/sbp.h>
#include <ros/ros.h>
#include <memory>
#include <string>
#include <vector>
#include "piksi_multi_cpp/device.h"

namespace piksi_multi_cpp {

// This class offers a ROS interface for Piksi Multi receivers. It automatically
// assigns a type to a device and offers ROS topics and services.
class ROSReceiver {
 public:
  /* The three types of receivers are

  kBaseStationReceiver: The static base station sending out RTK corrections.

  kPositionReceiver: The moving rover receiving RTK corrections from the
  base station and broadcasting RTK GPS positions.

  kAttitudeReceiver: The moving rover receiving RTK corrections from a moving
  reference receiver and broadcasting the moving baseline (also referred to as
  heading). */
  enum Type {
    kBaseStationReceiver = 0,
    kPositionReceiver,
    kAttitudeReceiver,
    kUnknown
  };
  static std::vector<Type> kTypeVec;

  ROSReceiver(const ros::NodeHandle& nh, const std::shared_ptr<Device>& device);

  // Closes device.
  ~ROSReceiver();

  // Open device.
  bool init();
  // Read device and process SBP callbacks.
  void process();

  // Factory methods to create receivers.

  // Create receiver by setting node handle, hardware device, and type.
  // Warning: Node handle namespace must be unique for every device.
  static std::shared_ptr<ROSReceiver> create(
      const ros::NodeHandle& nh, const std::shared_ptr<Device>& device,
      const Type type);

  // Create receiver from node handle and hardware device. Auto infer type from
  // device.
  // Warning: Node handle namespace must be unique for every device.
  static std::shared_ptr<ROSReceiver> create(
      const ros::NodeHandle& nh, const std::shared_ptr<Device>& device);

  // Create all receivers from node handle only. Autodetects connected hardware
  // devices, infers device type from Piksi firmware settings and assigns unique
  // name spaces.
  static std::vector<std::shared_ptr<ROSReceiver>> createAllReceivers(
      const ros::NodeHandle& nh);

 protected:
  // ROS node handle in the correct receiver namespace.
  ros::NodeHandle nh_;
  // The actual hardware interface.
  std::shared_ptr<Device> device_;

 private:
  // Infer receiver type from Piksi firmware settings.
  static Type inferType(const std::shared_ptr<Device>& dev);
  static std::string createNameSpace(const Type type, const size_t id);

  // The sbp state.
  std::shared_ptr<sbp_state_t> state_;
};

}  // namespace piksi_multi_cpp

#endif  // PIKSI_MULTI_CPP_ROS_RECEIVER_H_
