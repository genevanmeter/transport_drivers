// Copyright 2015 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/* This header must be included by all UDP_DRIVER headers which declare symbols
 * which are defined in the UDP_DRIVER library. When not building the UDP_DRIVER
 * library, i.e. when using the headers in other package's code, the contents
 * of this header change the visibility of certain symbols which the UDP_DRIVER
 * library cannot have, but the consuming code must have inorder to link.
 */

#ifndef UDP_DRIVER__VISIBILITY_CONTROL_HPP_
#define UDP_DRIVER__VISIBILITY_CONTROL_HPP_

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define UDP_DRIVER_EXPORT __attribute__ ((dllexport))
    #define UDP_DRIVER_IMPORT __attribute__ ((dllimport))
  #else
    #define UDP_DRIVER_EXPORT __declspec(dllexport)
    #define UDP_DRIVER_IMPORT __declspec(dllimport)
  #endif
  #ifdef UDP_DRIVER_BUILDING_LIBRARY
    #define UDP_DRIVER_PUBLIC UDP_DRIVER_EXPORT
  #else
    #define UDP_DRIVER_PUBLIC UDP_DRIVER_IMPORT
  #endif
  #define UDP_DRIVER_PUBLIC_TYPE UDP_DRIVER_PUBLIC
  #define UDP_DRIVER_LOCAL
#else
  #define UDP_DRIVER_EXPORT __attribute__ ((visibility("default")))
  #define UDP_DRIVER_IMPORT
  #if __GNUC__ >= 4
    #define UDP_DRIVER_PUBLIC __attribute__ ((visibility("default")))
    #define UDP_DRIVER_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define UDP_DRIVER_PUBLIC
    #define UDP_DRIVER_LOCAL
  #endif
  #define UDP_DRIVER_PUBLIC_TYPE
#endif

#endif  // UDP_DRIVER__VISIBILITY_CONTROL_HPP_
