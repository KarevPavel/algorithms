#!/usr/bin/env python3
import os
import subprocess

size = ['b', 'Kb', 'Mb', 'Gb', 'Tb']


def file_size(file_absolute_path):
    file_size = os.path.getsize(file_absolute_path)
    size_index = 0
    while file_size > 1024:
        size_index = size_index + 1
        file_size = file_size / 1024
    return str(round(file_size, 2)) + size[size_index]


if __name__ == '__main__':
    result_file = '/home/yacopsae/CLionProjects/algo-homework/compression/README.md'
    f = open(result_file, "w")
    f.write('#SIMPLE RLE\n')
    f.write('FILE_NAME|DECOMPRESSED|COMPRESSED|\n')
    f.write('| --- |--- |--- |\n')

    path = '/home/yacopsae/CLionProjects/algo-homework/compression/test'
    bin_path = '/home/yacopsae/CLionProjects/algo-homework/compression/rle/bin/rle'
    for _, _, files in os.walk(path):
        for file in files:
            file_absolute_path = path + '/' + file
            file_size_before = file_size(file_absolute_path)
            process = subprocess.Popen([bin_path, '--input', file_absolute_path, '--compress'])
            process.wait()
            compressed_file = file_absolute_path[:file_absolute_path.rindex('.')] + '.rle'
            os.path.getsize(compressed_file)
            file_size_after = file_size(compressed_file)
            f.write('|' + file + '|' + file_size_before + '|' + file_size_after + '|\n')
            os.remove(compressed_file)
