from functools import reduce

def hamming_syndrome(bits):
    return reduce(
        lambda x, y: x ^ y, 
        [i for (i, b) in enumerate(bits) if b]
    )