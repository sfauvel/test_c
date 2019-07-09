import unittest
import cffi
import importlib

def load(filename):
    source = open("./src/" + filename + ".c").read()
    includes = open("./include/" + filename + ".h").read()

    ffibuilder = cffi.FFI()
    print(includes)

    ffibuilder.cdef(includes)
    #ffibuilder.set_source(filename + '_', source)
    #ffibuilder.compile()

    module = importlib.import_module(filename + '_')
    return module.lib


class TestStringMethods(unittest.TestCase):

    def test_square(self):
        module = load("myapp")
        print("Hello")

    def test_upper(self):
        self.assertEqual('foo'.upper(), 'FOO')

    def test_isupper(self):
        self.assertTrue('FOO'.isupper())
        self.assertFalse('Foo'.isupper())

    def test_split(self):
        s = 'hello world'
        self.assertEqual(s.split(), ['hello', 'world'])
        # check that s.split fails when the separator is not a string
        with self.assertRaises(TypeError):
            s.split(2)

if __name__ == '__main__':
    unittest.main()
