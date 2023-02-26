# 读入三个整数 X,Y,Z

x, y, z = input("请输入三个整数，用空格隔开：").split()

# 排序
if x >= y and y >= z:
    print(x, y, z)
elif x >= z and z >= y:
    print(x, z, y)
elif y >= x and x >= z:
    print(y, x, z)
elif y >= z and z >= x:
    print(y, z, x)
elif z >= x and x >= y:
    print(z, x, y)
else:
    print(z, y, x)
