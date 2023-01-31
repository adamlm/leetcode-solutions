class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        rotate(matrix, 0, len(matrix))


def rotate(matrix, l, r):
    if l >= r:
        return

    for j in range(r - l - 1):
        new_val = matrix[l][l + j]

        # right
        tmp = matrix[l + j][r - 1]
        matrix[l + j][r - 1] = new_val
        new_val = tmp

        # bottom
        tmp = matrix[r - 1][r - 1 - j]
        matrix[r - 1][r - 1 - j] = new_val
        new_val = tmp

        # left
        tmp = matrix[r - 1 - j][l]
        matrix[r - 1 - j][l] = new_val
        new_val = tmp

        # top
        matrix[l][l + j] = new_val

    rotate(matrix, l + 1, r - 1)

