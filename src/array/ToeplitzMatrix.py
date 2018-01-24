#!/bin/env/python

# Solution for : https://leetcode.com/problems/toeplitz-matrix/description/

class Solution(object):
    def validUpperDiag(self, matrix, diag, rows, cols):
        elem = matrix[0][diag]
        for i in range(rows):
            if i + diag < cols:
                if matrix[i][i+diag] != elem:
                    return False
        return True

    def validLowerDiag(self, matrix, diag, rows, cols):
        elem = matrix[diag][0]
        for i in range(cols):
            if i + diag < rows:
                if matrix[i+diag][i] != elem:
                    return False
        return True

    def isToeplitzMatrix(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: bool
        """
        if not matrix:
            return False
        rows = len(matrix)
        cols = len(matrix[0])
        for i in range(cols):
            if not self.validUpperDiag(matrix, i, rows, cols):
                return False

        for i in range(1,rows):
            if not self.validLowerDiag(matrix, i, rows, cols):
                return False
        return True
