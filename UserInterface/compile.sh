#!/bin/bash

gcc file_ops.cpp -lstdc++ -o file_ops.e

c++  UserInterface.cpp `wx-config --cxxflags --libs` -o UserInterface.e
