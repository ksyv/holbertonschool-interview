#!/usr/bin/python3
"""
Module for test if data's byte sequence is UTF8 compatible.
"""

def validUTF8(data):
    index = 0
    while index < len(data):
        byte = data[index]

        if (byte >> 7) == 1:
            one_counter = 0
            while (byte >> (7 - one_counter)) == 1:
                one_counter += 1

            if one_counter == 1 or one_counter > 4:
                return False

            if one_counter > 4 or index + one_counter > len(data):
                return False

            for i in range(1, one_counter):
                next_byte = data[index + i]
                if (next_byte >> 6) != 2:
                    return False

            index += one_counter

        index += 1
    return True
