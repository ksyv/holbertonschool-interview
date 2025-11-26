#!/usr/bin/python3
"""
Script that reads stdin line by line and computes metrics
"""
import sys


def print_stats(total_size, status_codes):
    """
    Prints the accumulated statistics
    """
    print("File size: {}".format(total_size))
    for key in sorted(status_codes.keys()):
        if status_codes[key] > 0:
            print("{}: {}".format(key, status_codes[key]))


if __name__ == "__main__":
    status_codes = {
        200: 0, 301: 0, 400: 0, 401: 0,
        403: 0, 404: 0, 405: 0, 500: 0
    }
    total_size = 0
    line_count = 0

    try:
        for line in sys.stdin:
            parts = line.split()
           
            if len(parts) < 7:
                continue

            try:
                file_size = int(parts[-1])
                total_size += file_size
            except (ValueError, IndexError):

                continue

            try:
                status_code = int(parts[-2])
                if status_code in status_codes:
                    status_codes[status_code] += 1
            except (ValueError, IndexError):
                pass

            line_count += 1

            if line_count % 10 == 0:
                print_stats(total_size, status_codes)

    except KeyboardInterrupt:
        print_stats(total_size, status_codes)
        raise

    print_stats(total_size, status_codes)
