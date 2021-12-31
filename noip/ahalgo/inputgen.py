#!/usr/bin/env Python
# -*- coding: utf-8 -*-

import random

class Constants(object):
    NUM = 39
    FILENAME = "./arrdata.txt"

if __name__ == "__main__":
    with open(Constants.FILENAME, "w+") as fl:
        fl.write("%s\n" % Constants.NUM)
        for k in range(Constants.NUM):
            fl.write("%s " % random.randint(0, 39))
        fl.write("\n")
        fl.close()

