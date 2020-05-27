CXX=g++
CXX_FLAGS=-O3 -g -Wall -Werror -pedantic -std=c++17

BUILD_DIR=./build
PROG=airwatcher

SRCS=$(shell find . -name '*.cpp')
OBJS=$(SRCS:%=$(BUILD_DIR)/%.o)

$(PROG): $(OBJS)
	$(CXX) -o $(PROG) $(OBJS)

$(BUILD_DIR)/$(PROG): $(OBJS)
	$(CXX) $(OBJS) -o $@

$(BUILD_DIR)/%.cpp.o: %.cpp
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXX_FLAGS) -c $< -o $@

.PHONY: clean

clean:
	$(RM) -r $(BUILD_DIR)
