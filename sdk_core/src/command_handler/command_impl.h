//
// The MIT License (MIT)
//
// Copyright (c) 2019 Livox. All rights reserved.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//

#ifndef LIVOX_SDK_COMMAND_IMPL_H
#define LIVOX_SDK_COMMAND_IMPL_H

namespace livox {

/** The maximum buffer size of command */
static const uint32_t kMaxCommandBufferSize = 1536;
static const uint16_t KDefaultTimeOut = 500;

/** Enum that represents the index of command set. */
typedef enum {
  kCommandSetGeneral = 0, /**< general command set. */
  kCommandSetLidar,       /**< LiDAR command set. */
  kCommandSetHub          /**< hub command set. */
} CommandSet;

/**  Enum that represents the command id. */
typedef enum {
  /** General command set, broadcast command. */
  kCommandIDGeneralBroadcast = 0,
  /**
   * General command set, handshake command. When received broadcast from a Livox LiDAR or Hub, a handshake command
   * should be sent back to the same port to negotiate connection with the device.
   */
  kCommandIDGeneralHandshake = 1,
  /**
   * General command set, query the information of device.
   */
  kCommandIDGeneralDeviceInfo = 2,
  /**
   * General command set, heartbeat command. after connected, a heartbeat command should be sent at least every second.
   */
  kCommandIDGeneralHeartbeat = 3,
  /**
   * General command set, enable or disable the sampling.
   *
   */
  kCommandIDGeneralControlSample = 4,
  /**
   * General command set, change the coordinate of point cloud data.
   */
  kCommandIDGeneralCoordinateSystem = 5,
  /**
   * General command set, disconnect the device.
   */
  kCommandIDGeneralDisconnect = 6,
  /**
   * General command set, a message command from a connected device to notify exceptions, in 10Hz.
   */
  kCommandIDGeneralPushAbnormalState = 7,
  /**
   * General command set, set the IP of the a device.
   */
  kCommandIDGeneralConfigureStaticDynamicIP = 8,
  /**
   * General command set, get the IP of the a device.
   */
  kCommandIDGeneralGetDeviceIPInformation = 9,

  /**
   * ******************************************************
   * Don't add command id after kCommandIDGeneralCommandCount.
   */
  kCommandIDGeneralCommandCount
} GeneralCommandID;

static const uint16_t GeneralCommandTimeout[kCommandIDGeneralCommandCount] = {KDefaultTimeOut,
                                                                              KDefaultTimeOut,
                                                                              KDefaultTimeOut,
                                                                              KDefaultTimeOut,
                                                                              KDefaultTimeOut,
                                                                              KDefaultTimeOut,
                                                                              KDefaultTimeOut,
                                                                              KDefaultTimeOut,
                                                                              KDefaultTimeOut,
                                                                              KDefaultTimeOut};

/**  Enum that represents the command id. */
typedef enum {
  /**
   * Lidar command set, set the working mode and sub working mode of a LiDAR.
   */
  kCommandIDLidarSetMode = 0,
  /**
   * Lidar command set, set the parameters of a LiDAR.
   */
  kCommandIDLidarSetExtrinsicParameter = 1,
  /**
   * Lidar command set, get the parameters of a LiDAR.
   */
  kCommandIDLidarGetExtrinsicParameter = 2,
  /**
   * Lidar command set, enable or disable the rain/fog suppression of a LiDAR.
   */
  kCommandIDLidarControlRainFogSuppression = 3,

  /**
   * ******************************************************
   * Don't add command id after kCommandIDLidarCommandCount.
   */
  kCommandIDLidarCommandCount
} LidarCommandID;

static const uint16_t LidarCommandTimeout[kCommandIDLidarCommandCount] = {KDefaultTimeOut,
                                                                          KDefaultTimeOut,
                                                                          KDefaultTimeOut,
                                                                          KDefaultTimeOut};

/**  Enum that represents the command id. */
typedef enum {
  /**
   * Hub command set, get the information of connected Livox LiDAR.
   */
  kCommandIDHubQueryLidarInformation = 0,
  /**
   * Hub command set, set the working mode of connected Livox LiDAR.
   */
  kCommandIDHubSetMode = 1,
  /**
   * Hub command set, enable or disable the power supply of the hub slot.
   */
  kCommandIDHubControlSlotPower = 2,
  /**
   * Hub command set, set the parameters of connected Livox LiDAR.
   */
  kCommandIDHubSetExtrinsicParameter = 3,
  /**
   * Hub command set, get the parameters of connected Livox LiDAR.
   */
  kCommandIDHubGetExtrinsicParameter = 4,
  /**
   * Hub command set, get the working state of the connected Livox LiDAR.
   */
  kCommandIDHubQueryLidarDeviceStatus = 5,
  /**
   * Hub command set, enable or disable calculating the parameters.
   */
  kCommandIDHubExtrinsicParameterCalculation = 6,
  /**
   * Hub command set, open or close the rain and fog mode of the connected Livox LiDAR.
   */
  kCommandIDHubRainFogSuppression = 7,

  /**
   * ******************************************************
   * Don't add command id after kCommandIDHubCommandCount.
   */
  kCommandIDHubCommandCount
} HubCommandID;

static const uint16_t HubCommandTimeout[kCommandIDHubCommandCount] = {KDefaultTimeOut,
                                                                      KDefaultTimeOut,
                                                                      KDefaultTimeOut,
                                                                      KDefaultTimeOut,
                                                                      KDefaultTimeOut,
                                                                      KDefaultTimeOut,
                                                                      KDefaultTimeOut,
                                                                      KDefaultTimeOut};

/**
 * Enum that represents the command type.
 */
typedef enum {
  /** command type, which requires response from the receiver. */
  kCommandTypeCmd = 0,
  /** acknowledge type, which is the response of command type. */
  kCommandTypeAck = 1,
  /** message type, which is sent at a specified frequency. */
  kCommandTypeMsg = 2
} CommandType;
}  // namespace livox
#endif  // LIVOX_SDK_COMMAND_IMPL_H
