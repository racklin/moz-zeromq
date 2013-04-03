cmake_minimum_required(VERSION 2.8)

project(moz0mq)

find_package(PkgConfig)

if(IS_DIRECTORY ${XULRUNNER-SDK})

    set(XUL_INCLUDE_DIRS ${XULRUNNER-SDK}/include ${XULRUNNER-SDK}/include/nspr)
    set(XUL_LIBRARY_DIRS ${XULRUNNER-SDK}/lib)
    set(XUL_LIBRARIES xpcomglue_s xpcom mozalloc plds4 plc4 nspr4)

    link_directories(${XUL_LIBRARY_DIRS})
    include_directories(${XUL_INCLUDE_DIRS})

else(IS_DIRECTORY ${XULRUNNER-SDK})

    pkg_check_modules(XUL libxul)
    if (XUL_FOUND)
      link_directories(${XUL_LIBRARY_DIRS})
      include_directories(${XUL_INCLUDE_DIRS})
    endif(XUL_FOUND)

endif(IS_DIRECTORY ${XULRUNNER-SDK})

pkg_check_modules(ZMQ libzmq)
if (ZMQ_FOUND)
  link_directories(${ZMQ_LIBRARY_DIRS})
  include_directories(${ZMQ_INCLUDE_DIRS})
endif(ZMQ_FOUND)

set(CMAKE_CXX_FLAGS "-std=c++0x -fshort-wchar")

add_library(moz0mq SHARED nsZMQImpl.cpp ZMQModules.cpp)
target_link_libraries(moz0mq ${XUL_LIBRARIES})
target_link_libraries(moz0mq ${ZMQ_LIBRARIES})

add_executable(test_rep test_rep.c)
target_link_libraries(test_rep ${ZMQ_LIBRARIES})

add_executable(test_req test_req.c)
target_link_libraries(test_req ${ZMQ_LIBRARIES})

add_executable(test_pub test_pub.c)
target_link_libraries(test_pub ${ZMQ_LIBRARIES})

add_executable(test_sub test_sub.c)
target_link_libraries(test_sub ${ZMQ_LIBRARIES})
