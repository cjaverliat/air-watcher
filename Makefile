CXX=g++
CXX_FLAGS=-O3 -g -Wall -Werror -pedantic -std=c++11

BUILD_DIR=./build
PROG=airwatcher
RESOURCES=$(wildcard resources/*)

SRCS=$(shell find . -name '*.cpp')
OBJS=$(SRCS:%=$(BUILD_DIR)/%.o)

$(BUILD_DIR)/$(PROG): $(OBJS)
	mkdir -p ${BUILD_DIR}/resources/
	cp -f -t ${BUILD_DIR}/resources/ $(RESOURCES)
	$(CXX) -o $@ $^

$(BUILD_DIR)/%.cpp.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXX_FLAGS) -c $< -o $@

.PHONY: clean

clean:
	$(RM) -r $(BUILD_DIR)
