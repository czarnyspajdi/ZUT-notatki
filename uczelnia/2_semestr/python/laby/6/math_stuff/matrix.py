class matrix:
    def __init__(self, mat: list[list[int]] = None) -> None:
        self.matrix = [] if mat is None else mat


def add(m1: matrix, m2: matrix) -> None:
    for i in range(len(m1.matrix)):
        for j in range(len(m1.matrix[0])):
            m1.matrix[i][j] += m2.matrix[i][j]


def add_constant(m1: matrix, constant: int) -> None:
    for i in range(len(m1.matrix)):
        for j in range(len(m1.matrix[0])):
            m1.matrix[i][j] += constant


def multiplication(A: matrix, B: matrix) -> matrix:
    rows_A = len(A.matrix)
    cols_B = len(B.matrix[0]) if B.matrix else 0

    C_mat = [[0 for _ in range(cols_B)] for _ in range(rows_A)]
    C: matrix = matrix(C_mat)

    for i in range(len(A.matrix)):
        for j in range(len(B.matrix[0])):
            for k in range(len(B.matrix)):
                C.matrix[i][j] += A.matrix[i][k] * B.matrix[k][j]
    return C


def multiplication_scalar(A: matrix, scalar: int) -> None:
    for i in range(len(A.matrix)):
        for j in range(len(A.matrix[0])):
            A.matrix[i][j] *= scalar


def multiplication_hadamar(A: matrix, B: matrix) -> matrix:
    rows = len(A.matrix)
    cols = len(A.matrix[0]) if rows > 0 else 0

    C_mat = [[0 for _ in range(cols)] for _ in range(rows)]
    C: matrix = matrix(C_mat)

    for i in range(rows):
        for j in range(cols):
            C.matrix[i][j] = A.matrix[i][j] * B.matrix[i][j]

    return C


def multiplication_kronecker(A: matrix, B: matrix) -> matrix:
    rows_A = len(A.matrix)
    cols_A = len(A.matrix[0]) if rows_A > 0 else 0

    rows_B = len(B.matrix)
    cols_B = len(B.matrix[0]) if rows_B > 0 else 0

    rows_C = rows_A * rows_B
    cols_C = cols_A * cols_B

    C_mat = [[0 for _ in range(cols_C)] for _ in range(rows_C)]
    C: matrix = matrix(C_mat)

    for i_a in range(rows_A):
        for j_a in range(cols_A):
            for i_b in range(rows_B):
                for j_b in range(cols_B):
                    row_c = i_a * rows_B + i_b
                    col_c = j_a * cols_B + j_b

                    C.matrix[row_c][col_c] = A.matrix[i_a][j_a] * B.matrix[i_b][j_b]

    return C
