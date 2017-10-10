import numpy
from pyTestFunctions import *
import unittest

class ConversionCheck(unittest.TestCase):
    def test_Matrices(self):
        print "Launch Dynamic size matrix"
        structure = RandomDynamicSizeMatrix(5, 8)
        mat = structure.get()
        self.assertTrue(structure.check(mat))

        print "Launch Fixed size matrix"
        structure = RandomFixedSizeMatrix()
        mat = structure.get()
        self.assertTrue(structure.check(mat))

        print "Launch Half-dynamic size matrix"
        structure = RandomHalfDynamicSizeMatrix(8)
        mat = structure.get()
        self.assertTrue(structure.check(mat))

    def test_vectors(self):
        print "Launch Dynamic size vector"
        structure = RandomDynamicSizeVector(8)
        vec = structure.get()
        self.assertTrue(structure.check(vec))

        print "Launch Fixed size vector"
        structure = RandomFixedSizeVector()
        vec = structure.get()
        self.assertTrue(structure.check(vec))

    def test_row_vectors(self):
        print "Launch Dynamic size row vector"
        structure = RandomDynamicSizeRowVector(8)
        vec = structure.get()
        self.assertTrue(structure.check(vec))

        print "Launch Fixed size row vector"
        structure = RandomFixedSizeRowVector()
        vec = structure.get()
        self.assertTrue(structure.check(vec))

    def test_list_Matrices(self):
        print "Launch Dynamic size matrix list"
        structure = RandomDynamicSizeMatrix(5, 8)
        mat = structure.get()
        self.assertTrue(structure.check(mat.tolist()))

    def test_list_vectors(self):
        print "Launch Dynamic size vector list"
        structure = RandomDynamicSizeVector(8)
        vec = structure.get()
        print vec
        print vec.tolist()
        print
        self.assertTrue(structure.check(vec.tolist()))

    def test_list_row_vectors(self):
        print "Launch Dynamic size row vector list"
        structure = RandomDynamicSizeRowVector(8)
        vec = structure.get()
        print vec
        print vec.tolist()
        print
        self.assertTrue(structure.check(vec.tolist()))

if __name__ == '__main__':
    unittest.main()
