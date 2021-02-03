import pandas as pd
import numpy as np
import matplotlib
import matplotlib.pyplot as plt

AH = pd.read_csv('./bank.csv', sep=";", header=0, index_col=False)

AH.head()
#matplotlib.style.use('ggplot')

AH["age"].hist()