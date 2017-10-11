import numpy
from pyTestFunctions import *
import unittest

class ConversionCheckInt(unittest.TestCase):
    def test_Matrices(self):
        print "Launch Dynamic size matrix"
        structure = RandomDynamicSizeMatrixInt(5, 8)
        mat = structure.get()
        self.assertTrue(structure.check(mat))

        print "Launch Fixed size matrix"
        structure = RandomFixedSizeMatrixInt()
        mat = structure.get()
        self.assertTrue(structure.check(mat))

        print "Launch Half-dynamic size matrix"
        structure = RandomHalfDynamicSizeMatrixInt(8)
        mat = structure.get()
        self.assertTrue(structure.check(mat))

    def test_vectors(self):
        print "Launch Dynamic size vector"
        structure = RandomDynamicSizeVectorInt(8)
        vec = structure.get()
        self.assertTrue(structure.check(vec))

        print "Launch Fixed size vector"
        structure = RandomFixedSizeVectorInt()
        vec = structure.get()
        self.assertTrue(structure.check(vec))

    def test_row_vectors(self):
        print "Launch Dynamic size row vector"
        structure = RandomDynamicSizeRowVectorInt(8)
        vec = structure.get()
        self.assertTrue(structure.check(vec))

        print "Launch Fixed size row vector"
        structure = RandomFixedSizeRowVectorInt()
        vec = structure.get()
        self.assertTrue(structure.check(vec))

    def test_list_Matrices(self):
        print "Launch Dynamic size matrix list"
        structure = RandomDynamicSizeMatrixInt(5, 8)
        mat = structure.get()
        self.assertTrue(structure.check(mat.tolist()))

    def test_list_vectors(self):
        print "Launch Dynamic size vector list"
        structure = RandomDynamicSizeVectorInt(8)
        vec = structure.get()
        self.assertTrue(structure.check(vec.tolist()))

    def test_list_row_vectors(self):
        print "Launch Dynamic size row vector list"
        structure = RandomDynamicSizeRowVectorInt(8)
        vec = structure.get()
        self.assertTrue(structure.check(vec.tolist()))

class ConversionCheckFloat(unittest.TestCase):
    def test_Matrices(self):
        print "Launch Dynamic size matrix"
        structure = RandomDynamicSizeMatrixFloat(5, 8)
        mat = structure.get()
        self.assertTrue(structure.check(mat))

        print "Launch Fixed size matrix"
        structure = RandomFixedSizeMatrixFloat()
        mat = structure.get()
        self.assertTrue(structure.check(mat))

        print "Launch Half-dynamic size matrix"
        structure = RandomHalfDynamicSizeMatrixFloat(8)
        mat = structure.get()
        self.assertTrue(structure.check(mat))

    def test_vectors(self):
        print "Launch Dynamic size vector"
        structure = RandomDynamicSizeVectorFloat(8)
        vec = structure.get()
        self.assertTrue(structure.check(vec))

        print "Launch Fixed size vector"
        structure = RandomFixedSizeVectorFloat()
        vec = structure.get()
        self.assertTrue(structure.check(vec))

    def test_row_vectors(self):
        print "Launch Dynamic size row vector"
        structure = RandomDynamicSizeRowVectorFloat(8)
        vec = structure.get()
        self.assertTrue(structure.check(vec))

        print "Launch Fixed size row vector"
        structure = RandomFixedSizeRowVectorFloat()
        vec = structure.get()
        self.assertTrue(structure.check(vec))

    def test_list_Matrices(self):
        print "Launch Dynamic size matrix list"
        structure = RandomDynamicSizeMatrixFloat(5, 8)
        mat = structure.get()
        self.assertTrue(structure.check(mat.tolist()))

    def test_list_vectors(self):
        print "Launch Dynamic size vector list"
        structure = RandomDynamicSizeVectorFloat(8)
        vec = structure.get()
        self.assertTrue(structure.check(vec.tolist()))

    def test_list_row_vectors(self):
        print "Launch Dynamic size row vector list"
        structure = RandomDynamicSizeRowVectorFloat(8)
        vec = structure.get()
        self.assertTrue(structure.check(vec.tolist()))

class ConversionCheckDouble(unittest.TestCase):
    def test_Matrices(self):
        print "Launch Dynamic size matrix"
        structure = RandomDynamicSizeMatrixDouble(5, 8)
        mat = structure.get()
        self.assertTrue(structure.check(mat))

        print "Launch Fixed size matrix"
        structure = RandomFixedSizeMatrixDouble()
        mat = structure.get()
        self.assertTrue(structure.check(mat))

        print "Launch Half-dynamic size matrix"
        structure = RandomHalfDynamicSizeMatrixDouble(8)
        mat = structure.get()
        self.assertTrue(structure.check(mat))

    def test_vectors(self):
        print "Launch Dynamic size vector"
        structure = RandomDynamicSizeVectorDouble(8)
        vec = structure.get()
        self.assertTrue(structure.check(vec))

        print "Launch Fixed size vector"
        structure = RandomFixedSizeVectorDouble()
        vec = structure.get()
        self.assertTrue(structure.check(vec))

    def test_row_vectors(self):
        print "Launch Dynamic size row vector"
        structure = RandomDynamicSizeRowVectorDouble(8)
        vec = structure.get()
        self.assertTrue(structure.check(vec))

        print "Launch Fixed size row vector"
        structure = RandomFixedSizeRowVectorDouble()
        vec = structure.get()
        self.assertTrue(structure.check(vec))

    def test_list_Matrices(self):
        print "Launch Dynamic size matrix list"
        structure = RandomDynamicSizeMatrixDouble(5, 8)
        mat = structure.get()
        self.assertTrue(structure.check(mat.tolist()))

    def test_list_vectors(self):
        print "Launch Dynamic size vector list"
        structure = RandomDynamicSizeVectorDouble(8)
        vec = structure.get()
        self.assertTrue(structure.check(vec.tolist()))

    def test_list_row_vectors(self):
        print "Launch Dynamic size row vector list"
        structure = RandomDynamicSizeRowVectorDouble(8)
        vec = structure.get()
        self.assertTrue(structure.check(vec.tolist()))

