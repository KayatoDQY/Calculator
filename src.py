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
        substring = '#2'
        newstring = '**0.5'
        expression = expression.replace(substring, newstring)
        substring = '^2'
        newstring = '**2'
        expression = expression.replace(substring, newstring)
        substring = 'ln'
        newstring = 'math.log'
        expression = expression.replace(substring, newstring)
        substring = 'e^'
        newstring = 'math.exp'
        expression = expression.replace(substring, newstring)
        expression=process_factorial(expression)
        #print(expression)
        substring = '!'
        newstring = 'math.factorial('
        expression = expression.replace(substring, newstring)
        
        result = eval(expression)
        return  str(result)

    except:
        return "Expression Error"

def process_factorial(expr):
    if '!' in expr:
        if len(expr) > 1 and expr[-1] == '!':  
            i = len(expr) - 2  
            while i >= 0 and expr[i].isdigit():  
                i -= 1
            if expr[i] == '!':  
                new_expr = '!' + expr[0:-1]+')'
                return new_expr
        raise ValueError("Invalid expression: " + expr)
    else:
        return expr