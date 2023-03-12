class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        backtrack(board, 0, 0)


def backtrack(board, i, j) -> bool:
    next_i, next_j = get_next_coords(i, j)

    if i == 9 and j == 9:
        return True

    if board[i][j] != '.':
        return backtrack(board, next_i, next_j)

    for num in get_possible_nums(board, i, j):
        board[i][j] = num

        if backtrack(board, next_i, next_j):
            return True

        board[i][j] = '.'

    return False


def get_next_coords(i, j) -> List[int]:
    if i == 8 and j == 8:
        return [9, 9]

    if j == 8:
        return [i + 1, 0]

    return [i, j + 1]


def get_possible_nums(board, i, j) -> List[int]:
    possible_nums = {'1', '2', '3', '4', '5', '6', '7', '8', '9'}

    # search rows
    for idx in range(9):
        num = board[idx][j]
        if num in possible_nums:
            possible_nums.remove(num)

    # search columns
    for jdx in range(9):
        num = board[i][jdx]
        if num in possible_nums:
            possible_nums.remove(num)

    # search box
    box_row_start = (i // 3) * 3
    box_col_start = (j // 3) * 3
    for idx in range(box_row_start, box_row_start + 3):
        for jdx in range(box_col_start, box_col_start + 3):
            num = board[idx][jdx]
            if num in possible_nums:
                possible_nums.remove(num)

    return list(possible_nums)

