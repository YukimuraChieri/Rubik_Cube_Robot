# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "kociemba_solve: 0 messages, 2 services")

set(MSG_I_FLAGS "-Istd_msgs:/opt/ros/noetic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(kociemba_solve_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/pi/project/catkin_ws/src/kociemba_solve/srv/KociembaSolve.srv" NAME_WE)
add_custom_target(_kociemba_solve_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "kociemba_solve" "/home/pi/project/catkin_ws/src/kociemba_solve/srv/KociembaSolve.srv" ""
)

get_filename_component(_filename "/home/pi/project/catkin_ws/src/kociemba_solve/srv/RandomSolve.srv" NAME_WE)
add_custom_target(_kociemba_solve_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "kociemba_solve" "/home/pi/project/catkin_ws/src/kociemba_solve/srv/RandomSolve.srv" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages

### Generating Services
_generate_srv_cpp(kociemba_solve
  "/home/pi/project/catkin_ws/src/kociemba_solve/srv/KociembaSolve.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/kociemba_solve
)
_generate_srv_cpp(kociemba_solve
  "/home/pi/project/catkin_ws/src/kociemba_solve/srv/RandomSolve.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/kociemba_solve
)

### Generating Module File
_generate_module_cpp(kociemba_solve
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/kociemba_solve
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(kociemba_solve_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(kociemba_solve_generate_messages kociemba_solve_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/pi/project/catkin_ws/src/kociemba_solve/srv/KociembaSolve.srv" NAME_WE)
add_dependencies(kociemba_solve_generate_messages_cpp _kociemba_solve_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pi/project/catkin_ws/src/kociemba_solve/srv/RandomSolve.srv" NAME_WE)
add_dependencies(kociemba_solve_generate_messages_cpp _kociemba_solve_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(kociemba_solve_gencpp)
add_dependencies(kociemba_solve_gencpp kociemba_solve_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS kociemba_solve_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages

### Generating Services
_generate_srv_eus(kociemba_solve
  "/home/pi/project/catkin_ws/src/kociemba_solve/srv/KociembaSolve.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/kociemba_solve
)
_generate_srv_eus(kociemba_solve
  "/home/pi/project/catkin_ws/src/kociemba_solve/srv/RandomSolve.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/kociemba_solve
)

### Generating Module File
_generate_module_eus(kociemba_solve
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/kociemba_solve
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(kociemba_solve_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(kociemba_solve_generate_messages kociemba_solve_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/pi/project/catkin_ws/src/kociemba_solve/srv/KociembaSolve.srv" NAME_WE)
add_dependencies(kociemba_solve_generate_messages_eus _kociemba_solve_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pi/project/catkin_ws/src/kociemba_solve/srv/RandomSolve.srv" NAME_WE)
add_dependencies(kociemba_solve_generate_messages_eus _kociemba_solve_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(kociemba_solve_geneus)
add_dependencies(kociemba_solve_geneus kociemba_solve_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS kociemba_solve_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages

### Generating Services
_generate_srv_lisp(kociemba_solve
  "/home/pi/project/catkin_ws/src/kociemba_solve/srv/KociembaSolve.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/kociemba_solve
)
_generate_srv_lisp(kociemba_solve
  "/home/pi/project/catkin_ws/src/kociemba_solve/srv/RandomSolve.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/kociemba_solve
)

### Generating Module File
_generate_module_lisp(kociemba_solve
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/kociemba_solve
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(kociemba_solve_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(kociemba_solve_generate_messages kociemba_solve_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/pi/project/catkin_ws/src/kociemba_solve/srv/KociembaSolve.srv" NAME_WE)
add_dependencies(kociemba_solve_generate_messages_lisp _kociemba_solve_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pi/project/catkin_ws/src/kociemba_solve/srv/RandomSolve.srv" NAME_WE)
add_dependencies(kociemba_solve_generate_messages_lisp _kociemba_solve_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(kociemba_solve_genlisp)
add_dependencies(kociemba_solve_genlisp kociemba_solve_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS kociemba_solve_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages

### Generating Services
_generate_srv_nodejs(kociemba_solve
  "/home/pi/project/catkin_ws/src/kociemba_solve/srv/KociembaSolve.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/kociemba_solve
)
_generate_srv_nodejs(kociemba_solve
  "/home/pi/project/catkin_ws/src/kociemba_solve/srv/RandomSolve.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/kociemba_solve
)

### Generating Module File
_generate_module_nodejs(kociemba_solve
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/kociemba_solve
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(kociemba_solve_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(kociemba_solve_generate_messages kociemba_solve_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/pi/project/catkin_ws/src/kociemba_solve/srv/KociembaSolve.srv" NAME_WE)
add_dependencies(kociemba_solve_generate_messages_nodejs _kociemba_solve_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pi/project/catkin_ws/src/kociemba_solve/srv/RandomSolve.srv" NAME_WE)
add_dependencies(kociemba_solve_generate_messages_nodejs _kociemba_solve_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(kociemba_solve_gennodejs)
add_dependencies(kociemba_solve_gennodejs kociemba_solve_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS kociemba_solve_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages

### Generating Services
_generate_srv_py(kociemba_solve
  "/home/pi/project/catkin_ws/src/kociemba_solve/srv/KociembaSolve.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/kociemba_solve
)
_generate_srv_py(kociemba_solve
  "/home/pi/project/catkin_ws/src/kociemba_solve/srv/RandomSolve.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/kociemba_solve
)

### Generating Module File
_generate_module_py(kociemba_solve
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/kociemba_solve
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(kociemba_solve_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(kociemba_solve_generate_messages kociemba_solve_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/pi/project/catkin_ws/src/kociemba_solve/srv/KociembaSolve.srv" NAME_WE)
add_dependencies(kociemba_solve_generate_messages_py _kociemba_solve_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/pi/project/catkin_ws/src/kociemba_solve/srv/RandomSolve.srv" NAME_WE)
add_dependencies(kociemba_solve_generate_messages_py _kociemba_solve_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(kociemba_solve_genpy)
add_dependencies(kociemba_solve_genpy kociemba_solve_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS kociemba_solve_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/kociemba_solve)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/kociemba_solve
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(kociemba_solve_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/kociemba_solve)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/kociemba_solve
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(kociemba_solve_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/kociemba_solve)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/kociemba_solve
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(kociemba_solve_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/kociemba_solve)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/kociemba_solve
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(kociemba_solve_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/kociemba_solve)
  install(CODE "execute_process(COMMAND \"/usr/bin/python3\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/kociemba_solve\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/kociemba_solve
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(kociemba_solve_generate_messages_py std_msgs_generate_messages_py)
endif()
