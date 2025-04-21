import math
import sys

def rotate(x, y, z, a, b, c, theta):
    norm = math.sqrt(a*a + b*b + c*c)
    if norm == 0:
        return (x, y, z)
    kx = a / norm
    ky = b / norm
    kz = c / norm
    
    # dot product
    dot = kx * x + ky * y + kz * z
    # cross product
    cross_x = ky * z - kz * y
    cross_y = kz * x - kx * z
    cross_z = kx * y - ky * x
    
    cos = math.cos(theta)
    sin = math.sin(theta)
    
    # rodriguez
    x_res = x * cos + cross_x * sin + kx * dot * (1 - cos)
    y_res = y * cos + cross_y * sin + ky * dot * (1 - cos)
    z_res = z * cos + cross_z * sin + kz * dot * (1 - cos)
    
    return (x_res, y_res, z_res)

t = int(sys.stdin.readline())
for _ in range(t):
    line = sys.stdin.readline().split()
    parts = list(map(float, line))
    x, y, z, a, b, c, theta = parts
    res = rotate(x, y, z, a, b, c, theta)
    print("{0:.6f} {1:.6f} {2:.6f}".format(res[0], res[1], res[2]))