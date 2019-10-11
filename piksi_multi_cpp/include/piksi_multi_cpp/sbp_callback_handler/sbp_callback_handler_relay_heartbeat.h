#ifndef PIKSI_MULTI_CPP_SBP_CALLBACK_HANDLER_SBP_CALLBACK_HANDLER_RELAY_HEARTBEAT_H_
#define PIKSI_MULTI_CPP_SBP_CALLBACK_HANDLER_SBP_CALLBACK_HANDLER_RELAY_HEARTBEAT_H_

#include <libsbp/sbp.h>
#include <piksi_rtk_msgs/Heartbeat.h>
#include <ros/ros.h>
#include "piksi_multi_cpp/sbp_callback_handler/sbp_callback_handler_relay.h"

namespace piksi_multi_cpp {

class SBPCallbackHandlerRelayHeartbeat
    : public SBPCallbackHandlerRelay<piksi_rtk_msgs::Heartbeat> {
 public:
  SBPCallbackHandlerRelayHeartbeat(const ros::NodeHandle& nh,
                                   const uint16_t sbp_msg_type,
                                   const std::shared_ptr<sbp_state_t>& state);

 private:
  void callback(uint16_t sender_id, uint8_t len, uint8_t msg[]) override;
};

}  // namespace piksi_multi_cpp

#endif  // PIKSI_MULTI_CPP_SBP_CALLBACK_HANDLER_SBP_CALLBACK_HANDLER_RELAY_HEARTBEAT_H_
