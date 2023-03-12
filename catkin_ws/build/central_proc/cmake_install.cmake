# Install script for directory: /home/pi/project/catkin_ws/src/central_proc

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/pi/project/catkin_ws/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/central_proc/action" TYPE FILE FILES
    "/home/pi/project/catkin_ws/src/central_proc/action/CubeReadExec.action"
    "/home/pi/project/catkin_ws/src/central_proc/action/CubeSolveExec.action"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/central_proc/msg" TYPE FILE FILES
    "/home/pi/project/catkin_ws/devel/share/central_proc/msg/CubeReadExecAction.msg"
    "/home/pi/project/catkin_ws/devel/share/central_proc/msg/CubeReadExecActionGoal.msg"
    "/home/pi/project/catkin_ws/devel/share/central_proc/msg/CubeReadExecActionResult.msg"
    "/home/pi/project/catkin_ws/devel/share/central_proc/msg/CubeReadExecActionFeedback.msg"
    "/home/pi/project/catkin_ws/devel/share/central_proc/msg/CubeReadExecGoal.msg"
    "/home/pi/project/catkin_ws/devel/share/central_proc/msg/CubeReadExecResult.msg"
    "/home/pi/project/catkin_ws/devel/share/central_proc/msg/CubeReadExecFeedback.msg"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/central_proc/msg" TYPE FILE FILES
    "/home/pi/project/catkin_ws/devel/share/central_proc/msg/CubeSolveExecAction.msg"
    "/home/pi/project/catkin_ws/devel/share/central_proc/msg/CubeSolveExecActionGoal.msg"
    "/home/pi/project/catkin_ws/devel/share/central_proc/msg/CubeSolveExecActionResult.msg"
    "/home/pi/project/catkin_ws/devel/share/central_proc/msg/CubeSolveExecActionFeedback.msg"
    "/home/pi/project/catkin_ws/devel/share/central_proc/msg/CubeSolveExecGoal.msg"
    "/home/pi/project/catkin_ws/devel/share/central_proc/msg/CubeSolveExecResult.msg"
    "/home/pi/project/catkin_ws/devel/share/central_proc/msg/CubeSolveExecFeedback.msg"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/central_proc/cmake" TYPE FILE FILES "/home/pi/project/catkin_ws/build/central_proc/catkin_generated/installspace/central_proc-msg-paths.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/pi/project/catkin_ws/devel/include/central_proc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/home/pi/project/catkin_ws/devel/share/roseus/ros/central_proc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/pi/project/catkin_ws/devel/share/common-lisp/ros/central_proc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/home/pi/project/catkin_ws/devel/share/gennodejs/ros/central_proc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND "/usr/bin/python3" -m compileall "/home/pi/project/catkin_ws/devel/lib/python3/dist-packages/central_proc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python3/dist-packages" TYPE DIRECTORY FILES "/home/pi/project/catkin_ws/devel/lib/python3/dist-packages/central_proc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/pi/project/catkin_ws/build/central_proc/catkin_generated/installspace/central_proc.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/central_proc/cmake" TYPE FILE FILES "/home/pi/project/catkin_ws/build/central_proc/catkin_generated/installspace/central_proc-msg-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/central_proc/cmake" TYPE FILE FILES
    "/home/pi/project/catkin_ws/build/central_proc/catkin_generated/installspace/central_procConfig.cmake"
    "/home/pi/project/catkin_ws/build/central_proc/catkin_generated/installspace/central_procConfig-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/central_proc" TYPE FILE FILES "/home/pi/project/catkin_ws/src/central_proc/package.xml")
endif()

