# this one is important
SET(CMAKE_SYSTEM_NAME Linux)
#this one not so much
SET(CMAKE_SYSTEM_VERSION 1)


# 交叉编译工具链安装路径 (需要修改)
SET(MY_TOOL_PATH /home/zucker/Project/3.vatics/tools/toolchain/vtcs_toolchain/arm-eabi-uclibc/usr)
SET(MY_TOOL_BIN_PATH ${MY_TOOL_PATH}/bin)
# 交叉编译工具链前缀名 (需要修改)
SET(MY_CROSS_COMPILER arm-buildroot-linux-uclibcgnueabi-)


# C/C++ 交叉编译工具链
SET(CMAKE_C_COMPILER   ${MY_TOOL_BIN_PATH}/${MY_CROSS_COMPILER}gcc)
SET(CMAKE_CXX_COMPILER ${MY_TOOL_BIN_PATH}/${MY_CROSS_COMPILER}g++)

# 交叉编译环境库路径
SET(CMAKE_FIND_ROOT_PATH ${MY_TOOL_PATH}/lib)

# search for programs in the build host directories
SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
# for libraries and headers in the target directories
SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)


# 该平台环境有点特殊，需要手动source编译环境，不会会提示"libmpc.so.3找不到"
# source目的：export LD_LIBRARY_PATH=xxx/arm-eabi-uclibc/usr/lib/:$LD_LIBRARY_PATH


