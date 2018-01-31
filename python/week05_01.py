# -*- coding: utf-8 -*-
import time
import socket
from collections import defaultdict


class ClientError(Exception):
    pass


class Client:
    def __init__(self, host: str, port: int, timeout=None):
        self._host = host
        self._port = port
        self._timeout = timeout

    def _send(self, data):
        sock = socket.create_connection(
            (self._host, self._port), self._timeout)
        try:
            sock.sendall(data.encode('utf-8'))
            resp = sock.recv(1024)
            return resp
        except BaseException as err:
            raise ClientError
        sock.close()

    def put(self, key: str, value: float, timestamp=None):
        if timestamp is None:
            timestamp = str(int(time.time()))

        value = float(value)
        data = self._send(f'put {key} {value} {timestamp}\n')
        if data != b"ok\n\n":
            raise ClientError

    def get(self, key: str='*'):
        result = defaultdict(list)
        data = self._send(f'get {key}\n')
        if data[:3] != b'ok\n':
            raise ClientError
        data = data[3:-2].split(b'\n')

        if data and data[0]:
            for row in data:
                key, value, tmstmp = row.split()
                result[key.decode("utf-8")].append((int(tmstmp), float(value)))

        result = dict(result)
        return result
