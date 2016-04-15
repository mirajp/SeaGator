import numpy as np

def mapping(points,order):
    x = np.array([p[0] for p in points])
    y = np.array([p[1] for p in points])

    polynomial = np.polyfit(x,y,order)

    return polynomial

if __name__ == "__main__":
    tmp = [[0,1],[1,2]]
    print mapping(tmp,2)
    
