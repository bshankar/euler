import os
import glob
import sys
import timeit


def intro():
    message = """\n\nEuler 0.1 
author: Bhavani Shankar (ebs@openmailbox.org)
==================================================
"""
    print(message)


def compile(n, mode):
    if mode == "debug":
        cxxflags = "-O0 -g -lgmp -lgmpxx"
    elif mode == "release":
        cxxflags = "-Ofast -march=native -lgmp -lgmpxx"
    else:
        return False

    compile_command = "g++ %s %s -o %s" %(cxxflags,
                                                 "solutions/%s.cpp"%n,
                                                 "../bin/%s"%n)
    print("Compiling %s ...\n"%mode)
    os.system(compile_command)
    return True


def solve(n):
    bin_file = "../bin/" + str(n)
    if os.path.isfile(bin_file):
       os.system(bin_file) 


if __name__ == "__main__":
    intro()
    try:
        command = sys.argv[1]
        n = sys.argv[2]
        compile(n, command)
        print("Time elapsed: " +
              str(timeit.timeit("solve(%s)"%n,
              setup="from __main__ import solve", number=1)) + "s")
    except:
        n = sys.argv[1]
        print("Time elapsed: " +
              str(timeit.timeit("solve(%s)"%n,
              setup="from __main__ import solve", number=1)) + "s")
