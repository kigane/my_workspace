import math
import random
from collections import Counter

def normal_pdf(x, mu=0, sigma=1):
    sqrt_two_pi = math.sqrt(2 * math.pi)
    return math.exp(-(x-mu)**2 / math.sqrt(2)/sigma ** 2) / (sqrt_two_pi * sigma)


def normal_cdf(x, mu=0.0, sigma=1.0):
    return (1.0 + math.erf((x - mu) / math.sqrt(2) / sigma)) / 2.0


def inverse_normal_cdf(p, mu = 0, sigma = 1, tolerance = 0.00001):
    """
        二分法对 normal_cdf 取逆
    """
    # 标准化
    if mu != 0 or sigma != 1:
        return mu + sigma * inverse_normal_cdf(p, tolerance=tolerance)
    
    low_z, low_p = -10.0, 0 # normal_cdf(-10) 接近 0
    hi_z, hi_p = 10.0, 1    # normal_cdf(10) 接近 1
    while hi_z - low_z > tolerance:
        mid_z = (low_z + hi_z) / 2
        mid_p = normal_cdf(mid_z)
        if mid_p < p:
            low_z, low_p = mid_z, mid_p
        elif mid_p > p:
            hi_z, hi_p = mid_z, mid_p
        else:
            break
    return mid_z


def bernoulli_trial(p):
    return 1 if random.random() < p else 0

def binomial(n, p):
    return sum(bernoulli_trial(p) for _ in range(n))
