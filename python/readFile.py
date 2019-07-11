import sys


print "Globals inside function : id %s and %s " % (id(globals()), globals())

print "Locals inside function : id %s and %s " % (id(locals()), locals())

with open('./resources/file_for_test.txt') as lines:
    for line in lines:
        print("PYTHON: " + sys.argv[1])

45
