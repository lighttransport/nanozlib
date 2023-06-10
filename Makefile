_CXXENV = $(shell printenv 'CXX')

ifeq ($(_CXXENV),)
  CXX := clang++
endif

all:
	$(CXX) -o test_nanozdec test_nanozdec.cc
