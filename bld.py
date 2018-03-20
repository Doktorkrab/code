#!/usr/bin/python
import os
from sys import argv

CPP_ARGS = ['-DLOCAL', '-pedantic', '-Wall', '-Wextra', '-std=c++14']


argv = argv[1:]

for arg in argv:  # parsing args
    if os.path.exists(arg + '.cpp'):
        os.system('g++ -o ' + arg + ' ' + ' '.join(CPP_ARGS) + ' ' + arg + '.cpp')
    elif os.path.exists(arg + '.py'):
        os.system('python ' + arg + '.py')
    else:
        print("file {0} not found".format(arg))
