#!/bin/python3

import math
import os
import random
import re
import sys



if __name__ == '__main__':
    n = int(input().strip())
    if n>=1 and n<=100:
        if (n%2==0):
            if ((n>=2 and n<=5 ) or n>21):
                print("Not Weird")
            else:
                print("Weird")           
        else:
            print("Weird")
