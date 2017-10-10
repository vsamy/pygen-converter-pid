import numpy
from TestFunctions import *
import unittest

class ConversionCheck(unittest.TestCase):
    def test_Matrices(self):
        structure = RandomDynamicSizeMatrix(5, 8)
        mat = structure.get()
        self.assertTrue(structure.check(mat))

        structure = RandomFixedSizeMatrix()
        mat = structure.get()
        self.assertTrue(structure.check(mat))

        structure = RandomhalfDynamicSizeMatrix(8)
        mat = structure.get()
        self.assertTrue(structure.check(mat))

    def test_vectors(self):
        structure = RandomDynamicSizeVector(8)
        vec = structure.get()
        self.assertTrue(structure.check(vec))

        structure = RandomFixedSizeVector()
        vec = structure.get()
        self.assertTrue(structure.check(vec))

    def test_row_vectors(self):
        structure = RandomDynamicSizeRowVector(8)
        vec = structure.get()
        self.assertTrue(structure.check(vec))

        structure = RandomFixedSizeRowVector()
        vec = structure.get()
        self.assertTrue(structure.check(vec))

    def test_list_Matrices(self):
        structure = RandomDynamicSizeMatrix(5, 8)
        mat = structure.get()
        self.assertTrue(structure.check(mat.tolist()))

    def test_list_vectors(self):
        structure = RandomDynamicSizeVector(8)
        vec = structure.get()
        self.assertTrue(structure.check(vec.tolist()))

    def test_list_row_vectors(self):
        structure = RandomDynamicSizeRowVector(8)
        vec = structure.get()
        self.assertTrue(structure.check(vec.tolist()))

if __name__ == '__main__':
    unittest.main()
