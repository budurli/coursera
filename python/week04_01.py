# -*- coding: utf-8 -*-
import os
import tempfile


class File:
    def __init__(self, filename):
        self.filename = filename
        if not os.path.isfile(self.filename):
            with open(self.filename, 'w'):
                pass

    def __str__(self):
        return self.filename

    def __iter__(self):
        with open(self.filename, 'r') as f:
            for i in f.readlines():
                yield i

    def __add__(self, obj):
        filename = '+'.join([
            os.path.split(self.filename)[-1],
            os.path.split(obj.filename)[-1]
        ])
        path = os.path.join(tempfile.gettempdir(), filename)

        new_f = File(path)

        for i in self:
            new_f.write(i)

        for i in obj:
            new_f.write(i)

        return new_f

    def write(self, _string):
        with open(self.filename, 'a') as f:
            f.write(_string)
