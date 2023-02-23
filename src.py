import math

     
def Calculate(expression):
    try:
        substring = 'sin'
        newstring = 'math.sin'
        expression = expression.replace(substring, newstring)
        substring = 'cos'
        newstring = 'math.cos'
        expression = expression.replace(substring, newstring)
        substring = 'tan'
        newstring = 'math.tan'
        expression = expression.replace(substring, newstring)
        substring = 'pi'
        newstring = 'math.pi'
        expression = expression.replace(substring, newstring)
        print(expression)

        result = eval(expression)
        return  str(result)
    except:
        return "Expression Error"

print(Calculate("sin(pi)+sin(1.5*pi)"))