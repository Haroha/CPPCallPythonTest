def Hello():
    print("Hello Python")
 
def Add(a, b):
    return a + b

def PrintPI():
    import numpy as np
    print(np.pi)

def ShowColorChecker():
    from colour import plotting
    import matplotlib.pyplot as plt

    plotting.plot_single_colour_checker(text_kwargs={"visible": False})