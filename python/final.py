# -*- coding: utf-8 -*-

import asyncio
import re
from collections import defaultdict, OrderedDict


metrics = defaultdict(OrderedDict)

AVAILABLE_COMMANDS = ['put', 'get']
PUT_PATTERN = re.compile('put (\w+) ([-+]?\d*\.\d+|\d+) (\d+)')
GET_PATTERN = re.compile('get (\S+)')


def parse_get_command(raw_get_command):
    key = GET_PATTERN.findall(raw_get_command)[0]
    return key


def parse_put_command(raw_put_command):
    key, value, time = PUT_PATTERN.findall(raw_put_command)[0]
    return key, float(value), int(time)


def dump_metric(key):
    resp = ''
    if key in metrics.keys():
        resp += '\n'.join(['{} {} {}'.format(key, value, timestamp)
                           for timestamp, value in metrics[key].items()])
    return resp


def process_data(data):
    command = data[:3]
    resp = 'error\nwrong command\n\n'

    if command == 'get':
        key = parse_get_command(data)
        resp = 'ok\n'
        if key == '*':
            for key in metrics.keys():
                resp += dump_metric(key)
                resp += '\n'
        else:
            resp += dump_metric(key)
            resp += '\n'

        resp += '\n'

    if command == 'put':
        key, value, time = parse_put_command(data)
        metrics[key][time] = value
        resp = 'ok\n\n'

    return resp


class ClientServerProtocol(asyncio.Protocol):
    def connection_made(self, transport):
        self.transport = transport

    def data_received(self, data):
        resp = process_data(data.decode())
        self.transport.write(resp.encode())


def run_server(host='127.0.0.1', port=8181):
    loop = asyncio.get_event_loop()
    coro = loop.create_server(
        ClientServerProtocol,
        host, port
    )

    server = loop.run_until_complete(coro)

    try:
        loop.run_forever()
    except KeyboardInterrupt:
        pass

    server.close()
    loop.run_until_complete(server.wait_closed())
    loop.close()
