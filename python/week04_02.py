# -*- coding: utf-8 -*-


class Value:
    def __init__(self, value=0):
        self.value = value

    def __get__(self, obj, obj_type):
        return self.value * (1 - obj.commission)

    def __set__(self, obj, value):
        self.value = value
