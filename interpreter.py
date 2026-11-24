data=input("expression: ")
x,y,z= data.split(" ")
x=int(x)
z=int(z)
if y=="+":
    result =x+z
elif y=="-":
    result= x-z
elif y=="*":
    result=x*z
elif y=="/":
    result =x/z
print(f"{result:.1f}")
