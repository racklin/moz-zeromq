cmake_minimum_required(VERSION 2.6)

project(moz0mq)

find_package(PkgConfig)

pkg_check_modules(XUL libxul)
if (XUL_FOUND)
  link_directories(${XUL_LIBRARY_DIRS})
  include_directories(${XUL_INCLUDE_DIRS})
endif(XUL_FOUND)

pkg_check_modules(ZMQ libzmq)
if (ZMQ_FOUND)
  link_directories(${ZMQ_LIBRARY_DIRS})
  include_directories(${ZMQ_INCLUDE_DIRS})
endif(ZMQ_FOUND)

add_library(moz0mq SHARED nsZMQImpl.cpp ZMQModules.cpp)
target_link_libraries(moz0mq ${XUL_LIBRARIES})
target_link_libraries(moz0mq ${ZMQ_LIBRARIES})

add_executable(test_rep test_rep.c)
target_link_libraries(test_rep ${ZMQ_LIBRARIES})

add_executable(test_req test_req.c)
target_link_libraries(test_req ${ZMQ_LIBRARIES})