class ConversionCheckCFloat(unittest.TestCase):
    def test_Matrices(self):
        print "Launch Dynamic size matrix"
        structure = RandomDynamicSizeMatrixCFloat(5, 8)
        mat = structure.get()
        self.assertTrue(structure.check(mat))

        print "Launch Fixed size matrix"
        structure = RandomFixedSizeMatrixCFloat()
        mat = structure.get()
        self.assertTrue(structure.check(mat))

        print "Launch Half-dynamic size matrix"
        structure = RandomHalfDynamicSizeMatrixCFloat(8)
        mat = structure.get()
        self.assertTrue(structure.check(mat))

    def test_vectors(self):
        print "Launch Dynamic size vector"
        structure = RandomDynamicSizeVectorCFloat(8)
        vec = structure.get()
        self.assertTrue(structure.check(vec))

        print "Launch Fixed size vector"
        structure = RandomFixedSizeVectorCFloat()
        vec = structure.get()
        self.assertTrue(structure.check(vec))

    def test_row_vectors(self):
        print "Launch Dynamic size row vector"
        structure = RandomDynamicSizeRowVectorCFloat(8)
        vec = structure.get()
        self.assertTrue(structure.check(vec))

        print "Launch Fixed size row vector"
        structure = RandomFixedSizeRowVectorCFloat()
        vec = structure.get()
        self.assertTrue(structure.check(vec))

    def test_list_Matrices(self):
        print "Launch Dynamic size matrix list"
        structure = RandomDynamicSizeMatrixCFloat(5, 8)
        mat = structure.get()
        self.assertTrue(structure.check(mat.tolist()))

    def test_list_vectors(self):
        print "Launch Dynamic size vector list"
        structure = RandomDynamicSizeVectorCFloat(8)
        vec = structure.get()
        self.assertTrue(structure.check(vec.tolist()))

    def test_list_row_vectors(self):
        print "Launch Dynamic size row vector list"
        structure = RandomDynamicSizeRowVectorCFloat(8)
        vec = structure.get()
        self.assertTrue(structure.check(vec.tolist()))

class ConversionCheckCDouble(unittest.TestCase):
    def test_Matrices(self):
        print "Launch Dynamic size matrix"
        structure = RandomDynamicSizeMatrixCDouble(5, 8)
        mat = structure.get()
        self.assertTrue(structure.check(mat))

        print "Launch Fixed size matrix"
        structure = RandomFixedSizeMatrixCDouble()
        mat = structure.get()
        self.assertTrue(structure.check(mat))

        print "Launch Half-dynamic size matrix"
        structure = RandomHalfDynamicSizeMatrixCDouble(8)
        mat = structure.get()
        self.assertTrue(structure.check(mat))

    def test_vectors(self):
        print "Launch Dynamic size vector"
        structure = RandomDynamicSizeVectorCDouble(8)
        vec = structure.get()
        self.assertTrue(structure.check(vec))

        print "Launch Fixed size vector"
        structure = RandomFixedSizeVectorCDouble()
        vec = structure.get()
        self.assertTrue(structure.check(vec))

    def test_row_vectors(self):
        print "Launch Dynamic size row vector"
        structure = RandomDynamicSizeRowVectorCDouble(8)
        vec = structure.get()
        self.assertTrue(structure.check(vec))

        print "Launch Fixed size row vector"
        structure = RandomFixedSizeRowVectorCDouble()
        vec = structure.get()
        self.assertTrue(structure.check(vec))

    def test_list_Matrices(self):
        print "Launch Dynamic size matrix list"
        structure = RandomDynamicSizeMatrixCDouble(5, 8)
        mat = structure.get()
        self.assertTrue(structure.check(mat.tolist()))

    def test_list_vectors(self):
        print "Launch Dynamic size vector list"
        structure = RandomDynamicSizeVectorCDouble(8)
        vec = structure.get()
        self.assertTrue(structure.check(vec.tolist()))

    def test_list_row_vectors(self):
        print "Launch Dynamic size row vector list"
        structure = RandomDynamicSizeRowVectorCDouble(8)
        vec = structure.get()
        self.assertTrue(structure.check(vec.tolist()))

if __name__ == '__main__':
    unittest.main()
