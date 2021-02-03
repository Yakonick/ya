import numpy as np;
import pandas as pd;
import matplotlib;
import  matplotlib.pyplot as plt;
import datetime as dp;

ProductList = pd.read_csv("PRODUCT_LIST.CSV", sep =";", encoding='cp1251', header = 0, index_col = False)
SaleList = pd.read_csv("SALE_LIST.csv", sep = ";", encoding='cp1251', header = 0, index_col = False)

MergedTable = ProductList.merge(SaleList, left_on='Product_code', right_on="product_code")

ProductCount = MergedTable[['Product_name', 'product_count']].groupby('Product_name', as_index = False).sum('product_count')
ProductCountbyRest = MergedTable[['Product_name', 'product_count', 'rest_code']].groupby(['Product_name', 'rest_code'], as_index = False).sum('product_count')
ProductCount = ProductCount.sort_values('product_count', ascending=False)
ProductCountTop5 = ProductCount[['Product_name', 'product_count']].head(5)
ProductCountbyRestTop5 = ProductCountbyRest[ProductCountbyRest['Product_name'].isin(ProductCountTop5['Product_name'])]
RestSales = MergedTable[['rest_code', 'product_count']].groupby('rest_code', as_index = False).sum('product_count')
DatesCount = MergedTable[MergedTable['rest_code']=='Мечта'].groupby('date', as_index=False)['date'].agg(['count']).reset_index()
DatesCount = DatesCount.sort_values('count', ascending=False)
DatesCountTop5 = DatesCount.head(5)


x = np.arange(len(ProductCountbyRestTop5)/2)  # the label locations
width = 0.35
fig, ax1 = plt.subplots()
rects1 = ax1.bar(x - width/2, ProductCountbyRestTop5[ProductCountbyRestTop5['rest_code'] == 'Мечта']['product_count'], width, label='Мечта')
rects2 = ax1.bar(x + width/2, ProductCountbyRestTop5[ProductCountbyRestTop5['rest_code'] == 'Озерный']['product_count'], width, label='Озерный')
ax1.set_ylabel('Product count')
ax1.set_title('Продажи 5 наиболее популярных товаров в ресторанах "Мечта" и "Озерный"')
ax1.set_xticks(x)
ax1.set_xticklabels(ProductCountbyRestTop5[ProductCountbyRestTop5['rest_code'] == 'Мечта']['Product_name'], fontsize = 5)
ax1.legend()
ax1.get_figure().suptitle(' ')
plt.show()

DatesCountTop5.plot.bar(x='date', y = 'count', color = 'blue', legend = False)
plt.title('Наиболее загруженные даты в ресторане "Мечта"')
plt.xticks(rotation=0)
plt.show()

fig1, ax1 = plt.subplots()
plt.title('Продажи 5 самых популярных товаров в ресторанах Мечта и Озерный')
ax1.pie(ProductCountTop5['product_count'], labels = ProductCountTop5['Product_name'], autopct='%1.2f%%')
ax1.axis('equal')
plt.show()

ax2 = MergedTable[MergedTable['Product_name'].isin(ProductCount['Product_name'].head(5))].boxplot(column = 'product_count', by = 'Product_name', vert = False)
plt.title('Распределение количества заказов наиболее популярных товаров')
plt.show()

RestSales.plot.bar(x='rest_code', y = 'product_count', color = 'green')
plt.title('Заказы в ресторанах "Мечта" и "Озерный"')
plt.xticks(rotation=0)
plt.show()


