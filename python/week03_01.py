import os


class FileReader:
    def __init__(self, filename):
        self.filename = filename

    def read(self):
        result = ''

        if not os.path.isfile(self.filename):
            return ''

        with open(self.filename, 'r') as f:
            result = f.read()

        return result
