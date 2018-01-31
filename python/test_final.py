# -*- coding: utf-8 -*-

import unittest
from collections import deque

# импорт модуля с решением
from week05_01 import Client, ClientError


class ServerSocketException(Exception):
    pass



class TestClient(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.client = Client("127.0.0.1", 8181, timeout=2)

    def test_1_client_put(self):
        metrics_for_put = [
            ("test", 0.5, 1),
            ("test", 2.0, 2),
            ("test", 0.4, 2),
            ("load", 301, 3),
        ]
        for metric, value, timestamp in metrics_for_put:
            try:
                self.client.put(metric, value, timestamp)
            except ServerSocketException as exp:
                message = exp.args[0]
                self.fail(f"Ошибка вызова client.put("
                          f"'{metric}', {value}, timestamp={timestamp})\n{message}")

    def test_2_client_get_key(self):
        try:
            rsp = self.client.get("test")
        except ServerSocketException as exp:
            message = exp.args[0]
            self.fail(f"Ошибка вызова client.get('test')\n{message}")

        metrics_fixture = {
            "test": [(1, .5), (2, .4)],
        }
        self.assertEqual(rsp, metrics_fixture)

    def test_3_client_get_all(self):
        try:
            rsp = self.client.get("*")
        except ServerSocketException as exp:
            message = exp.args[0]
            self.fail(f"Ошибка вызова client.get('*')\n{message}")

        metrics_fixture = {
            "test": [(1, .5), (2, .4)],
            "load": [(3, 301.0)]
        }
        self.assertEqual(rsp, metrics_fixture)

    def test_4_client_get_not_exists(self):
        try:
            rsp = self.client.get("key_not_exists")
        except ServerSocketException as exp:
            message = exp.args[0]
            self.fail(f"Ошибка вызова client.get('key_not_exists')\n{message}")

        self.assertEqual({}, rsp, "check rsp eq {}")

    def test_5_client_get_client_error(self):
        try:
            self.assertRaises(ClientError,
                              self.client.get, "get_client_error")
        except ServerSocketException as exp:
            message = exp.args[0]
            self.fail(f"Некорректно обработано сообщение сервера об ошибке: {message}")
