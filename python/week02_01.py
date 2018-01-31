import os
import tempfile
import json
import argparse
parser = argparse.ArgumentParser()
parser.add_argument('--key')
parser.add_argument('--val')
args = parser.parse_args()


storage_filename = os.path.join(tempfile.gettempdir(), 'storage.data')


def is_non_zero_file(fpath):
    return os.path.isfile(fpath) and os.path.getsize(fpath) > 0


if is_non_zero_file(storage_filename):
    with open(storage_filename, 'r') as f:
        storage = json.load(f)
else:
    storage = {}


if args.val:
    with open(storage_filename, 'w') as f:
        if storage.get(args.key):
            storage[args.key].append(args.val)
        else:
            storage[args.key] = [args.val]
        json.dump(storage, f)
else:
    if storage.get(args.key):
        print(', '.join(storage[args.key]))
    else:
        print('None')
