# 声明：以下所有内容都是deepseek写的，我也不知道对不对，先这样吧
cmake_minimum_required(VERSION 3.20)   # C++20 需要较新的 CMake 版本
project(MyProject VERSION 1.0.0 LANGUAGES CXX)

# 强制使用 MSVC 编译器，否则报错
if(NOT MSVC)
    message(FATAL_ERROR "This project requires MSVC compiler on Windows.")
endif()

# 设置 C++20 标准（强制使用，不启用编译器扩展）
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 可选：设置生成的可执行文件输出目录（放在 build 下）
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# 收集 src/ 下所有 .cpp 文件（如新增文件后需重新运行 CMake 配置）
file(GLOB SOURCES "src/*.cpp")

# 创建可执行文件
add_executable(MyProject ${SOURCES})

# 添加头文件搜索路径（PRIVATE 表示仅本目标需要）
target_include_directories(MyProject PRIVATE include)

# 启用所有警告
target_compile_options(MyProject PRIVATE /Wall)