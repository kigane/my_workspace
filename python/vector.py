from functools import reduce
import math

def vector_add(v, w):
    return [v_i + w_i for v_i, w_i in zip(v, w)]

def vector_substract(v, w):
    return [v_i - w_i for v_i, w_i in zip(v, w)]

def vector_sum(vectors):
    return reduce(vector_add, vectors)

def scalar_multiply(c, v):
    return [c * v_i for v_i in v]

def vector_mean(vectors):
    n = len(vectors)
    return scalar_multiply(1/n, vector_sum(vectors))

def dot(v, w):
    return sum(v_i * w_i for v_i, w_i in zip(v, w))

def sum_of_squares(v):
    return dot(v, v)

def magnitude(v):
    return math.sqrt(sum_of_squares(v))

def distance(v, w):
    return magnitude(vector_substract(v, w))

def shape(A):
    num_rows = len(A)
    num_cols = len(A[0]) if A else 0
    return num_rows, num_cols

def get_row(A, i):
    return A[i]

def get_col(A, j):
    return [A_i[j] for A_i in A]

