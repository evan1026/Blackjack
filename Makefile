CXX ?= clang++

default:
	$(CXX) *.cpp -o blackjack -std=c++11
