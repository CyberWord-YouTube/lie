EXE_NAME := lie


# It is suggested to use a custom built cross toolchain to build a kernel.
# We are using the standard "cc" here, it may work by using
# the host system's toolchain, but this is not guaranteed.
CC := clang
CXX := clang++

override CXXFLAGS += \
    -Wall \
    -Wextra \
    -std=c++17 \

# Internal C preprocessor flags that should not be changed by the user.
override CPPFLAGS := \
    -I Include/ \


CXXFILES := $(shell find -L * -type f -name '*.cpp')

# Default target.
.PHONY: all
all: compile

clean:
	rm lie

# Compilation rules for *.cpp files.
compile:
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(CXXFILES) -o $(EXE_NAME)