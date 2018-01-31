# -*- coding: utf-8 -*-
import os
import csv


class BaseCar(object):
    car_type = None

    def __init__(self, brand, photo_file_name, carrying):
        self.brand = brand
        self.photo_file_name = photo_file_name
        self.carrying = float(carrying)

    def get_photo_file_ext(self):
        return os.path.splitext(self.photo_file_name)[1]


class Car(BaseCar):
    car_type = 'car'

    def __init__(self, brand, photo_file_name, carrying,
                 passenger_seats_count):
        super().__init__(brand, photo_file_name, carrying)

        self.passenger_seats_count = int(passenger_seats_count)


class Truck(BaseCar):
    car_type = 'truck'

    def __init__(self, brand, photo_file_name, carrying, body_whl=None):
        super().__init__(brand, photo_file_name, carrying)
        if body_whl:
            self.body_length, self.body_width, self.body_height = map(float, body_whl.split(
                'x'))
        else:
            self.body_length = self.body_width =self.body_height = 0

    def get_body_volume(self):
        return self.body_length * self.body_width * self.body_height


class SpecMachine(BaseCar):
    car_type = 'spec_machine'

    def __init__(self, brand, photo_file_name, carrying, extra):
        super().__init__(brand, photo_file_name, carrying)
        self.extra = extra


def parse_car_row(car_type=None, brand=None,
                  passenger_seats_count=None, photo_file_name=None,
                  body_whl=None, carrying=None, extra=None):

    if not all([car_type, brand, photo_file_name, carrying]):
        return None

    if car_type == 'car' and passenger_seats_count:
        return Car(
            brand=brand,
            photo_file_name=photo_file_name,
            carrying=carrying,
            passenger_seats_count=passenger_seats_count)

    if car_type == 'truck':
        return Truck(
            brand=brand,
            photo_file_name=photo_file_name,
            carrying=carrying,
            body_whl=body_whl)

    if car_type == 'spec_machine' and extra:
        return SpecMachine(
            brand=brand,
            photo_file_name=photo_file_name,
            carrying=carrying,
            extra=extra)


def get_car_list(csv_filename):
    car_list = []
    with open(csv_filename) as csv_fd:
        reader = csv.reader(csv_fd, delimiter=';')
        next(reader)
        for row in reader:
            car_obj = parse_car_row(*row)
            if car_obj:
                car_list.append(car_obj)
    return car_list