# CC = gcc
# CFLAGS = -Wall -Wextra -O2 -g -Iinclude
# SRC_DIR = src
# OBJ_DIR = obj
# TARGET = jhpsh

# # src/*.c 자동 탐색
# SRCS = $(wildcard $(SRC_DIR)/*.c)

# # obj/*.o 로 변환
# OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

# # dependency 파일 (.d)
# DEPS = $(OBJS:.o=.d)

# all: $(TARGET)

# # 실행파일 생성 (링크 단계)
# $(TARGET): $(OBJS)
# 	$(CC) $(OBJS) -o $@

# # 컴파일 단계
# $(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
# 	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

# clean:
# 	rm -f $(OBJ_DIR)/*.o $(OBJ_DIR)/*.d $(TARGET)

# -include $(DEPS)

# .PHONY: all clean

CC = gcc

# C++ 컴파일러 옵션
CXXFLAGS = -Wall -O2

# 링커 옵션
LDFLAGS =

# 헤더파일 경로
INCLUDE = -Iinclude/

# 소스 파일 디렉토리
SRC_DIR = ./src

# 오브젝트 파일 디렉토리
OBJ_DIR = ./obj

# 생성하고자 하는 실행 파일 이름
TARGET = jhpsh

# Make 할 소스 파일들
# wildcard 로 SRC_DIR 에서 *.cc 로 된 파일들 목록을 뽑아낸 뒤에
# notdir 로 파일 이름만 뽑아낸다.
# (e.g SRCS 는 foo.cc bar.cc main.cc 가 된다.)
SRCS = $(notdir $(wildcard $(SRC_DIR)/*.c))

OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)

# OBJS 안의 object 파일들 이름 앞에 $(OBJ_DIR)/ 을 붙인다.
OBJECTS = $(patsubst %.o,$(OBJ_DIR)/%.o,$(OBJS))
DEPS = $(OBJECTS:.o=.d)

all: $(TARGET)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CXXFLAGS) $(INCLUDE) -c $< -o $@ -MD $(LDFLAGS)

$(TARGET) : $(OBJECTS)
	$(CC) $(CXXFLAGS) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

.PHONY: clean all
clean:
	rm -f $(OBJECTS) $(DEPS) $(TARGET)

-include $(DEPS)